/* 백준 14940(쉬운 최단거리)
(silver/2178.c 참고) 목표지점을 시작으로 하여 1차원 배열 형태로 탐색을 진행한 후, 목표지점으로부터의 depth를 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

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
    int is_road;
    int depth;
    int visited;
} target;

void bfs (target* t, int start, int t_size, int m) {
    t[start].visited = 1;
    t[start].depth = 0;
    queue q;
    init_queue(&q, t_size);
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int current_num = dequeue(&q);
        int move[4] = {current_num - m, current_num - 1, current_num + 1, current_num + m};
        for (int i = 0; i < 4; i++) {
            int next = move[i];
            if (next < 1 || next > t_size) continue;
            else if ((current_num - 1) % m == 0 && i == 1) continue;
            else if (current_num % m == 0 && i == 2) continue;
            else if (t[next].visited == 0 && t[next].is_road == 1) {
                t[next].visited = 1;
                t[next].depth = t[current_num].depth + 1;   //depth를 1씩 늘려가며 목표지점으로부터의 거리 측정
                enqueue(&q, next);
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    target* map = calloc(n * m + 1, sizeof(target));

    int start;
    for (int i = 1; i <= n * m; i++) {
        int num;
        scanf("%d", &num);

        map[i].is_road = num;
        if (map[i].is_road == 2)
            start = i;
        else if (map[i].is_road == 1)
            map[i].depth = -1;  //도달 가능한 지점의 depth를 -1로 초기화 (도달할 수 없을 경우 그대로 -1이 출력됨)
    }

    bfs(map, start, n * m, m);

    for (int i = 1; i <= n * m; i++) {
        printf("%d ", map[i].depth);
        if (i % m == 0) printf("\n");
    }

    free(map);

    return 0;
}