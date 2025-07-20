/* 백준 1181(단어 정렬)
길이를 비교한 후, 길이가 같을 때 사전 순으로 비교하는 compare 함수로 정렬, 두 문자열이 같은지 비교하는 cmp 함수로 같은 문자열을 소거하여 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int compare (const void* a, const void* b) {
    const char *s1 = *(const char**)a, *s2 = *(const char**)b;
    if (strlen(s1) > strlen(s2)) return 1;  //b 문자열이 더 짧으면 1 출력
    else if (strlen(s1) < strlen(s2)) return -1;    //a 문자열이 더 짧으면 -1 출력
    else {
        //문자열의 앞에서부터 검사하여 다른 알파벳을 가진 값이 나오는 순간 s1에서 s2를 뺀 값 출력 (s1의 알파벳이 사전순 상 앞이라면 음수, 반대라면 양수 출력)
        for (int i = 0; i < strlen(s1); i++) {
            if (s1[i] != s2[i]) return s1[i] - s2[i];
        }
    }
}

int cmp (char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return 0; //두 문자열의 길이가 다르다면 같지 않다고 판단
    else {
        int check = 1;
        //문자열 전체에서 같지 않은 값이 하나라도 있을경우 다르다고 판단
        for (int i = 0; i < strlen(s1); i++) {
            if (s1[i] != s2[i]) check = 0;
        }
        return check;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    char** word = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        word[i] = malloc(51 * sizeof(char));
        scanf("%s", word[i]);
    }

    qsort(word, n, sizeof(char*), compare);

    for (int i = 0; i < n; i++) {
        if (i != 0 && cmp(word[i - 1], word[i])) continue;
        printf("%s\n", word[i]);
    }

    for (int i = 0; i < n; i++) {
        free(word[i]);
    }
    free(word);

    return 0;
}