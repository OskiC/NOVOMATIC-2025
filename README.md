# Novomatic Internship 2025 Tasks
-[Task 1: Search Administrator](task1)

-[Task 2: Collision Detection](task2)

-[Task 3: Binary Operation](task3)

## Compiler

All solutions were tested on Windows using `CMake` 

## Building
If you are using terminal go to the main directory and:
```
cmake -S . -B cmake-build
cmake --build cmake-build --config Debug
```
Every task should be built.

## Dependencies

All required dependencies will be automatically downloaded and 
configured during the build process.
## Testing
Unit tests are written using GoogleTest (GTest).

To run all tests, use:
```
ctest --test-dir cmake-build
```