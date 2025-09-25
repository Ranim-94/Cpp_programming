# Understanding Stack vs Heap Memory in Shallow Copy

<u>Source code:</u> [main_heap_copy_vec.cpp](./main_heap_copy_vec.cpp)

## The Confusion Explained

When working with shallow copy in C++, it's important to understand the difference between:

- **Object addresses** (where the objects themselves are stored)
- **Pointer values** (what the pointers inside the objects point to)

## Code Example

```cpp
heap_vec2 v1{5, 10};     // Original object
heap_vec2 v2 {v1};       // Shallow copy (deault copy constructor in case of shallow copy)
```

<u>**!! Note!!**:</u>
`heap_vec2 v2 {v1}`:

- this statment will not invoke the normal constructor of `heap_vec2` class, but it will
the **copy constructor** which takes `v1` as argument, and create a new object `v2`

- So it is important to distinguish that when instantiating objects, which constructor will be called
  - `heap_vec2 v1{5, 10}` normal constructor
  - `heap_vec2 v2 {v1}`-> copy constructor which takes const object reference as argument

## Memory Layout Diagram

### Stack Memory (Different Addresses)
```
Stack:
┌─────────────────┐  Address: 0x7fff1234
│      v1         │  
│  ┌───────────┐  │
│  │ m_x  ────┼──┼─────┐
│  │ m_y  ────┼──┼───┐ │
│  └───────────┘  │   │ │
└─────────────────┘   │ │
                      │ │
┌─────────────────┐   │ │  Address: 0x7fff5678
│      v2         │   │ │
│  ┌───────────┐  │   │ │
│  │ m_x  ────┼──┼───┘ │  <- Same pointer value!
│  │ m_y  ────┼──┼─────┘  <- Same pointer value!
│  └───────────┘  │
└─────────────────┘
```

### Heap Memory (Same Location)
```
Heap:
┌─────────────────┐  Address: 0x12345678
│    float(5.0)   │  <- Both v1.m_x and v2.m_x point here
└─────────────────┘
┌─────────────────┐  Address: 0x12345680
│   float(10.0)   │  <- Both v1.m_y and v2.m_y point here
└─────────────────┘
```

## Key Points

### 1. Object Addresses Are Always Different
```cpp
std::cout << "&v1: " << &v1 << std::endl;  // e.g., 0x7fff1234
std::cout << "&v2: " << &v2 << std::endl;  // e.g., 0x7fff5678 (DIFFERENT!)
```
**Why?** `v1` and `v2` are separate objects on the stack, even with shallow copy.

### 2. Pointer Values Are The Same (Shallow Copy)
```cpp
std::cout << "v1.m_x points to: " << v1.get_x() << std::endl;  // e.g., 0x12345678
std::cout << "v2.m_x points to: " << v2.get_x() << std::endl;  // e.g., 0x12345678 (SAME!)
```
**Why?** Shallow copy copies the pointer values, not the data they point to.

### 3. Modifying One Affects The Other
```cpp
v2.set_x(15);  // Changes the value at 0x12345678

// Both objects see the change because they point to the same memory:
auto [x1, y1] = v1.get_coordinates();  // x1 = 15 (changed!)
auto [x2, y2] = v2.get_coordinates();  // x2 = 15 (changed!)
```

## Common Mistake: Using Stale Data

```cpp
// WRONG: Capturing values before modification
auto [x1, y1] = v1.get_coordinates();  // x1 = 5, y1 = 10

v2.set_x(15);  // This changes the shared heap memory

// Still printing old captured values!
std::cout << "v1: (" << x1 << "," << y1 << ")" << std::endl;  // Still shows 5,10!

// CORRECT: Get fresh values after modification
auto [x1_new, y1_new] = v1.get_coordinates();  // x1_new = 15!
std::cout << "v1: (" << x1_new << "," << y1_new << ")" << std::endl;  // Shows 15,10
```

## Visual Summary

```
Shallow Copy Behavior:
┌──────────┐    ┌──────────┐
│    v1    │    │    v2    │     <- Different stack addresses
│          │    │          │
│   m_x ───┼────┼──> [5.0] │     <- Same heap memory
│   m_y ───┼────┼──> [10.0]│     <- Same heap memory
└──────────┘    └──────────┘
```

## The Problem This Creates

1. **Double Free Error**: When both objects are destroyed, both destructors try to delete the same memory.
2. **Unexpected Behavior**: Modifying one object affects the other.
3. **Data Races**: In multi-threaded code, both objects access the same memory without synchronization.

## Solution: Deep Copy

Implement a proper copy constructor that allocates new memory:

```cpp
heap_vec2::heap_vec2(const heap_vec2& other):
    m_x(new float{*other.m_x}),     // Allocate NEW memory
    m_y(new float{*other.m_y}) {    // Copy the VALUES, not pointers
    std::cout << "Deep copy constructor called" << std::endl;
}
```

This ensures each object manages its own heap memory.
