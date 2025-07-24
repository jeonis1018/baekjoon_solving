/* 백준 11286(절댓값 힙)
기존 최소힙의 삽입, 삭제 함수에서 절댓값을 기반으로 검사하는 내용을 추가하여 구현 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int* data;
    int size;
} heap;

void init_heap (heap* h, int size) {
    h->data = calloc(size + 1, sizeof(int));
    h->size = 0;
}

void insert (heap* h, int value) {
    int i = ++h->size;
    int tmp = i / 2;

    while (i != 1) {
        if (abs(value) < abs(h->data[tmp])) {   //절댓값 비교
            h->data[i] = h->data[tmp];
            i = tmp;
            tmp /= 2;
        } else if (abs(value) == abs(h->data[tmp])) {
            if (value < h->data[tmp]) {   //절댓값이 같은 경우에는 실제값으로 비교
                h->data[i] = h->data[tmp];
                i = tmp;
                tmp /= 2;
            } else break;
        } else break;
    }

    h->data[i] = value;
}

int delete (heap* h) {
    if (h->size < 1) return 0;
    int item = h->data[1];
    int tmp = h->data[h->size--];

    int parent = 1, child = 2;

    while (child <= h->size) {
        if (child < h->size) {  //절댓값 기반 비교, 절대값이 같을 때에는 실제값 비교까지 진행하여 child, child + 1 비교
            if (abs(h->data[child]) > abs(h->data[child + 1]) || (abs(h->data[child]) == abs(h->data[child + 1]) && h->data[child] > h->data[child + 1]))
                child++;
        }
        if (abs(tmp) > abs(h->data[child])) {   //절댓값 비교
            h->data[parent] = h->data[child];
            parent = child;
            child *= 2;
        } else if (abs(tmp) == abs(h->data[child])) {
            if (tmp > h->data[child]) { //절댓값이 같은 경우에는 실제값 비교
                h->data[parent] = h->data[child];
                parent = child;
                child *= 2;
            } else break;
        } else break;
    }

    h->data[parent] = tmp;
    return item;
}

int main(void) {
    int n;
    scanf("%d", &n);

    heap h;
    init_heap(&h, n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        if (x == 0) printf("%d\n", delete(&h));
        else insert(&h, x);
    }

    return 0;
}