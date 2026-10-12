# Polymorphism in C++

## Table of Contents

- [Polymorphism in C++](#polymorphism-in-c)
  - [Table of Contents](#table-of-contents)
  - [Inheritance](#inheritance)
  - [What is Polymorphism?](#what-is-polymorphism)
  - [Requirements for Polymorphism](#requirements-for-polymorphism)
  - [Types of Polymorphism](#types-of-polymorphism)
  - [Dynamic Binding Requirements](#dynamic-binding-requirements)
  - [Notes from Reading](#notes-from-reading)
    - [Goal of Runtime Polymorphism](#goal-of-runtime-polymorphism)

---

## Inheritance

Inheritance is a technique in OOP where we group many common attributes in some general class.

For example: in university, we have many student: medical student, engineering,...

All of these students have an `ID` and some `start_year` for example, so instead of implementing each of these members in a separate class, we group them in 1 common class, referred to as the **base class** (or the **parent class**).

Medical students, engineering students are referred **derived class** (also knowns **child**, or **subclass**)

## What is Polymorphism?

Polymorphism refers to the concept that we can point to or refer an object to some other object:

- A derived class instance can be stored/referenced through a base class pointer or reference.
- **Example:**
  ```cpp
  Character* char_1 = &hero; // hero is an instance of a class derived from Character
  ```

---

## Requirements for Polymorphism

- A **base class** and at least one **derived class**.
- A function that is **redefined** in the derived class.
- The `virtual` keyword on the base class function — this tells the compiler the function may be overridden in a derived class.
- If the derived class itself also has derived classes (multilevel inheritance), the `virtual` keyword can be applied there as well.

---

## Types of Polymorphism

| Type | Keyword | Binding | Description |
|------|---------|---------|-------------|
| **Static** | *(none)* | Compile-time | C++ uses the function defined in the base class. |
| **Dynamic** | `virtual` | Run-time | The compiler infers at run time which function to call (dynamic binding). |

---

## Dynamic Binding Requirements

To enable dynamic (runtime) binding you need:

1. The `virtual` keyword on the base class function.
2. Access to the object via a **pointer** (`*`) or a **reference** (`&`).

---

## Notes from Reading

> **Source:** *C++20 for Programmers*, Chapter 10

### Goal of Runtime Polymorphism

- Program in a **generic** way.
- Treat all objects as a general object (the base class type).
- **Benefit:** Makes code easily extensible — only the new derived class code needs to be modified when adding new behaviour.
