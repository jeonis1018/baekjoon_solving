/* 백준 1001(A-B)
두 값을 입력 받아서 먼저 입력된 수에서 나중에 입력된 수를 뺀 값을 출력*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d", a - b);

    return 0;
}