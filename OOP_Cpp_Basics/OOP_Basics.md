# OOP Basics in C++

## Table of Contents

- [OOP Basics in C++](#oop-basics-in-c)
  - [Table of Contents](#table-of-contents)
  - [Prerequiste](#prerequiste)
  - [Overview](#overview)
  - [1. Class Definition \& Access Modifiers](#1-class-definition--access-modifiers)
  - [2. Constructors](#2-constructors)
    - [Default Constructor](#default-constructor)
    - [Parameterized Constructor](#parameterized-constructor)
  - [3. Member Initializer List](#3-member-initializer-list)
  - [4. Getter (Accessor) \& Setter (Mutator) Methods](#4-getter-accessor--setter-mutator-methods)
  - [5. Object Instantiation](#5-object-instantiation)
    - [Stack-Allocated Object (Automatic Storage)](#stack-allocated-object-automatic-storage)
    - [Heap-Allocated Object (Dynamic Storage)](#heap-allocated-object-dynamic-storage)
  - [Summary Table](#summary-table)

---

This document summarizes the Object-Oriented Programming concepts demonstrated in the `OOP_Cpp_Basics` module, using a `Vector2` class as a practical example.

The idea presented here are introductory concetps, and more advanced concepts (like inheritance, polymorphism, copy constructor,...) will be explained in other modules

---

## Prerequiste

Before diving into OOP basics, familiarity with the following concepts is recommended:

- [Pointers](../pointers_cpp/) — understanding raw pointers, heap allocation, and the `->` operator is essential for working with heap-allocated objects.
- [Functions](../functions_cpp/) — knowledge of function definitions, parameters, and the `&` (reference) operator is needed to understand getters/setters and method signatures.
- [L-Values & R-Values](../LR_Values/) — understanding value categories helps clarify how objects are initialized and how the member initializer list works.

---

## Overview

The `Vector2` class represents a 2D Cartesian vector with coordinates `(x, y)` and a name/ID. It is used to demonstrate core OOP concepts such as class definition, constructors, member initializer lists, accessor/mutator methods, and object instantiation on the stack vs the heap.

---

## 1. Class Definition & Access Modifiers

Defined in `src/vectors.hpp`.

```cpp
class Vector2 {

    private:
        float m_x, m_y;                       // Cartesian coordinates
        std::string m_vec_name, m_vec_id;

    public:
        Vector2();                             // Default constructor
        Vector2(float x, float y, std::string vec_name); // Parameterized constructor

        float get_x(void);                    // Getter (accessor) methods
        float get_y(void);

        void set_x(float& x);                 // Setter (mutator) methods
        void set_y(float& y);

        void log_vec(void);                   // Logging method

}; /* End of class Vector2 */
```

- **`private`**: Member variables (`m_x`, `m_y`, `m_vec_name`, `m_vec_id`) are only accessible from within the class. This enforces **encapsulation**.
- **`public`**: Methods are accessible from outside the class, forming the class's interface.

---

## 2. Constructors

Both constructors are implemented in `src/vectors.cpp` using **member initializer lists**.

### Default Constructor

No arguments are required when creating an instance. Attributes are initialized to sentinel/default values.

```cpp
Vector2::Vector2():
    m_x{-1},
    m_y{-1},
    m_vec_name{"dummy_vec"},
    m_vec_id{"dummy_vec_-1_-1"}
{
    std::cout << "\t Default constructor called" << std::endl;
}
```

### Parameterized Constructor

Arguments are required when creating an instance. Coordinates and a name are provided by the caller.

```cpp
Vector2::Vector2(float x, float y, std::string vec_name):
    m_x{x},
    m_y{y},
    m_vec_name{vec_name},
    m_vec_id(vec_name.append("_" + std::to_string(x) + "_" + std::to_string(y)))
{
    std::cout << "\t Parameterized constructor called" << std::endl;
}
```

---

## 3. Member Initializer List

The syntax after the `:` in the constructor signature is called the **member initializer list**. Key points from the code comments:

- Each member variable is initialized **before** the constructor body executes.
- In the list, you can **call functions** — for example, `m_vec_id` uses `std::string::append()` to build the ID by concatenating the name, x, and y values:
  ```
  vec id format: <name>_<x>_<y>
  Example: v1_5.000000_10.000000
  ```
- You can reference **other member variables** inside the list — `m_vec_id` is built using `m_x`, `m_y`, and `vec_name`, not directly from a dedicated constructor argument.
- You can also **call constructors of member objects** from the list, since a constructor is itself a function.

---

## 4. Getter (Accessor) & Setter (Mutator) Methods

These methods provide controlled access to the private member variables.

```cpp
// Getters — read the value of a private attribute
float Vector2::get_x(void) { return this->m_x; }
float Vector2::get_y(void) { return this->m_y; }

// Setters — modify the value of a private attribute
void Vector2::set_x(float& x) { this->m_x = x; }
void Vector2::set_y(float& y) { this->m_y = y; }
```

The `this` pointer refers to the current object instance, used to explicitly access its member variables.

---

## 5. Object Instantiation

Demonstrated in `main_oop.cpp`.

### Stack-Allocated Object (Automatic Storage)

```cpp
float x{5}, y{10};

Vector2 v1{x, y, "v1"};  // Parameterized constructor — v1 has coordinates and a name
v1.log_vec();

Vector2 v2;               // Default constructor — no {} braces needed
v2.log_vec();
```

- Stack objects are destroyed **automatically** when they go out of scope.
- Members are accessed using the **dot operator** (`.`).

### Heap-Allocated Object (Dynamic Storage)

```cpp
Vector2* v3 = new Vector2{15, 20, "v3"};  // Allocated on the heap

v3->log_vec();  // Use -> operator to access members through a pointer

delete v3;      // Must manually free the memory — destructor is NOT called automatically
```

- Heap objects are **not destroyed automatically**. You must call `delete` to free the memory and invoke the destructor.
- Members are accessed using the **arrow operator** (`->`).

---

## Summary Table

| Concept                    | Description                                                                 |
|---------------------------|-----------------------------------------------------------------------------|
| `private` / `public`      | Access modifiers controlling encapsulation                                  |
| Default Constructor        | No arguments; initializes attributes to default/sentinel values             |
| Parameterized Constructor  | Takes arguments; initializes attributes from provided values                |
| Member Initializer List    | Initializes members before the constructor body; supports function calls    |
| Getter / Accessor          | Returns the value of a private member variable                              |
| Setter / Mutator           | Modifies the value of a private member variable                             |
| `this` pointer             | Refers to the current object instance inside a method                       |
| Stack object (`.`)         | Automatic lifetime; accessed via dot operator                               |
| Heap object (`->`)         | Manual lifetime; accessed via arrow operator; requires `delete`             |
