/* 백준 1654(랜선 자르기)
이분탐색을 통해 원하는 수의 랜선을 만드는 최대 길이 탐색 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

long long calc (long long value, int* arr, int size) {
    long long cnt = 0;
    for (int i = 0; i < size; i++) {
        cnt += arr[i] / value;
    }

    return cnt;
}

int binary_search (int max_lan, int* arr, int size, int target) {
    long long left = 1, right = max_lan, mid;
    int result = 0;

    while (left <= right) {
        mid = (left + right) / 2;

        if (calc(mid, arr, size) < target) right = mid - 1;
        else {
            result = mid;   //target보다 랜선의 개수가 많을 경우 result에 해당 값을 저장한 후 더 큰 수 탐색
            left = mid + 1;
        }
    }

    return result;
}

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);

    int* leng;
    leng = malloc(k * sizeof(int));

    int max = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &leng[i]);
        if (max < leng[i])
            max = leng[i];  //모든 랜선 중 가장 긴 랜선까지의 길이가 가능한 길이의 최댓값이므로 저장하여 이분탐색에 활용
    }

    int result = binary_search(max, leng, k, n);

    printf("%d\n", result);

    return 0;
}