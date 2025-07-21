/* 백준 1259(팰린드롬수)
문자열 형태로 입력받은 후, 앞과 뒤를 가리키는 포인터 2개로 대칭인지 검사하여 펠린드롬수인지 판별 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    while(1) {
        char* num = malloc(1 * sizeof(char));
        int size = 1;
        int len = 0;
        int ch;

        while((ch = getchar()) != '\n' && ch != EOF) {  //줄바꿈문자가 입력되기 전까지 반복
            num[len++] = ch;

            if (len + 1 >= size) {  //size가 부족해질 경우 2를 곱한 후 재할당
                size *= 2;
                num = realloc(num, size * sizeof(char));
            }
        }
        num[len] = '\0';    //문자열 마지막에 널문자 삽입

        if (num[0] == '0') return 0;
        else if (len == 1) printf("yes\n");
        else {
            int start = 0, end = len - 1;   //문자열의 맨 앞과 뒤를 가리키는 포인터
            int check = 1;

            while (start < end) {
                if (num[start] == num[end]) {
                    //start와 end를 증가, 감소 시켜나가면서 전체 구간 비교
                    start++;
                    end--;
                } else {
                    check = 0;
                    break;
                }
            }

            if (check == 1) printf("yes\n");
            else if (check == 0) printf("no\n");
        }
    }
}