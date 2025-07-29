/* 백준 7576(토마토)
처음부터 1인 지점을 모두 저장한 배열을 bfs에 넣어서 다중 시작 bfs를 구현하여 해결 */

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
    int tomato;
    int visited;
    int depth;
} node;

void bfs(node* nd, int* start, int start_size, int m, int nd_size) {
    queue q;
    init_queue(&q, nd_size);
    //1인 위치를 저장한 배열을 통해 모든 시작지점을 enqueue하고 시작
    for (int i = 0; i < start_size; i++) {
        nd[start[i]].visited = 1;
        enqueue(&q, start[i]);
    }
    while(!is_empty(&q)) {
        int current_num = dequeue(&q);
        int move[4] = {current_num - m, current_num -1, current_num + 1, current_num + m};

        for (int i = 0; i < 4; i++) {
            int next = move[i];
            //범위 벗어나는 경우 방지
            if (next < 1 || next > nd_size) continue;
            //왼쪽 끝, 오른쪽 끝에서 각각 왼쪽, 오른쪽으로 이동 방지
            else if (current_num % m == 1 && i == 1) continue;
            else if (current_num % m == 0 && i == 2) continue;

            if (nd[next].visited == 0 && nd[next].tomato == 0) {
                nd[next].visited = 1;
                nd[next].tomato = 1;
                nd[next].depth = nd[current_num].depth + 1;
                enqueue(&q, next);
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    node* nd = calloc(n * m + 1, sizeof(node));
    int* tomato = malloc((n * m + 1) * sizeof(int));
    int tomato_cnt = 0;
    for (int i = 1; i <= n * m; i++) {
        int is_tomato;
        scanf("%d", &is_tomato);

        if (is_tomato == 0) continue;
        else if (is_tomato == 1) {
            nd[i].tomato = 1;
            tomato[tomato_cnt++] = i;
        }
        else if (is_tomato == -1) nd[i].tomato = -1;
        else return 1;
    }

    bfs(nd, tomato, tomato_cnt, m, n * m);

    int max = 0, check = 0;
    for (int i = 1; i <= n * m; i++) {
         if (nd[i].tomato == 0) {
            check = 1;
            break;
         }

         if (nd[i].tomato == 1 && nd[i].depth > max)
            max = nd[i].depth;
    }

    if (check == 0) printf("%d", max);
    else if (check == 1) printf("-1");
    else return 1;

    free(nd);
    free(tomato);

    return 0;
}