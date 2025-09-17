/* 백준 1676(팩토리얼 0의 개수)
0의 개수가 늘어나기 위해서는 소인수에 2, 5가 하나씩 늘어나야하는 점을 이용하여 코드 구성 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int div_five(int num) { //약수에 5가 몇개 있는지 확인
    if (num == 0) return 0;

    int cnt = 0;
    while (num % 5 == 0) {
        cnt++;
        num /= 5;
    }

    return cnt;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* zero;
    zero = malloc((n + 1) * sizeof(int));

    zero[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 5 != 0) zero[i] = zero[i - (i % 5)];    //5의 배수가 아닌 경우에는 이전 5의 배수와 같은 0의 개수를 가질 수 밖에 없다
        else {
            zero[i] = zero[i - 5] + div_five(i);    //5의 배수일 경우 이전 5의 배수에 자식의 5의 약수의 개수를 더한다
        }
    }

    printf("%d\n", zero[n]);

    return 0;
}