/* 백준 1463(1로 만들기)
n + 1 만큼의 배열을 생성한 후, (/2, /3, -1)번째 인덱스 중 가장 작은 값을 택하여 (해당 값 + 1)로 채워나가고, n번째 인덱스의 값을 출력한다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int small (int a, int b) {
    if (a <= b) return a;
    return b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n == 2) {   //2일 경우 1 출력 후 종료
        printf("1");
        return 0;
    }
    if (n == 3) {   //3일 경우 1 출력 후 종료
        printf("1");
        return 0;
    }

    int* calc = malloc((n + 1) * sizeof(int));

    calc[2] = 1;
    calc[3] = 1;    //n이 4 이상이므로 확정적으로 3까지 접근할 수 있다

    for (int i = 4; i <= n; i++) {
        calc[i] = calc[i - 1] + 1;  //기본적으로 -1번째 인덱스 값 + 1로 초기화
        if (i % 2 == 0) {   //2의 배수일 경우 /2번째 인덱스 값 + 1 과 비교하여 값 결정
            calc[i] = small(calc[i / 2] + 1, calc[i]);
        }
        if (i % 3 == 0) {   //3의 배수일 경우 /3번째 인덱스 값 + 1 과 비교하여 값 결정
            calc[i] = small(calc[i / 3] + 1, calc[i]);
        }
    }

    printf("%d", calc[n]);

    return 0;
}