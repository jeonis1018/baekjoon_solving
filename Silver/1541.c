/* 백준 1541(잃어버린 괄호)
입력받은 식에 대해 '-' 등장 이후에는 전부 빼기, 이전에는 전부 더하기로 계산 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char arr[51];
    fgets(arr, 51, stdin);

    int len = strlen(arr);

    int tmp = 0, minus = 0, res = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == '\n') break;  //줄바꿈 문자일 경우 예외처리
        if (arr[i] == '+') {    //'+'일 경우 이전에 '-'가 있었는지 체크하여 계산
            if (minus == 0) res += tmp;
            else if (minus == 1) res -= tmp;
            tmp = 0;
        }
        else if (arr[i] == '-') {   //'-'일 경우 이전에 '-'가 있었는지 체크하여 계산 후, '-' 등장 표시
            if (minus == 0) res += tmp;
            else if (minus == 1) res -= tmp;
            tmp = 0;
            minus = 1;
        } else {    //수가 등장했을 경우 tmp * 10 후, 등장한 값 덧셈
            tmp *= 10;
            tmp += arr[i] - '0';
        }
    }

    //식이 수로 끝나기 때문에 마지막으로 계산 후 출력
    if (minus == 0) res += tmp;
    else if (minus == 1) res -= tmp;

    printf("%d", res);

    return 0;
}