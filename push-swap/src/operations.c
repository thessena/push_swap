void push(int **stack_a, int *top_a, int value) {
    (*top_a)++;
    (*stack_a)[*top_a] = value;
}

void pop(int **stack_a, int *top_a) {
    if (*top_a >= 0) {
        (*top_a)--;
    }
}

void swap(int *stack, int top) {
    if (top > 0) {
        int temp = stack[top];
        stack[top] = stack[top - 1];
        stack[top - 1] = temp;
    }
}

void rotate(int *stack, int top) {
    if (top > 0) {
        int temp = stack[top];
        for (int i = top; i > 0; i--) {
            stack[i] = stack[i - 1];
        }
        stack[0] = temp;
    }
}

void reverse_rotate(int *stack, int top) {
    if (top > 0) {
        int temp = stack[0];
        for (int i = 0; i < top; i++) {
            stack[i] = stack[i + 1];
        }
        stack[top] = temp;
    }
}