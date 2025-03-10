# Push Swap Project

## Overview
The Push Swap project implements a sorting algorithm using two stacks. The goal is to sort a list of integers with the least number of operations possible. This project is a common exercise in algorithm optimization and data structure manipulation.

## Files
- **src/main.c**: Entry point of the application. Initializes the program and calls necessary functions.
- **src/push_swap.c**: Contains the main logic for the push-swap algorithm, including sorting and stack management.
- **src/operations.c**: Defines stack operations such as push, swap, and rotate.
- **src/utils.c**: Includes utility functions for error handling, memory management, and input parsing.
- **includes/push_swap.h**: Header file with function and structure declarations.

## Compilation
To compile the project, use the provided Makefile. Run the following command in the terminal:

```
make
```

This will generate the executable file.

## Running the Program
After compilation, you can run the program with the following command:

```
./push_swap [list of integers]
```

Replace `[list of integers]` with the integers you want to sort.

## Example
To sort the integers 3, 2, 1, run:

```
./push_swap 3 2 1
```

## Notes
- Ensure that the input integers are valid and do not contain duplicates.
- The program will output the sequence of operations performed to sort the integers. 

## License
This project is open-source and available for modification and distribution under the terms of the MIT License.