/* 백준 1152(단어의 개수)
공백이 연속해서 나오지 않는다는 점을 이용하여, 공백으로 시작하는 경우, 공백 하나만 입력되는 경우, 공백으로 끝나는 경우를 예외처리 하여 공백 개수 카운트 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char sentence[1000001];

    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        size_t len = strlen(sentence);
        //fgets로 입력받았으므로 줄바꿈문자를 널문자로 변환하여 예외처리
        if (len > 0 && sentence[len - 1] == '\n')
            sentence[len - 1] = '\0';
    }

    int idx = 0;
    //공백으로 시작하는 경우 예외처리
    if (sentence[0] == ' ') {
        if (sentence[1] == '\0') {  //공백만 입력되는 경우 예외처리
            printf("0\n");
            return 0;
        }

        idx++;
    }

    int cnt = 1;
    size_t len = strlen(sentence);
    for (int i = idx; i < len; i++) {
        if (sentence[i] != ' ') continue;
        else {
            if (i + 1 != len) {     //공백으로 끝나는 경우 예외처리
                cnt++;
            } else break;
        }
    }

    printf("%d\n", cnt);

    return 0;
}