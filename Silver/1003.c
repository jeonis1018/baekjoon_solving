/* 백준 1003(피보나치 함수)
수가 1 증가할때마다 0의 개수는 이전 수의 1의 개수가 되고, 1의 개수는 이전 0의 개수가 더해진다는 특성 활용 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int t;

    scanf("%d", &t);

    int n;
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        int zero = 0, one = 1;

        if (n == 0) {
            printf("1 0\n");
            continue;
        } else if (n == 1) {
            printf("0 1\n");
            continue;
        } else {
            for (int j = 1; j < n; j++) {   //이전 수의 결과값을 활용하여 다음 결과값 도출
                int tmp = zero;
                zero = one;
                one += tmp;
            }
        }

        printf("%d %d\n", zero, one);
    }

    return 0;
}