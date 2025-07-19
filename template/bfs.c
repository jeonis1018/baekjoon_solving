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
    int visited;
    int connected_cnt;
    int* connected;
} target;

void bfs (target* t, int start, int t_size) {
    t[start].visited = 1;
    queue q;
    init_queue(&q, t_size);
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int current_num = dequeue(&q);
        for (int i = 0; i < t[current_num].connected_cnt; i++) {
            int next = t[current_num].connected[i];
            if (t[next].visited == 0) {
                t[next].visited = 1;
                enqueue(&q, next);
            }
        }
    }

    free_queue(&q);
}

int main(void) {


    return 0;
}