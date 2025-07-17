/* 백준 1008(A/B)
두 수 a, b를 입력받아서 a / b를 소수점 아래 9자리까지 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    double a, b;    //정확도가 떨어지는 것을 방지하기 위해서 float이 아닌 double을 사용

    scanf("%lf %lf", &a, &b);
    printf("%.9lf", a / b);

    return 0;
}