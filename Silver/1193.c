/* 백준 1193(분수찾기)
분모와 분자 중 어떤 것이 증가해야하는 단계인지 vector변수를 통해 체크하며 x번째 분수 탐색 진행 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int x;
    scanf("%d", &x);
    //numer는 분자, denom은 분모, vector는 분모와 분자 중 어떤 값이 커져야하는 차례인지, 몇번 반복해야 하는지 나타내는 지표
    int numer = 1, denom = 1, vector = 1, cnt = 1;

    while(cnt < x) {
        if (vector % 2 == 1) {  //vector가 홀수일 때에는 분모가 증가하고, 분자가 감소하는 형태
            for (int i = 0; i < vector; i++) {
                denom++;
                if (numer > 1) numer--; //분모 증가 단계의 마지막에선 분자가 1로 유지된다
                if (++cnt == x) break;
            }
        } else {    //vector가 짝수일 때에는 분자가 증가하고, 분모가 감소하는 형태
            for (int i = 0; i < vector; i++) {
                numer++;
                if (denom > 1) denom--; //분자 증가 단계의 마지막에선 분모가 1로 유지된다
                if (++cnt == x) break;
            }
        }

        vector++;
    }

    printf("%d/%d", numer, denom);

    return 0;
}