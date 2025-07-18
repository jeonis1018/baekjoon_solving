/* 백준 1110(더하기 사이클)
10으로 나누기, 나머지 계산을 통해 일의 자릿수, 십의 자릿수로 나누어 연산을 반복해나간다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int n;

    scanf("%d", &n);

    int n1, n2;
    int tmp = n;
    int cnt = 0;

    while(1) {
        cnt++;
        if (tmp < 10) n1 = 0, n2 = tmp;
        else n1 = tmp / 10, n2 = tmp % 10;

        tmp = n2 * 10 + (n1 + n2) % 10;
        if (tmp == n) break;
    }

    printf("%d\n", cnt);

    return 0;
}