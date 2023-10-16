# Funcat

Funcat is a functional programming library for C++ that focuses on enabling curried functions and providing an expressive set of tools for working with collections, strings, numbers, and custom data types.<br>
Why Funcat? Because functions are purr-fectly amazing, and we all know cats rule the internet (and our hearts)!

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
#include "funcat.h"
```

## Examples

Here are a few examples to get you started with Funcat:

```cpp
// Curry example
auto add = [](int a, int b) { return a + b; };
auto add5 = funcat::curry(add)(5);
std::cout << add5(3);  // Output: 8

// Pipe example
auto multiplyBy2 = [](int a) { return a * 2; };
auto subtract3 = [](int a) { return a - 3; };
auto operation = funcat::pipe(multiplyBy2, subtract3);
std::cout << operation(10);  // Output: 17
```

## Performance and Efficiency

Funcat is designed to be easy to use without compromising on performance and efficiency. We leverage modern C++ features to ensure that the library is both expressive and performant.
