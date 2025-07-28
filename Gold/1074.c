/* 백준 1074(Z)
구역을 4등분하여 (r, c)가 어디에 위치하는데 찾아내고, 해당 구역에 대한 재귀 호출을 통해 탐색 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int power (int a, int b) {  //a ^ b 함수
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

int z_func(int n, int start_r, int start_c, int r, int c) {
    int res = 0;    //0에서부터 결과값 카운팅 시작

    if (n == 1) {   //n이 1인 경우에는 재귀 호출을 하지 않고, (r, c)를 탐색하여 res값 반환
        if (start_r == r && start_c == c) {
            return res;
        } else if (start_r == r && start_c + 1 == c) {
            res++;
            return res;
        } else if (start_r + 1 == r && start_c == c) {
            res += 2;
            return res;
        } else if (start_r + 1 == r && start_c + 1== c) {
            res += 3;
            return res;
        }
    } else {
        if (r < start_r + power(2, n - 1) && c < start_c + power(2, n - 1)) {   //구역을 4등분 하였을 때, 왼쪽 위에 있는 경우
            res += z_func(n - 1, start_r, start_c, r, c);
        } else if (r < start_r + power(2, n - 1)) {   //구역을 4등분 하였을 때, 오른쪽 위에 있는 경우
            res += power(2, 2 * n - 2);     //이전 구역들의 크기만큼 더하기
            res += z_func(n - 1, start_r, start_c + power(2, n - 1), r, c);
        } else if (c < start_c + power(2, n - 1)) {   //구역을 4등분 하였을 때, 왼쪽 아래에 있는 경우
            res += 2 * power(2, 2 * n - 2);     //이전 구역들의 크기만큼 더하기
            res += z_func(n - 1, start_r + power(2, n - 1), start_c, r, c);
        } else {   //구역을 4등분 하였을 때, 오른쪽 아래에 있는 경우
            res += 3 * power(2, 2 * n - 2);     //이전 구역들의 크기만큼 더하기
            res += z_func(n - 1, start_r + power(2, n - 1), start_c + power(2, n - 1), r, c);
        }
    }

    return res;
}

int main(void) {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);

    printf("%d", z_func(n, 0, 0, r, c));

    return 0;
}