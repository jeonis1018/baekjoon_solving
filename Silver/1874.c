/* 백준 1874(스택 수열)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int* arr;
    int top;
    int size;
} stack;

void init_stack (stack* s, int size) {
    s->arr = malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
}

bool is_empty (stack* s) {
    return s->size == -1;
}

bool is_full (stack* s) {
    return s->top + 1 == s->size;
}

void push (stack* s, int value) {
    if (!is_full(s)) s->arr[++s->top] = value;
    else {
        printf("stack is full\n");
        return;
    }
    return;
}

int pop (stack* s) {
    if (!is_empty) return s->arr[s->top--];
    else {
        printf("stack is empty\n");
        return 0;
    }
}

void free_stack (stack* s) {
    free(s->arr);
}

int main(void) {
    int n;
    scanf("%d", &n);

    stack s;

    init_stack(&s, n);
    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    

    return 0;
}