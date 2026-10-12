# g++ Tool: C++ Compiler on Ubuntu

This README contains some information about the C++ compiler (`g++`) on Ubuntu Linux.

## 1. Checking Installed Compiler

To see which C and C++ compilers are installed and their versions:

```bash
gcc --version   # GNU C Compiler
g++ --version   # GNU C++ Compiler
```

## 2. Checking Supported C++ Standards

`g++` supports multiple C++ standards. You can specify the standard with the `-std=c++XX` flag:

- `c++98`
- `c++03`
- `c++11`
- `c++14`
- `c++17`
- `c++20`
- `c++23` (supported in recent versions)

Example:
```bash
g++ -std=c++20 --version
```
If no error in the terminal is shown, this means that this standard is supported.

## 3. My Current Compiler Version

In my computer the following version is used:
```
g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
```
This version supports all major C++ standards up to C++23.

## 4. More Information

For details on supported features and standards:
- [GCC C++ Status Page](https://gcc.gnu.org/projects/cxx-status.html)

## 5. Troubleshooting

- If a standard is not recognized, your compiler may be outdated.
- Update with: `sudo apt update && sudo apt upgrade build-essential`

---
Feel free to add more notes or commands as you learn!
