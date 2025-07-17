/* 백준 1931(회의실 배정)
회의 끝 시간(끝시간이 같으면 시작 시간 기준)을 기준으로 오름차순 배열을 한 후, 포함시킬 수 있는 회의의 수를 카운트 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int start;  //회의 시작 시간
    int end;    //회의 끝 시간
} pair;

int compare (const void* a, const void* b) {
    const pair* p1 = (const pair*)a;
    const pair* p2 = (const pair*)b;

    //끝 시간 기준 오름차순, 끝시간이 같을 경우 시작 시간 기준 오름차순
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
            time = p[i].end;    //현재 시간을 갱신해나가며 선택 가능한 회의 확인
        }
    }

    printf("%d", cnt);

    return 0;
}