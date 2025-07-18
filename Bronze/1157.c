/* 백준 1157(단어 공부)
대문자에서 'A'를 빼면 0~25, 소문자에서 'a'를 빼면 0~25가 나온다는 점을 이용해서 대/소문자 구분없이 카운팅 후 제일 많이 나온 알파벳을 출력 */

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

    size_t len = strlen(sentence);
    int* alpha = calloc(26, sizeof(int));

    for (int i = 0; i < len; i++) {
        //대문자일 경우 'A'를 뺐을 때 나온 값을 인덱스로 해서 alpha[index]++
        if (sentence[i] - 'A' >= 0 && sentence[i] - 'A' <= 25) {
            alpha[sentence[i] - 'A']++;
        //소문자일 경우 'a'를 뺐을 때 나온 값을 인덱스로 해서 alpha[index]++
        } else if (sentence[i] - 'a' >= 0 && sentence[i] - 'a' <= 25) {
            alpha[sentence[i] - 'a']++;
        } else break;
    }

    int max = -1, max_idx;
    int check = 0;
    //alpha[]에서 최댓값 탐색
    for (int i = 0; i < 26; i++) {
        if (alpha[i] > max) {
            max = alpha[i];
            max_idx = i;
            check = 0;
            continue;
        } else if (alpha[i] == max) {
            check = 1;
        }
    }

    //최댓값이 여러개일 경우 ? 출력
    if (check == 1) {
        printf("?\n");
        return 0;
    } else {
        printf("%c\n", max_idx + 'A');  //최댓값이 하나일 경우 해당 인덱스에 'A'를 더해서 대문자로 출력
    }

    return 0;
}