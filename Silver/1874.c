/* 백준 1874(스택 수열)
스택을 구현한 후에 스택의 top과 배열의 값을 비교해가며 push, pop 시행 */

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
    return s->top == -1;
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
    if (!is_empty(s)) return s->arr[s->top--];
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
    char* res = malloc(n * 2 * sizeof(char));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int r_index = 0;
    push(&s, 1);
    res[r_index++] = '+';

    int push_num = 2, fail = 0;
    for (int i = 0; i < n; i++) {   //수의 순서를 저장한 배열을 따라가는 for문
        if (s.arr[s.top] == arr[i]) {
            pop(&s);
            res[r_index++] = '-';
        } else if (s.arr[s.top] < arr[i]) {
            while (s.arr[s.top] < arr[i]) {
                push(&s, push_num++);
                res[r_index++] = '+';
            }

            if (s.arr[s.top] == arr[i]) {
                pop(&s);
                res[r_index++] = '-';
            }
        } else {    //push나 pop 둘 중 아무것도 시행되지 않았다면 불가능한 것이므로 중단
            fail = 1;
            break;
        }
    }

    if (fail == 1) printf("NO\n");
    else {
        for (int i = 0; i < r_index; i++) {
            printf("%c\n", res[i]);
        }
    }

    free_stack(&s);
    free(arr);
    free(res);

    return 0;
}