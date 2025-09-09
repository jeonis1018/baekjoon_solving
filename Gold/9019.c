/* 백준 9019(DSLR)
bfs를 통해서 한 수로부터 도달할 수 있는 4개의 수를 탐색해 나가고, 도달한 경로를 저장해놨다가 역추적하여 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int visited;
    int depth;
    int parent; //역추적을 위해서 어떤 수로부터 왔는지 저장
    char route;
} num;

typedef int element;

typedef struct {
    int front;
    int rear;
    int size;
    element* data;
} queue;

void init_queue (queue* q, int size) {
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->data = malloc(q->size * sizeof(element));
}

bool is_empty (queue* q) {
    return q->front == q->rear;
}

bool is_full (queue* q) {
    return q->rear == q->size - 1;
}

bool enqueue (queue* q, element value) {
    if (is_full(q)) {
        printf("queue is full.\n");
        return false;
    }
    q->data[++q->rear] = value;
    return true;
}

element dequeue (queue* q) {
    if (is_empty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    return q->data[++q->front];
}

void free_queue(queue* q) {
    free(q->data);
}

void bfs(num* n, int start, int b) {
    n[start].visited = 1;
    queue q;
    init_queue(&q, 10000);
    enqueue(&q, start);
    while (!is_empty(&q)) {
        int current = dequeue(&q);
        if (current == b) break;
        int next[4];
        next[0] = (current * 2) % 10000;    //'D'함수 결과값
        next[1] = current - 1;  //'S'함수 결과값
        if (next[1] < 0) next[1] = 9999;    //'S'함수 음수 예외처리
        next[2] = ((current * 10) + (current / 1000)) % 10000;  //'L'함수 결과값
        next[3] = (current / 10) + (current % 10) * 1000;   //'R'함수 결과값
        for (int i = 0; i < 4; i++) {
            if (n[next[i]].visited == 0) {
                enqueue(&q, next[i]);
                n[next[i]].visited = 1;
                n[next[i]].depth = n[current].depth + 1;
                n[next[i]].parent = current;    //부모값 저장
                if (i == 0) n[next[i]].route = 'D';
                else if (i == 1) n[next[i]].route = 'S';
                else if (i == 2) n[next[i]].route = 'L';
                else if (i == 3) n[next[i]].route = 'R';
                else return;
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        num* n;
        int a, b;
        scanf("%d %d", &a, &b);

        n = calloc(10000, sizeof(num));

        bfs(n, a, b);
        
        char* route;
        route = malloc((n[b].depth + 1) * sizeof(char));
        route[n[b].depth] = '\0';
        for (int j = n[b].depth - 1; j >= 0; j--) { //역추적을 통해 루트 문자열 생성
            route[j] = n[b].route;
            b = n[b].parent;
        }

        printf("%s\n", route);

        free(route);
        free(n);
    }

    return 0;
}