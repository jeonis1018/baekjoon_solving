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
    int cur;
} db_queue;

void init_queue (db_queue* dq, int size) {
    dq->heap = malloc(size * sizeof(int));
    dq->cur = 0;
    dq->heap[0] = 0;
}

void insert (db_queue* dq, int value) {
    if (dq->cur == 0) {
        dq->heap[++dq->cur] = value;
        return;
    }

    if (((dq->cur + 1) / 2) % 2 == 1) {

    } else {
        
    }
}

int delete_max (db_queue* dq) {

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
                if (dq.cur <= 0) continue;
                if (value == 1) {
                    delete_max(&dq);
                } else if (value == -1) {
                    delete_min(&dq);
                } else return 1;
            } else return 1;
        }

        if (dq.cur <= 0) printf("EMPTY\n");
        else {
            if (dq.cur == 1) printf("%d %d\n", dq.heap[1], dq.heap[1]);
            else printf("%d %d\n", dq.heap[1], dq.heap[2]);
        }

        free_queue(&dq);
    }

    return 0;
}