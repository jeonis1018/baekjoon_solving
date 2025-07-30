/* 백준 27323(직사각형)
정수 a, b를 입력받아 두 수의 곱을 출력한다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", a * b);

    return 0;
}