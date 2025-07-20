/* 백준 2178(미로 탐색)
{-m, -1, +1, +m}의 4가지 움직임을 정의하여 일차원 배열에서의 bfs 사용으로 경로 탐색 */

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
    int is_road;
    int visited;
} target;

void bfs (target* t, int start, int m, int t_size) {
    t[start].visited = 1;
    t[start].depth = 1;
    queue q;
    init_queue(&q, t_size);
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int current_num = dequeue(&q);
        if (current_num == t_size) {
            printf("%d\n", t[current_num].depth);
            break;
        }
        // {-m(위로 이동), -1(왼쪽으로 이동), +1(오른쪽으로 이동), +m(아래로 이동)}
        int move[4] = {current_num - m, current_num - 1, current_num + 1, current_num + m};
        for (int i = 0; i < 4; i++) {
            int next = move[i];
            if (move[i] < 1 || move[i] > t_size) continue;  //범위를 벗어나는 움직임일 경우 예외처리
            if ((current_num - 1) % m == 0 && i == 1) continue; //왼쪽 끝 위치일 경우 왼쪽 이동 예외처리
            if (current_num % m == 0 && i == 2) continue;   //오른쪽 끝 위치일 경우 오른쪽 이동 예외처리
            //방문하지 않았고, 이동할 수 있는 경로일 경우 큐에 추가
            if (t[next].visited == 0 && t[next].is_road == 1) {
                t[next].visited = 1;
                t[next].depth = t[current_num].depth + 1;
                enqueue(&q, next);
            }
        }
    }

    free_queue(&q);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int maze_size = n * m;
    target* maze = calloc(maze_size + 1, sizeof(target));

    for (int i = 1; i <= maze_size; i++) {
        char num;
        scanf(" %c", &num); //" %c" 사용으로 숫자 하나씩 입력

        if (num == '0') continue;
        else if (num == '1') maze[i].is_road = 1;
        else return 1;  //값이 0이나 1이 아닐 경우 예외처리
    }

    bfs(maze, 1, m, maze_size);

    free(maze);

    return 0;
}