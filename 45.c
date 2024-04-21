#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* array;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->array[stack->top--];
}

void nextGreater(int arr[], int n) {
    struct Stack* stack = createStack(n);
    int next, element;
    push(stack, arr[0]);
    for (int i = 1; i < n; i++) {
        next = arr[i];
        if (!isEmpty(stack)) {
            element = pop(stack);
            while (element < next) {
                printf("%d --> %d\n", element, next);
                if (isEmpty(stack))
                    break;
                element = pop(stack);
            }
            if (element > next)
                push(stack, element);
        }
        push(stack, next);
    }
    while (!isEmpty(stack)) {
        element = pop(stack);
        next = -1;
        printf("%d --> %d\n", element, next);
    }
}

int main() {
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Next Greater Elements to the right are:\n");
    nextGreater(arr, n);
    return 0;
}
