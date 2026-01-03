# Building `sillyBot.dll` from `aiInterface.cpp`

This document contains **only the steps required** to compile a DLL from a single C++ source file using GCC on Windows.

---

## 1. Install MSYS2

Download and install MSYS2:

[https://www.msys2.org/](https://www.msys2.org/)

---

## 2. Install GCC

Open **MSYS2 MINGW64** from the Start Menu and run:

```bash
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```

---

## 3. Open the project directory

In the same terminal, navigate to the folder containing `aiInterface.cpp`:

```bash
cd /c/path/to/your/project
```

---

## 4. Compile the DLL

Run:

```bash
g++ -shared -o sillyBot.dll aiInterface.cpp
```

---

## Result

The file `sillyBot.dll` will be created in the same directory.
