/* 백준 1697(숨바꼭질)
bfs를 활용하여 각 값에 대해 n-1, n+1, n*2를 검사하고, 해당 검사까지의 깊이를 저장하여 타깃에 도달하면 깊이를 출력한다 */

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
    int depth;
    int visited;
} locate;

void bfs (locate* l, int start, int target, int l_size) {
    l[start].depth = 0; //초기값의 depth는 0으로 저장
    l[start].visited = 1;
    queue q;
    init_queue(&q, l_size);
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int current_num = dequeue(&q);
        if (current_num == target) {
            printf("%d\n", l[current_num].depth);   //값 발견 시 출력 후 종료
            break;
        }

        int moves[3] = {current_num - 1, current_num + 1, current_num * 2}; //도달할 수 있는 3가지 값 저장
        for (int i = 0; i < 3; i++) {
            int next = moves[i];
            if (next < 0 || next > 100000) continue;    //값이 범위를 넘어갈 경우 큐에 넣지 않고 continue
            if (l[next].visited == 0) {
                l[next].visited = 1;
                l[next].depth = l[current_num].depth + 1;   //이전 값의 깊이 + 1을 통해 깊이 저장
                enqueue(&q, next);
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int n, k;

    scanf("%d %d", &n, &k);

    if (n > k) {    //n이 k보다 클 때에는 -1을 반복하는 것이 최단 경로
        printf("%d\n", n - k);
        return 0;
    } else if (n == k) {    //n과 k가 같은 값일 경우 즉시 0 출력
        printf("0\n");
        return 0;
    }

    locate* l = calloc(100001, sizeof(locate));

    bfs(l, n, k, 100001);

    free(l);

    return 0;
}