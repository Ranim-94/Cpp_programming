# Copy Concepts in C++

[Points 1–3: main_copy_primitive.cpp](./main_copy_primitive.cpp)

[Point 4: main_object_copy.cpp](./main_object_copy.cpp)

[Points 5 and 6: main_heap_copy_vec.cpp](./main_heap_copy_vec.cpp)

## 1. Copying Primitive Data Types

- Copying primitive types (e.g., `int a = b;`) creates a new variable with its own memory address.
- Changing one variable does not affect the other.

## 2. Copying Structs

- Copying a struct (e.g., `vec_2 v2 = v1;`) creates a new copy of the entire struct.
- Each struct instance has its own memory address and data.

## 3. Copying Pointers and Dynamic Memory

- Copying pointers (e.g., `vec_2* v4 = v3;`) copies the address, not the data.
- Both pointers point to the same memory location; changes via one pointer affect the other.
- Shared ownership can lead to issues like double deletion if not managed properly.

## 4. Copy Assignment Operator vs. Copy Constructor

- **Copy Assignment Operator**: Used to copy data between already constructed objects. Does not create a new object.
- **Copy Constructor**: Used to create a new object as a copy of an existing one. Allocates new memory and copies values.

## 5. Copying Objects with Dynamic Memory

- When a class manages its own dynamic memory (e.g., with pointers), a custom copy constructor is needed.
- The copy constructor should allocate new memory and copy the values, ensuring each object manages its own resources.
- This prevents double deletion and ensures proper cleanup when destructors are called.

## 6. Best Practices

- Always define a copy constructor and destructor for classes that manage dynamic memory.
- Use the copy constructor to allocate separate memory for each object.
- Proper resource management avoids memory leaks and double deletion errors.

---
