/* 백준 10026(적록색약)
R, G, B로 나뉘었을 경우를 기준으로 bfs를 한번 실행하고, R과 G를 같게 만든 후 다시한번 bfs 실행 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int y, x;
} point;

typedef point element;

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
        return (point){-1, -1};
    }
    return q->data[++q->front];
}

void free_queue(queue* q) {
    free(q->data);
}

typedef struct {
    int color;
    int visited;
} node;

void bfs (node** nd, int r, int c, int n) {
    queue q;
    init_queue(&q, n * n);
    nd[r][c].visited = 1;
    int bfs_color = nd[r][c].color; //해당 bfs에서는 어떤 색만 탐색해야 하는지 확인하기 위해 저장
    enqueue(&q, (point){r, c});

    while(!is_empty(&q)) {
        point cur = dequeue(&q);
        for (int i = 0; i < 4; i++) {
            int y = cur.y + dy[i];
            int x = cur.x + dx[i];

            if (x < 0 || x > n - 1 || y < 0 || y > n - 1) continue;
            else if (nd[y][x].visited == 0 && nd[y][x].color == bfs_color) {
                enqueue(&q, (point){y, x});
                nd[y][x].visited = 1;
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int n;
    scanf("%d", &n);

    node** nd;
    nd = malloc(n * sizeof(node*));
    for (int i = 0; i < n; i++) {
        nd[i] = calloc(n, sizeof(node));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char color;
            scanf(" %c", &color);

            if (color == 'R') {
                nd[i][j].color = 1;
            } else if (color == 'G') {
                nd[i][j].color = 2;
            } else if (color == 'B') {
                nd[i][j].color = 3;
            } else return 1;
        }
    }

    int origin_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nd[i][j].visited == 0) {
                bfs(nd, i, j, n);
                origin_cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nd[i][j].visited = 0;   //bfs를 다시 실행하기 위해 visited값 초기화
            if (nd[i][j].color == 1)    //R로 입력받은 값들을 전부 G로 간주
                nd[i][j].color = 2;
        }
    }

    int rg_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nd[i][j].visited == 0) {    //node를 수정한 상태로 다시 bfs 실행
                bfs(nd, i, j, n);
                rg_cnt++;
            }
        }
    }

    printf("%d %d", origin_cnt, rg_cnt);

    for (int i = 0; i < n; i++) {
        free(nd[i]);
    }
    free(nd);

    return 0;
}