/* 백준 1931(회의실 배정)
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} pair;

int compare (const void* a, const void* b) {
    const pair* p1 = (const pair*)a;
    const pair* p2 = (const pair*)b;

    if (p1->end < p2->end) return -1;
    else if (p1-> end > p2->end) return 1;
    else if (p1->end == p2->end) {
        if (p1->start < p2->start) return -1;
        else if (p1->start > p2->start) return 1;
        else return 0;
    }
}

int main(void) {
    int t;

    scanf("%d", &t);

    pair* p = malloc(t * sizeof(pair));

    for (int i = 0; i < t; i++) {
        scanf("%d %d", &p[i].start, &p[i].end);
    }

    qsort(p, t, sizeof(pair), compare);

    int time = p[0].end;
    int cnt = 1;

    for (int i = 1; i < t; i++) {
        if (p[i].start >= time) {
            cnt++;
            time = p[i].end;
        }
    }

    printf("%d", cnt);

    return 0;
}