/* 백준 7662(이중 우선순위 큐)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int* heap;
    int rear;
} db_queue;

void init_queue (db_queue* dq, int size) {
    dq->heap = malloc(size * sizeof(int));
    dq->rear = 0;
    dq->heap[0] = 0;
}

void min_up () {

}

void max_up () {

}

void min_down () {

}

void max_down () {
    
}

void insert (db_queue* dq, int value) {
    dq->rear++;
    dq->heap[dq->rear] = value;
    int parent = dq->rear / 2;
    int grandparent = dq->rear / 4;
    if ((int)floor(log2(dq->rear)) % 2 == 0) {  //min 레벨에 삽입되었을 경우
        if (parent > 0) {
            if (value > dq->heap[parent]) {
                dq->heap[dq->rear] = dq->heap[parent];
                grandparent /= 2;
                while (grandparent > 0) {
                    max_up();
                }
            } else {
                while (grandparent > 0) {
                    min_up();
                }
            }
        }
    } else {    //max레벨에 삽입되었을 경우
        if (parent > 0) {
            if (value < dq->heap[parent]) {
                dq->heap[dq->rear] = dq->heap[parent];
                grandparent /= 2;
                while (grandparent > 0) {
                    min_up();
                }
            } else {
                while (grandparent > 0) {
                    max_up();
                }
            }
        }
    }
}

int delete_max (db_queue* dq) {
     if (dq->rear <= 0) return 0;
     else if (dq->rear == 1 || dq->rear == 2) return dq->heap[dq->rear--];
     else {
        if (dq->heap[2] >= dq->heap[3]) {
            int result = dq->heap[2];
            dq->heap[2] = dq->heap[dq->rear--];
            if (dq->rear )
        } else {
            int result = dq->heap[3];
            dq->heap[3] = dq->heap[dq->rear--];
        }
     }

}

int delete_min(db_queue* dq) {

}

void free_queue (db_queue* dq) {
    free(dq->heap);
}

int main(void) {
    int t;
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++) {
        int k;
        scanf("%d", &k);

        db_queue dq;
        init_queue(&dq, k);

        for (int i = 0; i < k; i++) {
            char func;
            int value;
            scanf("%c %d", &func, &value);

            if (func == 'I') {
                insert(&dq, value);
            } else if (func == 'D') {
                if (value == 1) {
                    delete_max(&dq);
                } else if (value == -1) {
                    delete_min(&dq);
                } else return 1;
            } else return 1;
        }

        if (dq.rear <= 0) printf("EMPTY\n");
        else {
            if (dq.rear == 1) {
                int n = delete_min(&dq);
                printf("%d %d", n, n);
            }
            else printf("%d %d\n", delete_min(&dq), delete_max(&dq));
        }

        free_queue(&dq);
    }

    return 0;
}