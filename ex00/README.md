# Scalar Converter

This project implements a `ScalarConverter` class that converts a string representation of a C++ literal into various scalar types: `char`, `int`, `float`, and `double`. The conversion handles common literals, including special cases like `nan`, `+inf`, and `-inf`.

## Files

- **Makefile**: Contains build instructions for compiling the source files and linking them to create the executable.
- **ScalarConverter.cpp**: Implements the `ScalarConverter` class and its static method `convert`.
- **ScalarConverter.hpp**: Declares the `ScalarConverter` class and its method, including necessary headers for numeric limits and special values.
- **main.cpp**: Contains the `main` function to test the `ScalarConverter` class.

## Compilation

To compile the project, navigate to the `ex00` directory and run the following command:

```
make
```

This will generate an executable named `convert`.

## Usage

To use the `ScalarConverter`, run the executable with a string representation of a C++ literal as an argument:

```
./convert <literal>
```

### Examples

1. For input `0`:
   ```
   char: Non displayable
   int: 0
   float: 0.0f
   double: 0.0
   ```

2. For input `nan`:
   ```
   char: impossible
   int: impossible
   float: nanf
   double: nan
   ```

3. For input `42.0f`:
   ```
   char: '*'
   int: 42
   float: 42.0f
   double: 42.0
   ```

## Notes

- The `ScalarConverter` class is designed to handle various edge cases, including non-displayable characters and overflow situations.
- Ensure that the input literals are in the correct format for accurate conversion.