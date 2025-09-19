/* 백준 1712(손익분기점)
c - b가 개당 수익이므로 a를 c - b로 나눈 후 1을 더한 값이 손익분기점이 된다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    unsigned int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (b >= c) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", a / (c - b) + 1);

    return 0;
}