#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void error_exit(const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int *allocate_array(int size)
{
    int *array = malloc(size * sizeof(int));
    if (!array)
        error_exit("Memory allocation failed");
    return array;
}

void free_array(int *array)
{
    free(array);
}

void parse_input(int argc, char **argv, int **array, int *size)
{
    if (argc < 2)
        error_exit("No input provided");

    *size = argc - 1;
    *array = allocate_array(*size);

    for (int i = 0; i < *size; i++)
    {
        (*array)[i] = atoi(argv[i + 1]);
    }
}