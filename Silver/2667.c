/* 백준 2667(단지번호붙이기)
(silver/2178.c 참고) 2차원 배열이 아닌 1차원 배열에서 탐색하는 bfs 함수에 count값을 추가하여 단지 당 집 개수 카운트 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int compare (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

typedef int element;

typedef struct {
    int front;
    int rear;
    int size;
    element* data;
} queue;

void init_queue (queue* q, int size) {
    q->front = 0;
    q->rear = 0;
    q->size = size + 1;
    q->data = malloc(q->size * sizeof(element));
}

bool is_empty (queue* q) {
    return q->front == q->rear;
}

bool is_full (queue* q) {
    return (q->rear + 1) % q->size == q->front;
}

bool enqueue (queue* q, element value) {
    if (is_full(q)) {
        printf("queue is full.\n");
        return false;
    }
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = value;
    return true;
}

element dequeue (queue* q) {
    if (is_empty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    q->front = (q->front + 1) % q->size;
    return q->data[q->front];
}

void free_queue(queue* q) {
    free(q->data);
}

typedef struct {
    int is_house;
    int visited;
} target;

void bfs (target* t, int start, int t_size, int n, int* village, int idx) {
    t[start].visited = 1;
    t[start].is_house = 2;
    queue q;
    init_queue(&q, t_size);
    enqueue(&q, start);

    int count = 1;
    while (!is_empty(&q)) {
        int current_num = dequeue(&q);
        int move[4] = {current_num - n, current_num - 1, current_num + 1, current_num + n};
        for (int i = 0; i < 4; i++) {
            int next = move[i];
            if (next < 1 || next > t_size) continue;
            else if ((current_num - 1) % n == 0 && i == 1) continue;
            else if (current_num % n == 0 && i == 2) continue;
            else if (t[next].visited == 0 && t[next].is_house == 1) {
                t[next].visited = 1;
                t[next].is_house = 2;   //탐색한 집은 2로 값을 바꾸어서 bfs에 다시 들어오는 경우 방지
                enqueue(&q, next);
                count++;    //집이 탐색될 때마다 count값 증가
            }
        }
    }

    village[idx] = count;   //배열에 단지 수 입력

    free_queue(&q);
}

int main(void) {
    int n;
    scanf("%d", &n);

    target* map = calloc(n * n + 1, sizeof(target));

    for (int i = 1; i <= n * n; i++) {
        char num;
        scanf(" %c", &num);

        if (num == '0') continue;
        else if (num == '1') map[i].is_house = 1;
        else return 1;
    }

    int* village = malloc(n * n * sizeof(int));
    int idx = 0;

    for (int i = 1; i <= n * n; i++) {
        if (map[i].is_house == 1) {
            bfs(map, i, n * n, n, village, idx);
            idx++;  //bfs 함수가 실행될 때마다 idx값 증가를 통해 단지 수 카운트 + 다음 입력 준비
        }
    }

    printf("%d\n", idx);
    qsort(village, idx, sizeof(int), compare);  //집 개수에 따라 정렬
    for (int i = 0; i < idx; i++) {
        printf("%d\n", village[i]);
    }

    free(map);

    return 0;
}