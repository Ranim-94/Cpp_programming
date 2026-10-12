# Understanding Stack vs Heap Memory in Shallow Copy

<u>Source code:</u> [main_heap_copy_vec.cpp](./main_heap_copy_vec.cpp)

---

## Table of Contents

- [Understanding Stack vs Heap Memory in Shallow Copy](#understanding-stack-vs-heap-memory-in-shallow-copy)
  - [Table of Contents](#table-of-contents)
  - [The Confusion Explained](#the-confusion-explained)
  - [Code Example](#code-example)
  - [Memory Layout Diagram Using Shallow Copy](#memory-layout-diagram-using-shallow-copy)
    - [Stack Memory (Different Addresses)](#stack-memory-different-addresses)
    - [Heap memory for member variables](#heap-memory-for-member-variables)
  - [Key Points](#key-points)
    - [1. Object Addresses Are Always Different](#1-object-addresses-are-always-different)
    - [2. Pointer Values Are The Same (Shallow Copy)](#2-pointer-values-are-the-same-shallow-copy)
    - [3. Modifying One Affects The Other](#3-modifying-one-affects-the-other)
    - [Visual Summary](#visual-summary)
  - [The Problem with shallow copy](#the-problem-with-shallow-copy)
  - [Solution: Deep Copy](#solution-deep-copy)
  - [Bugs and Errors](#bugs-and-errors)
    - [`-Wreorder` Warning in Constructor Initializer List](#-wreorder-warning-in-constructor-initializer-list)

---

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

## Memory Layout Diagram Using Shallow Copy

### Stack Memory (Different Addresses)

When using statements such as `heap_vec2 v2 {v1}` with shallow copy, we have:

- `v2` and `v1` are objects allocated on the stack, each with different memory address
  - this is always true either with shallow or deep copy

<u>Stack:</u>

```
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

### Heap memory for member variables

- However, since we used shallow copy, the member variables `m_x` and `m_y` points to the same address
  - `v1.m_x` and `v2.m_x`  both have same address
  - `v1.m_y` and `v2.m_y`  both have same address

<u>Heap:</u>
```
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
heap_vec v1{"v_1",5,10}; // instantiating a vector v1

heap_vec v2 = v1; // instantiating a vector v2 using v1 and shallow copy

v2.set_x(15);  // Changes the value at 0x12345678

// Both objects see the change because they point to the same memory:
v2.log_vec_info();  // x2 = 15 (changed, this is normal)

v1.log_vec_info();  // x1 = 15 (changed! this is not normal since we want change only v2)

```

### Visual Summary

```
Shallow Copy Behavior:
┌──────────┐    ┌──────────┐
│    v1    │    │    v2    │     <- Different stack addresses
│          │    │          │
│   m_x ───┼────┼──> [5.0] │     <- Same heap memory
│   m_y ───┼────┼──> [10.0]│     <- Same heap memory
└──────────┘    └──────────┘
```

## The Problem with shallow copy

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

---

## Bugs and Errors

### `-Wreorder` Warning in Constructor Initializer List

**Warning message (triggered by `make run_heap_copy`):**

```
src/heap_vec.hpp: In constructor 'heap_vec2::heap_vec2()':
src/heap_vec.hpp:19:19: warning: 'heap_vec2::m_y' will be initialized after [-Wreorder]
   19 |     float *m_x , *m_y;
src/heap_vec.hpp:16:17: warning:   'std::string heap_vec2::m_vec_name' [-Wreorder]
   16 |     std::string m_vec_name;
src/heap_vec.cpp:15:1: warning:   when initialized here [-Wreorder]
   15 | heap_vec2::heap_vec2():
```

**Cause:**

`C++` always initializes member variables **in the order they are declared in the class**, regardless of the order written in the constructor's initializer list.

In `heap_vec.hpp`, the declaration order is:
```cpp
class heap_vec{
  
  private:

std::string m_vec_name;   // declared 1st
float *m_x , *m_y;        // declared 2nd & 3rd

...

} // End class heap_vec
```

But in the default constructor (`heap_vec.cpp`), the initializer list was written in a different order:
```cpp
heap_vec2::heap_vec2():
    m_x(new float{0}),    // written 1st ❌
    m_y(new float{0}),    // written 2nd ❌
    m_vec_name{"v_0"}     // written 3rd ❌
```

The compiler warns because the written order does not match the actual initialization order.
If one member's initializer depended on another already being set, this mismatch could cause subtle bugs with undefined behavior.

**Fix:** Reorder the initializer list to match the declaration order in the header:

```cpp
heap_vec2::heap_vec2():
    m_vec_name{"v_0"},    // 1st — matches declaration order ✅
    m_x(new float{0}),    // 2nd ✅
    m_y(new float{0})     // 3rd ✅
{
    std::cout << "\t -> Default constructor called" << std::endl << std::endl;
}
```
