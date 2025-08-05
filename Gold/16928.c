/* 백준 16928(뱀과 사다리 게임)
뱀과 사다리를 구조체로 선언하여 bfs 실행 시 시작값에 도달할 경우 뱀, 사다리의 도착값으로 변하게 하여 100으로 가는 최단 경로를 탐색한다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int move[6] = {1, 2, 3, 4, 5, 6};

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

typedef struct {    //사다리 구조체
    int start;
    int end;
} ladder;

typedef struct {    //뱀 구조체
    int start;
    int end;
} snake;

typedef struct {
    int visited;
    int depth;
} map;

void bfs(map* mp, int start, ladder* l, snake* s, int n, int m) {
    queue q;
    init_queue(&q, 101);
    mp[start].visited = 1;
    enqueue(&q, start);

    while(!is_empty(&q)) {
        int cur = dequeue(&q);
        int next_depth = mp[cur].depth + 1;
        for (int i = 0; i < 6; i++) {
            int next = cur + move[i];
            int in_l = 0;

            if (next > 100) continue;
            for (int j = 0; j < n; j++) {   //사다리의 시작 지점에 해당하는 값인지 검사
                if (next == l[j].start) {
                    mp[next].visited = 1;
                    mp[next].depth = next_depth;
                    next = l[j].end;    //해당할 경우 도착 지점 값으로 변경
                    in_l = 1;
                    break;
                }
            }
            if (in_l == 0) {
                for (int j = 0; j < m; j++) {   //뱀의 시작 지점에 해당하는 값인지 검사
                    if (next == s[j].start) {
                        mp[next].visited = 1;
                        mp[next].depth = next_depth;
                        next = s[j].end;    //해당할 경우 도착 지점 값으로 변경
                        break;
                    }
                }
            }

            if (mp[next].visited == 0) {
                enqueue(&q, next);
                mp[next].visited = 1;
                mp[next].depth = next_depth;
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    ladder* l = malloc(n * sizeof(ladder));
    snake* s = malloc(m * sizeof(snake));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l[i].start, &l[i].end);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s[i].start, &s[i].end);
    }

    map* mp = calloc(101, sizeof(map));

    bfs(mp, 1, l, s, n, m);

    printf("%d", mp[100].depth);    //100번째 인덱스의 depth를 출력하여 최단 경로 출력


    free(l);
    free(s);
    free(mp);

    return 0;
}