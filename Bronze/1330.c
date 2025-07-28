/* 백준 1330(두 수 비교하기)
if문을 통해 두 값을 비교하여 조건에 맞게 출력한다 */

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

    if (a < b) printf("<");
    else if (a > b) printf(">");
    else printf("==");

    return 0;
}