/* 백준 1436(영화감독 숌)
수를 1씩 늘려가며 666이 포함되어 있는지 검사하고, 666이 포함되어 있는 경우를 카운트해나가며 결과값을 출력한다 */

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

    int cnt = 0;
    int num = 666;
    while (cnt != n) {
        int tmp = num;

        while (tmp > 100) {
            if (tmp % 1000 == 666) {
                cnt++;
                break;
            }

            tmp /= 10;
        }

        if (cnt != n) num++;
    }

    printf("%d", num);

    return 0;
}