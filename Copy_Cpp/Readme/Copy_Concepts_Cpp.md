# Copy Concepts in C++

This document illustrate copy concepts in `C++`.

Copying like for example `int a = b` seems trivial with primitive and simple data type, but with more complex data types (`struct`,`class`) things get trickier and more complex.

1. we start with primitive data (`int,float,...`) and `strcut`, both on stack and heap.

2. we move to `class` data type, and introduce the notion of **copy assignement** and **copy constructor**, all on the stack (so no dynamic memory or heap allocation).

3. we continue with `class` but on the heap (dynamic objects).


The current readme file focus on case 1) and 2), that is we explore concept where our data (primitive and non-primitive) are on the stack.

---

## Table of Contents

- [Copy Concepts in C++](#copy-concepts-in-c)
  - [Table of Contents](#table-of-contents)
  - [1. Working with Primitive and Struct Data Types](#1-working-with-primitive-and-struct-data-types)
    - [Primitive Data type](#primitive-data-type)
    - [Structs Data type (on the stack)](#structs-data-type-on-the-stack)
    - [Copying via Pointers (Dynamic Memory)](#copying-via-pointers-dynamic-memory)
      - [Memory Handling](#memory-handling)
  - [2. Classes: Copy Assignment Operator vs. Copy Constructor](#2-classes-copy-assignment-operator-vs-copy-constructor)
    - [Copy Assignment Operator](#copy-assignment-operator)
    - [Copy Constructor](#copy-constructor)
  - [3. Classes with Dynamic Memory: The need of copy constructor](#3-classes-with-dynamic-memory-the-need-of-copy-constructor)
    - [Best Practices](#best-practices)
  - [4. Passing Objects to Functions](#4-passing-objects-to-functions)
  - [5. Rule of 3 and the Rule of 2](#5-rule-of-3-and-the-rule-of-2)

---

## 1. Working with Primitive and Struct Data Types

[Part1: main_copy_primitive.cpp](./main_copy_primitive.cpp)

### Primitive Data type

- Copying primitive types (e.g., `int a = b;`) creates a new variable with its own memory address.
- Changing one variable does not affect the other.

### Structs Data type (on the stack)

<u>Code Snippets:</u>

```cpp
struct vec_2{

float x,y; // 2D coordinate

};

int main(){

vec_2 v1{.x=5.0f,.y=10.0f};  // create a v1 vec_2

vec_2 v2 = v1; // creating v2 and initialize it to using v1 values of (x,y)

} /*End main()*/
```

- Copying a struct (e.g., `vec_2 v2 = v1;`) creates a new copy of the entire struct.
- Each struct instance has its own memory address and data.

### Copying via Pointers (Dynamic Memory)

```cpp
// allocating and initializing a vector on the heap
vec_2* v3 = new vec_2{.x = 2.0f, .y = 3.0f}; 

vec_2* v4 = v3; // copying the pointer (address) of v3 into v4
```

- Copying pointers (e.g., `vec_2* v4 = v3;`) copies the address, not the data.
- Both pointers point to the same memory location; changes via one pointer affect the other.
  - any chnage in `v3` will affect `v4`
- Shared ownership can lead to issues like double deletion if not managed properly.

#### Memory Handling

In the case of pointers, since `v3` and `v4` points to the same addresse, we need to delete only once

```cpp
delete v3;
```

## 2. Classes: Copy Assignment Operator vs. Copy Constructor

[Point 2: main_object_copy.cpp](./main_object_copy.cpp)

### Copy Assignment Operator

- Used to copy data between already constructed objects.
  - Does not create a new object

<u>Code in the main:</u>

```cpp
// setting up parameters    
float x = 1.5f, y = 2.5f;

// create an instance of some vector
Vector2 my_vec_1{x,y};

Vector2 my_vec_2; // this with a default constructor

// apply an assignment: this case default copy assignment operator will be called
my_vec_2 = my_vec_1;

```

`Cpp` provide us with a default copy assignment operator, where be default the member variables will be equal each other.

In [main_heap_copy_vec](./main_heap_copy_vec.cpp) we see how to implement our own one

### Copy Constructor

- It creates a new object as a copy of an existing one. Allocates new memory and copies values.
  - since the we are discussing object on stack, that is member variables are on the stack, change in 1 doesn't affect the other.

```cpp
// Here we have use the copy constructor
Vector2 my_3rd_vec = my_vec_1;

```

<u>Implementation of Copy Constructor</u>

```cpp
// Here we have use the copy constructor
Vector2::Vector2(const& Vector2 my_vec2):
m_x{2*my_vec2.x},
m_y{2*my_vec2.y}{

}; /* End Vector2() */

```

<u>Notes about copy constructor:</u>

- Inputs arguments: it takes a const reference object, and not normal input variable as in the case of normal parametrized constructor, where members (attributes) are the actual input arguments

## 3. Classes with Dynamic Memory: The need of copy constructor

[Points 3: main_heap_copy_vec.cpp](./main_heap_copy_vec.cpp)

- When a class manages its own dynamic memory (e.g., with pointers), a ***custom copy constructor is needed***.
- The copy constructor should allocate new memory and copy the values, ensuring each object manages its own resources.
  - This concept is called ***deep copy***
  - That is we copy what is in the memory, and not the memory itself (this is known the ***shallow copy***)
  - The copied content will be moved into a different memory address.
- This prevents double deletion and ensures proper cleanup when destructors are called.

### Best Practices

- Always define a copy constructor and destructor for classes that manage dynamic memory.
- Use the copy constructor to allocate separate memory for each object.
- Proper resource management avoids memory leaks and double deletion errors.

---

## 4. Passing Objects to Functions

[Point 4: main_obj_func.cpp](./main_obj_func.cpp)

- When passing objects to functions, we should ***pass them by references*** (and better by `const &` to prevent accident modifiation of object inside the function), so we don't have many copies.
- Otherwise, the copy constructor will be called (even if we don't implement one, the compiler generated one will be called) each we invoke the function using the object as parameter.

## 5. Rule of 3 and the Rule of 2

- The ***Rule of big 3*** states that if we define our constructor for some reason (some algorithm to initilize the variable,...) we should also define and implement the copy constructor and the destructor
- The ***Rule of big 2***: you can get away from implementing a destructor, if you know you member data will handle the resources appropirly
  - Such as havin a `vector<int> data` for example in the member section
  - The `vector` containor handle deleting data internally
- <u>Reference:</u> [The rule of three/five/zero](https://de.cppreference.com/w/cpp/language/rule_of_three.html)