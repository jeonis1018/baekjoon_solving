/* 백준 18870(좌표 압축)
입력받은 배열을 정렬 및 중복 제거된 배열로 변형한 뒤, 해당 값이 위치한 인덱스 값으로 변형하여 좌표 압축 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int compare (const void* a, const void* b) {    //qsort 오름차순 정렬을 위한 compare 함수
    return *(int*)a - *(int*)b;
}

int binary_search(int* arr, int size, int target) {     //이진탐색
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

    qsort(tmp, n, sizeof(int), compare);    //tmp배열을 오름차순 정렬

    int* unique = malloc(n * sizeof(int));

    int idx = 1;
    unique[0] = tmp[0];
    for (int i = 1; i < n; i++) {   //정렬된 tmp배열에서 중복된 수를 제외시킨 unique배열 생성
        if (tmp[i] != tmp[i - 1])
            unique[idx++] = tmp[i];
    }

    for (int i = 0; i < n; i++) {
        int modified = binary_search(unique, idx, num[i]);  //이진 탐색으로 해당 값을 찾은 후, 해당 값의 인덱스 번호로 변경
        printf("%d ", modified);
    }

    free(num);
    free(tmp);

    return 0;
}