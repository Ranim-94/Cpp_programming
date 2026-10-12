# Inheritance in C++

## Table of Contents

- [Inheritance in C++](#inheritance-in-c)
  - [Table of Contents](#table-of-contents)
  - [Inheritance Definition](#inheritance-definition)
  - [Implementation in C++](#implementation-in-c)
  

---

## Inheritance Definition

**Inheritance** is a technique in OOP where we group many common attributes in some general class.

For example: in university, we have many student: medical student, engineering,...

All of these students have an `ID` and some `start_year` for example, so instead of implementing each of these members in a separate class, we group them in 1 common class, referred to as the **base class** (or the **parent class**).

Medical students, engineering students are referred **derived class** (also knowns **child**, or **subclass**)

## Implementation in C++

To demonstrace inheritance, we implement 2 classes: `Student` and `Medical_Student`


<u>Derived Class</u>

```cpp
/* 1st derived class */
class Medical_Student:public Student{

private:

std::string m_specialty;

public:

 /* Constructor */   
 Medical_Student(std::string name, int start_year,
                std::string specialty);

 
 ~Medical_Student(); /* Destructor */


}; /* End class Medical_Student */
```

- the syntax
<pre>class Medical_Student:public Student</pre>

means class `Medical_Student` inherit public member from base class `Student`


- Always recall that in the constructor of a derived class;
we should input the attributes of the base class (that we inherited)
- but we don't need to declare these attributes again in the private
section, where we declare the members (attributes of the class)