# CS101 - Student Roster Application

**Course:** Scripting and Programming - Applications — C867  
**Author:** Brandon Ortiz  
**Student ID:** 900821299  
**Language:** C++

## Description

This is a C++ console application that manages a student roster for a cs101 college course im taking. It reads a hardcoded dataset of five students, parses the comma-separated values into Student objects, and stores them in an array of pointers. The program can print all students, validate email addresses, calculate average days in course per student, filter students by degree program, and remove students by ID.

## Files

| File | Purpose |
|------|---------|
| `degree.h` | Defines the DegreeProgram enum (SECURITY, NETWORK, SOFTWARE) |
| `student.h` | Student class declaration |
| `student.cpp` | Student class implementation (getters, setters, constructor, print) |
| `roster.h` | Roster class declaration |
| `roster.cpp` | Roster class implementation (parse, add, remove, print functions) |
| `main.cpp` | Entry point — loads data, creates roster, runs all required operations |

## How to Compile and Run

You need a C++ compiler that supports C++14 or later. This project was built with g++ via MinGW-w64 on Windows.

### Windows (MinGW-w64 in VS Code)

Open a terminal and set your PATH if needed:

```
$env:PATH += ";C:\mingw64\bin"
```

Compile:

```
g++ -std=c++14 -o roster.exe main.cpp student.cpp roster.cpp
```

Run:

```
.\roster.exe
```

### Linux / macOS

```
g++ -std=c++14 -o roster main.cpp student.cpp roster.cpp
./roster
```

## Expected Output

The program will:
1. Print course info, student ID, and student name
2. Print all 5 students in tab-separated format
3. Print invalid email addresses (3 of 5 are intentionally invalid)
4. Print average days in course for each student
5. Print only students in the SOFTWARE degree program
6. Remove student A3 and print the updated roster
7. Attempt to remove A3 again and print an error message
