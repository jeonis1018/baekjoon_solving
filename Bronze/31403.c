/* 백준 31403(A + B - C)
js방식의 경우 b의 자릿수만큼 a에 곱셈을 한 후 연산 진행 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int num_res, js_res;

    num_res = a + b - c;

    int size_check = 10;
    for (int i = 0; i < 4; i++) {
        if (b / size_check == 0) {
            //나누었을 때 b가 0일 경우 해당 자릿수보다 b가 작다고 판단 후 a에 곱하여 연산 진행
            js_res = a * size_check + b - c;
            break;
        }

        size_check *= 10;
    }

    printf("%d\n%d", num_res, js_res);

    return 0;
}