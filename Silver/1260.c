/* 백준 1260(DFS와 BFS)
재귀함수를 이용한 dfs 구현 및 queue를 통한 bfs 구현 */

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
    int visited;
    int connected_cnt;
    int* connected;
} node;

void dfs (node* nd, int start) {
    nd[start].visited = 1;
    printf("%d ", start);
    //해당 노드의 connected 배열 내에서 visited가 0인 노드가 있을 경우 dfs 재귀적 호출
    for (int i = 0; i < nd[start].connected_cnt; i++) {
        int next = nd[start].connected[i];
        if (nd[next].visited == 0)
            dfs(nd, next);
    }
}

void bfs (node* nd, int start, int size) {
    nd[start].visited = 1;
    queue q;
    init_queue(&q, size);
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int current_num = dequeue(&q);
        printf("%d ", current_num);
        //방문한 노드의 connected 배열 내에 있는 값들 중 visited가 0인 노드를 모두 queue에 추가
        for (int i = 0; i < nd[current_num].connected_cnt; i++) {
            int next = nd[current_num].connected[i];
            if (nd[next].visited == 0) {
                nd[next].visited = 1;
                enqueue(&q, next);
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    node* nd = calloc(n + 1, sizeof(node));

    for (int i = 1; i <= n; i++) {
        nd[i].connected = malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int n1, n2;
        scanf("%d %d", &n1, &n2);

        nd[n1].connected[nd[n1].connected_cnt++] = n2;
        nd[n2].connected[nd[n2].connected_cnt++] = n1;
    }

    for (int i = 1; i <= n; i++) {
        qsort(nd[i].connected, nd[i].connected_cnt, sizeof(int), compare);
    }

    dfs(nd, v);
    for (int i = 1; i <= n; i++) {  //dfs를 실행했으므로 visited값 0으로 초기화
        nd[i].visited = 0;
    }
    printf("\n");
    bfs(nd, v, n);

    free(nd);

    return 0;
}