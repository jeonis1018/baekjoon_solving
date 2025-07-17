/*백준 30804(과일 탕후루)
슬라이딩 윈도우(two pointer)를 통해서 두 종류 이하의 수를 가지는 연속된 구간 중 가장 긴 구간의 길이를 탐색 */

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

    int* cnt = malloc(10 * sizeof(int));    //입력되는 수의 범위가 1~9이므로 해당 수들의 수를 저장할 배열 생성
    for (int i = 0; i < 10; i++)
        cnt[i] = 0;

    int* fruit = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &fruit[i]);

    int max = 0;
    int type = 0;   //현재 구간에 몇 종류의 수가 있는지 담는 변수
    int left = 0;   //구간의 왼쪽 끝을 가리킬 포인터 left
    for (int right = 0; right < n; right++) {   //구간의 오른쪽 끝을 가리킬 포인터 right
        //오른쪽 끝 수가 현재 구간에 없던 숫자일 경우, 종류 1 추가
        if (cnt[fruit[right]] == 0)
            type++;
        cnt[fruit[right]]++;

        //구간의 종류를 2 이하로 만들기 위해서 왼쪽 끝을 오른쪽으로 이동
        while (type > 2) {
            cnt[fruit[left]]--;
            if (cnt[fruit[left]] == 0)
                type--;
            left++;
        }

        if (max < right - left + 1)
            max = right - left + 1;
    }

    printf("%d", max);

    return 0;
}