# C++ Fundamentals Learning Repository

## Description

This repository contains my learning journey and exploration of fundamental concepts in C++.

## Table of Contents

- [C++ Fundamentals Learning Repository](#c-fundamentals-learning-repository)
  - [Description](#description)
  - [Table of Contents](#table-of-contents)
  - [Repo Structure](#repo-structure)
  - [Building](#building)
    - [Building Rules](#building-rules)
  - [Resources](#resources)
    - [Youtube Channels](#youtube-channels)
    - [Web Resources](#web-resources)
    - [More Formal Resources](#more-formal-resources)

## Repo Structure

- Each directory focuses on a specific idea or concept in C++.
- Examples include object-oriented programming, pointers, templates, inheritance, and more.

## Building

- Projects are currently built using Makefiles and the `g++` compiler.
- I plan to explore CMake for build automation in the future.

### Building Rules

The rule are step up to build each main_xx.cpp file, along with its dependencies (the headers and source files usually in my `src` directory).

To build an executable, use:
<pre> make build_xx</pre>

and to run:
<pre> make run_xx </pre>

The executable will be generated in a generated output directory

<u>Example</u>: for `main_heap_copy_vec.cpp` in `Copy_Cpp` directory, type:
<pre> make build_heap_copy_vec</pre>

To run:

<pre> make run_heap_copy_vec</pre>


To run also type: make run_heap_copy_vec

## Resources

### Youtube Channels

These youtube channels are more pedagogical and user friendly then official resources.

- [The Cherno](https://www.youtube.com/@TheCherno)
  - contains also its series about Hazel game engine
- [PortfolioCourses](https://www.youtube.com/@PortfolioCourses)
- [ProfessorHankStalica](https://www.youtube.com/@ProfessorHankStalica)
- [MikeShah](https://www.youtube.com/@MikeShah)
  - Nice content about graphic and games programming
- [CodeBeauty](https://www.youtube.com/@CodeBeauty)

### Web Resources

- [studyplan](https://www.studyplan.dev/)
  - nicely structured, and organized for each topic with some samples code
    - and straightforward
  - also some gamedev using SDL

### More Formal Resources

- [C++ Reference](https://en.cppreference.com/)
- [LearnCpp](https://www.learncpp.com/)
- [C++ Language Tutorial](https://www.cplusplus.com/doc/tutorial/)
- [ISO C++](https://isocpp.org/)
