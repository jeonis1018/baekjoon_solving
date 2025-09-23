/* 백준 1920(수 찾기)
원래의 수열을 오름차순으로 정렬한 후, 비교 수열을 이진 탐색을 통해 하나씩 탐색한다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int compare (const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    else return 0;
}

bool binary_search (int* origin, int o_size, int target) {  //이진탐색
    int left = 0, right = o_size - 1, mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if (origin[mid] == target) return true;
        else if (origin[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}

int main(void) {
    int n, m;
    int *origin, *comp;

    scanf("%d", &n);
    origin = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &origin[i]);
    }

    scanf("%d", &m);
    comp = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &comp[i]);
    }

    qsort(origin, n, sizeof(int), compare); //오름차순 정렬

    for (int i = 0; i < m; i++) {
        if (binary_search(origin, n, comp[i])) printf("1\n");
        else printf("0\n");
    }

    return 0;
}