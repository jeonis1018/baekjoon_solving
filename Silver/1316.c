/* 백준 1316(그룹 단어 체커)
입력받은 문자의 알파벳에서 'a'를 빼서 int 형태로 만든 후, alpha 배열의 해당 인덱스의 값이 0인지 1인지 확인하여 이미 등장한 알파벳인지 검사 */

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
    getchar();  //버퍼에 남아있는 '\n' 제거

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int* alpha = calloc(26, sizeof(int));
        char word[101];
        fgets(word, sizeof(word), stdin);

        int back_num = -1;
        int check = 1;
        for (int j = 0; j < strlen(word); j++) {
            if (word[j] == '\n') continue;  //'\n'입력 제거

            int to_num = word[j] - 'a';
            if (back_num == to_num) continue;   //이전 알파벳과 같다면 반복되어 나오더라도 그룹문자 성립
            else if (alpha[to_num] == 0) alpha[to_num] = 1; //한번 등장한 알파벳 체크
            else {  //이미 등장한 알파벳이 연속적이지 않게 등장한다면 그룹문자가 아니라고 판명
                check = 0;
                break;
            }

            back_num = to_num;
        }

        if (check == 1) cnt++;
        
        free(alpha);
    }

    printf("%d", cnt);

    return 0;
}