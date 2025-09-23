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
    int* tree;
    int rear;
} heap;

typedef struct node {
    int key;
    int cnt;
    node* next;
} node;

typedef struct {
    int size;
    node** table;
} deletion_map;

void init_map (deletion_map d_map) {
    d_map.size = 131070;
    d_map.table = calloc(d_map.size, sizeof(node*));
}

void insert_map (deletion_map d_map, int value) {
    int index = (value % d_map.size + d_map.size) % d_map.size;
    node nd;
    nd.key = value;
}

void init_heap (heap h, int size) {
    h.tree = malloc((size + 1) * sizeof(int));
    h.tree[0] = 0;
    h.rear = 0;
}

void insert_min (heap min, int value) {

}

void insert_max (heap max, int value) {

}

int delete_min (heap min, deletion_map map) {

}

int delete_max (heap max, deletion_map map) {

}

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int q;
        scanf("%d", &q);

        heap min_heap, max_heap;
        init_heap(min_heap, q);
        init_heap(max_heap, q);

        deletion_map d_map;
        init_map(d_map);

        for (int j = 0; j < q; j++) {
            char func; int num;
            scanf(" %c %d", &func, &num);

            if (func == 'I') {
                insert_min(min_heap, num);
                insert_max(max_heap, num);

            } else if (func == 'D') {
                if (num == 1) {

                } else if (num == -1) {

                } else return 1;
            } else return 1;
        }
    }

    return 0;
}