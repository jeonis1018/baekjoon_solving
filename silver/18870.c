#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int compare (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int binary_search(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main(void) {
    int n;
    int *num, *tmp;

    scanf("%d", &n);

    if (n < 1) return 1;

    num = malloc(n * sizeof(int));
    tmp = malloc(n * sizeof(int));
    if (!num || !tmp) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        tmp[i] = num[i];
    }

    qsort(tmp, n, sizeof(int), compare);

    int* unique = malloc(n * sizeof(int));

    int idx = 1;
    unique[0] = tmp[0];
    for (int i = 1; i < n; i++) {
        if (tmp[i] != tmp[i - 1])
            unique[idx++] = tmp[i];
    }

    for (int i = 0; i < n; i++) {
        int modified = binary_search(unique, idx, num[i]);
        printf("%d ", modified);
    }

    free(num);
    free(tmp);

    return 0;
}