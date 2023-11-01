# Hawk - Functional C++ Library
Hawk is a functional programming library for C++ that emphasizes ease of use and productivity by offering a wide range of tools for working with collections, strings, numbers, and custom data types. It also supports curried functions for enhanced composability.

Why Hawk? Because it allows you to swoop down and handle your data with precision, making your code as sharp and efficient as a hawk's talons!

## Features

- **Currying**: Convert multi-argument functions into a sequence of functions that each take a single argument.
- **Pipe**: Compose functions from left to right, creating a pipeline of functions that transforms data.
- **Compose**: Compose functions from right to left, creating a function that is the composition of multiple functions.
- **Number Utilities**: A collection of utility functions that operate on numeric data types like float, int, and double.
- **String Utilities**: A suite of functions designed for efficient string manipulation.
- **Custom Data Types**: Functions that work seamlessly with user-defined data types.
- And much more!

## Getting Started

Include the Funcat library in your C++ project to start using its features.

```cpp
#include "hawk.h"
```

## Examples

Here are a few examples to get you started with Funcat:

```cpp
// Curry example
auto add = [](int a, int b) { return a + b; };
auto add5 = hawk::curry(add)(5);
std::cout << add5(3);  // Output: 8

// Pipe example
auto multiplyBy2 = [](int a) { return a * 2; };
auto subtract3 = [](int a) { return a - 3; };
auto operation = hawk::pipe(multiplyBy2, subtract3);
std::cout << operation(10);  // Output: 17
```

## Performance and Efficiency

Funcat is designed to be easy to use without compromising on performance and efficiency. We leverage modern C++ features to ensure that the library is both expressive and performant.
