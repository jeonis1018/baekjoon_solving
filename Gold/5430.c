/* 백준 5430(AC)
deque형태의 자료구조에 r(reverse)값을 추가하여 배열이 뒤집힌 상태인지 여부를 확인하며 함수 진행 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#define max_size 100001

typedef struct {
    int front;
    int rear;
    int size;
    int r;  //reverse 상태 판단 변수
    int* arr;
} ac;

void init_ac(ac* a, int size) {
    a->front = 0;
    a->rear = 0;
    a->size = 0;
    a->r = 0;
    a->arr = malloc(size * sizeof(int));
}

bool is_empty(ac* a) {
    if (a->size == 0) return true;
    else return false;
}

void insert(ac* a, int value) {
    a->arr[a->rear++] = value;
    a->size++;
}

int delete(ac *a) {
    if (is_empty(a)) {
        printf("ac is empty\n");
        return 0;
    }
    a->size--;
    return a->arr[a->front++];
}

int r_delete(ac *a) {   //delete함수 내에 조건문으로 구현할 경우 호출할 때마다 조건문이 실행되므로 따로 구현
    if (is_empty(a)) {
        printf("ac is empty\n");
        return 0;
    }
    a->size--;
    return a->arr[--a->rear];
}

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int error = 0;
        char func[max_size];
        int size;
        char arr[700000];
        ac a;

        scanf("%s", func);
        scanf("%d", &size);
        init_ac(&a, size);

        scanf("%s", arr);
        arr[strlen(arr) - 1] = '\0';    //맨 뒤에 있는 ']' 제거
        char* num = strtok(arr + 1, ",");   //맨 앞에 있는 '[' 를 제거한 상태에서 strtok를 통해 ',' 기준으로 나누기

        while (num != NULL) {
            insert(&a, atoi(num));  //각 값들을 int형으로 변환하여 insert
            num = strtok(NULL, ",");
        }

        int len = strlen(func);
        for (int j = 0; j < len; j++) {
            if (func[j] == 'D') {   //함수가 d일 경우 배열이 비어있는지 검사 후, reverse 상태에 따른 delete 실행
                if (is_empty(&a)) {
                    error = 1;
                    break;
                }
                if (a.r == 0) delete(&a);
                else r_delete(&a);
            } else if (func[j] == 'R') {    //함수가 r일 경우 r의 값을 0이나 1로 변환하여 reverse 상태 변환
                if (a.r == 0) {
                    a.r = 1;
                } else if (a.r == 1) {
                    a.r = 0;
                } else return 1;
            } else return 1;
        } 
        
        if (error == 1) {
            printf("error\n");
            continue;
        }

        printf("[");
        int s = a.size;
        if (a.r == 0) {
            for (int j = 0; j < s; j++) {
                if (j != 0) printf(",");
                printf("%d", delete(&a));
            }
        } else {
            for (int j = 0; j < s; j++) {
                if (j != 0) printf(",");
                printf("%d", r_delete(&a));
            }
        }
        printf("]\n");

        free(a.arr);
    }

    return 0;
}