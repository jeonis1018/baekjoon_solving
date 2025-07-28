/* 백준 1546(평균)
점수들을 입력받은 후, 모든 점수를 최댓값에 대해 /m * 100 연산을 시행한 후, 평균을 구해서 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    double n;
    scanf("%lf", &n);

    double* score = malloc(n * sizeof(double));

    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &score[i]);

        if (max < score[i]) max = score[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        score[i] = score[i] / max * 100;
        sum += score[i];
    }

    double avg = sum / n;

    printf("%.2lf", avg);

    return 0;
}