/* 백준 7569(토마토)
3차원 배열 형태로 창고를 구현하고, 다중 시작점 bfs를 통해 탐색하여 결과 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

//x축, y축, z축 이동을 배열로 구현
int dx[6] = {0, 0, 0, 0, 1, -1};    
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

typedef int* element;

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
    for (int i = 0; i < q->size; i++) {
        q->data[i] = malloc(3 * sizeof(int));
    }
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
        return NULL;
    }
    return q->data[++q->front];
}

void free_queue(queue* q) {
    free(q->data);
}

typedef struct {
    int visited;
    int depth;
} node;

void bfs(node*** farm, queue* q, int m, int n, int h) {
    while(!is_empty(q)) {
        int* cur = dequeue(q);
        int z = cur[0], y = cur[1], x = cur[2];
        //6번의 반복으로 이동할 수 있는 인접한 6개의 노드 검사
        for (int i = 0; i < 6; i++) {
            int next_z = z + dz[i];
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            //범위 밖으로 벗어나는 경우 예외처리
            if (next_z < 0 || next_z > h - 1 || next_y < 0 || next_y > n - 1 || next_x < 0 || next_x > m - 1) continue;
            //인접한 노드 중 방문한 적 없는 노드만 방문
            else if (farm[next_z][next_y][next_x].visited == 0) {
                int* next = malloc(3 * sizeof(int));
                next[0] = next_z;
                next[1] = next_y;
                next[2] = next_x;
                enqueue(q, next);
                farm[next[0]][next[1]][next[2]].visited = 1;
                farm[next[0]][next[1]][next[2]].depth = farm[z][y][x].depth + 1;
            }
        }

        free(cur);
    }
}

int main(void) {
    int m, n, h;
    scanf("%d %d %d", &m, &n, &h);

    node*** farm;
    //3차원 배열 형태로 구현
    farm = malloc(h * sizeof(node**));
    for (int i = 0; i < h; i++) {
        farm[i] = malloc(n * sizeof(node*));
        for (int j = 0; j < n; j++) {
            farm[i][j] = calloc(m, sizeof(node));
        }
    }

    queue q;
    init_queue(&q, m * n * h);
    int cnt = 0;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int num;
                int* loc = malloc(3 * sizeof(int));
                loc[0] = k;
                loc[1] = i;
                loc[2] = j;
                scanf("%d", &num);

                if (num == 0) {
                    free(loc);
                    continue;
                }
                else if (num == 1) {
                    farm[k][i][j].visited = 1;
                    farm[k][i][j].depth = 0;
                    enqueue(&q, loc);   //다중 시작점 bfs 구현을 위해서 1이 나올 때마다 enqueue
                    cnt++;
                }
                else if (num == -1) farm[k][i][j].visited = -1;
                else {
                    free(loc);
                    return 1;
                }
            }
        }
    }

    bfs(farm, &q, m, n, h);

    free_queue(&q);

    int max = -1;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //탐색 불가능한 지점이 있었는지 검사
                if (farm[k][i][j].visited == 0) {
                    printf("-1");
                    return 0;
                } else if (farm[k][i][j].depth > max)   //가장 큰 depth값 탐색
                    max = farm[k][i][j].depth;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            free(farm[i][j]);
        }
        free(farm[i]);
    }
    free(farm);

    printf("%d", max);

    return 0;
}