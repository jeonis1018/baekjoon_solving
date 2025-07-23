/* 백준 5525(IOIOI)
제한이 1,000,000으로 매우 크기 때문에 문자열을 저장하서 탐색하지 않고, 한 알파벳씩 입력받으며 탐색한다 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int cnt = 0;
    //before_i : 이전 입력이 I, O 중 무엇이었는지 나타내는 변수, start : IOI 반복을 카운트 중인 상태인지 나타내는 변수, tmp : 부분적인 IOI 반복을 카운트해주는 변수
    int before_i = 0, start = 0, tmp = 0; 
    for (int i = 0; i < m; i++) {
        char word;
        scanf(" %c", &word);    //한 알파벳씩 입력받기

        if (word == 'I') {
            if (before_i == 0 && start == 0) start = 1; //이전 입력이 O였고, 반복을 카운트 중이지 않을 경우 카운트 시작
            else if (before_i == 0 && start == 1) tmp++;    //이전 입력이 O였고, 반복을 카운트 중이었을 경우 카운트 + 1
            else if (before_i == 1 && start == 1) {     //이전 입력이 I였고, 반복을 카운트 중이었을 경우 카운트를 종료하고 cnt에 값 추가 
                if (tmp >= n) {     //IOI반복이 Pn보다 작을 경우 카운트를 추가할 필요 없음
                    tmp += 1 - n;   //IOI 반복에 1을 더한 후, n을 빼서 Pn이 몇개 포함되어있는지 카운트
                    cnt += tmp;
                }

                tmp = 0;
            }

            before_i = 1;
        } else if (word == 'O') {
            if (before_i == 0)  {   //이전 입력이 O였을 경우, cnt값을 추가하고, 반복카운트 종료
                if (tmp >= n) {
                    tmp += 1 - n;
                    cnt += tmp;
                }

                tmp = 0;
                start = 0;
            }

            before_i = 0;
        } else return 1;
    }

    //반복 카운트가 진행되는 중에 종료되었을 경우를 대비해서 cnt에 값 추가하는 코드 실행
    if (tmp >= n) {
        tmp += 1 - n;
        cnt += tmp;
    }

    printf("%d", cnt);

    return 0;
}