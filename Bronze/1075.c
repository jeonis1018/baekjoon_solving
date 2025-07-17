/* 백준 1075(나누기)
입력받은 값에서 100으로 나눈 나머지를 뺀 후, 1씩 더해가며 나누어 떨어지는 지점을 확인 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    int n, f;
    int res;

    scanf("%d %d", &n, &f);

    n = n - (n % 100);

    for (int i = 0; i < 100; i++) {
        if (n % f == 0) {
            res = i;
            break;
        }

        n++;
    }

    if (res >= 0 && res <= 9) {
        printf("0%d\n", res);
    } else {
        printf("%d\n", res);
    }

    return 0;
}