# C++ Fundamentals Learning Repository

## Description

This repository contains my learning journey and exploration of fundamental concepts in C++.

## Table of Contents

- [C++ Fundamentals Learning Repository](#c-fundamentals-learning-repository)
  - [Description](#description)
  - [Table of Contents](#table-of-contents)
  - [Repo Structure](#repo-structure)
  - [Building](#building)
    - [Support for Modern C++](#support-for-modern-c)
    - [G++ Installation for Modern C++](#g-installation-for-modern-c)
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

### Support for Modern C++

To support modern C++ like `C++23` for example for a certain project,
riight click on project properties, than

<pre>C/C++ Build → Settings → GCC C++ Compiler → Dialect</pre>

Then we add the flag `std=c++23` as shown in [Figure 1](#fig1)

<div id="fig1">
<img src="Figures_VsCode/cpp_std_23.png" alt="Widget Types" width="450">
<p><strong>Figure 1:</strong> Configuring SFML in Eclipse</p>
</div>

### G++ Installation for Modern C++

Features like `<print>` and `std::println()` (`C++23`) need `GCC 14` or newer.
Ubuntu 24.04 (my current OS) ships `GCC 13` as the default `g++`, which does not provide `<print>`.

To use modern features, we need to install `g++-14`, that is `GCC14` (the update version)

<u>Difference between `g++-14` and `g++`:</u>

| | `g++-14` | `g++` |
|---|---|---|
| What it is | The GCC 14 compiler itself, as a versioned package | A meta-package that depends on the distribution's default g++ (version 13 on Ubuntu 24.04) |
| Installed | no, until `sudo apt install g++-14` | yes |
| Candidate | 14.2.0 from `noble-updates/universe` | 4:13.2.0 from `noble/main` |

- `g++` is what runs when typing `g++`. On Ubuntu 24.04 it points to GCC 13, so `<print>` fails.
- `g++-14` is a separate, optional package. Installing it adds a `g++-14` command alongside GCC 13 and does not replace the default `g++`.

Check the available versions with:

<pre>apt-cache policy g++</pre>

<pre>apt-cache policy g++-14</pre>

<u>**g++-14 Installation:**</u>

`g++-14` is available in the official Ubuntu repositories (no PPA needed):

```bash
sudo apt install g++-14 gcc-14
```

This installs `g++-14` alongside `g++-13`. The default `g++` stays at version 13, which Ubuntu still needs, so do not remove it.

<u>**Using `GCC 14` system wide**</u>

since now we have `GCC 13`(contains `g++ 13`) (official ubuntu 24.x) and `GCC 14`(contains `g++ 14`)(installed by me to use modern features), we need to manage different version of the same `g++` command. This can be done using with `update-alternatives`:

```bash
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-13 13
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 14
sudo update-alternatives --config g++
```

Using these bash commands above, we can use `g++14` for all our projects in any directory, rather than configuring each project in the IDE.

`update-alternatives` is the Debian/Ubuntu tool that manages several versions of the same command.
`/usr/bin/g++` becomes a symlink (through `/etc/alternatives/g++`) to the selected version.

- `--install /usr/bin/g++ g++ /usr/bin/g++-13 13`: registers `g++-13` as a candidate.
  - `/usr/bin/g++`: the generic link users run.
  - `g++`: the name of the alternatives group.
  - `/usr/bin/g++-13`: the real binary this entry points to.
  - `13`: the priority. In automatic mode, the highest number wins.
- `--config g++`: interactive menu to choose which registered version is active.
  Once a version is chosen manually, it stays selected regardless of priority.

`g++-13` is registered too, so it stays selectable after adding `g++-14`.

Check the active version of `g++` with

<pre>g++ --version</pre>

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
- [Andreas Fertig](https://www.youtube.com/@andreas_fertig)
  - Nice playlist, highlighting features and what is happening behind the sceens

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
