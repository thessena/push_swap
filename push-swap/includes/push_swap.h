#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack {
    int *data;
    int top;
    int size;
} t_stack;

void push(t_stack *src, t_stack *dest);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void sort_stacks(t_stack *a, t_stack *b);
void free_stack(t_stack *stack);
int is_sorted(t_stack *stack);
void parse_input(int argc, char **argv, t_stack *stack);
void handle_error(const char *message);

#endif /* PUSH_SWAP_H */