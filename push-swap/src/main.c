#include "push_swap.h"

int main(int argc, char **argv) {
    // Initialize the program and check for errors
    if (argc < 2) {
        write(2, "Error: No arguments provided\n", 30);
        return 1;
    }

    // Parse input and initialize stacks
    t_stack *stack_a = parse_input(argc, argv);
    if (!stack_a) {
        write(2, "Error: Invalid input\n", 21);
        return 1;
    }

    // Execute the push-swap algorithm
    push_swap(stack_a);

    // Free allocated memory
    free_stack(stack_a);
    return 0;
}