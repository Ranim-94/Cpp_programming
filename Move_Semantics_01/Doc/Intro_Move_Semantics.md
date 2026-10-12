# Introduction to Move Semantics

## Table of Contents

- [Why Move Semantics?](#why-move-semantics)
- [Copying Objects](#copying-objects)
  - [Copying a String](#copying-a-string)
  - [Passing an Argument to a Function](#passing-an-argument-to-a-function)
- [Transferring Resources](#transferring-resources)
  - [Using References](#using-references)
  - [Using `std::move`](#using-stdmove)
- [Moved-from Objects](#moved-from-objects)

## Why Move Semantics?

C++ programs often copy objects. Copying can take time and use additional memory,
especially when an object owns a resource such as a dynamically allocated buffer.
Move semantics provide a way to transfer resources from one object to another
instead of copying those resources.

## Copying Objects

### Copying a String

For example, initializing `s2` from `s1` copies the string:

```cpp
std::string s1 = "long string";
std::string s2 = s1;
```

This invokes the string's copy constructor. The resulting `s2` has its own copy
of the string's contents, independent of `s1`.

### Passing an Argument to a Function

Passing an object by value also copies it into the function parameter:

```cpp
void func(std::string s3) {
    // Work with the function's own string object.
}

std::string value = "some text";
func(value); // Copies value into s3.
```

If the function only needs to use the caller's object without taking ownership,
it can accept a reference instead.

## Transferring Resources

### Using References

A non-const lvalue reference lets a function work with the caller's object
without making a copy. Since `s3` refers to the same string as `value`, changing
`s3` inside the function also changes `value`:

```cpp
#include <iostream>
#include <string>

void func(std::string& s3) {
    s3 += " changed in func";
}

int main() {
    std::string value = "original";
    func(value);
    std::cout << value << '\n';
}
```

Output:

```text
original changed in func
```

A reference does not transfer ownership: `value` is still the caller's string
and remains alive after `func` returns. The function only gets another way to
access that same object. This differs from passing by value, which gives the
function its own copy.

### Using `std::move`

When the caller no longer needs an object's current value, `std::move` can
enable a move operation that transfers its resources:

```cpp
std::string my_string{"move these contents"};
std::string new_string{};

new_string = std::move(my_string);
```

`std::move` does not move anything by itself; it makes the expression eligible
for a move operation. The selected move assignment or move constructor performs
the transfer when the type provides one.

## Moved-from Objects

After a successful move, the source object remains valid, but its value is
unspecified unless the type documents a more specific state. It can be
destroyed or assigned a new value; do not rely on its previous contents.