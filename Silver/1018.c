/* 백준 1018(체스판 다시 칠하기)
x좌표와 y좌표의 합의 짝수, 홀수 여부로 WBWB / BWBW 패텬에 각각 비교 후 비교 횟수가 더 적은 지점 탐색 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int n, m;
    char** board;

    scanf("%d %d", &n, &m);
    if (n < 8 || m < 8) return 1;

    board = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = malloc(m * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf(" %c", &board[i][j]);
    }

    int min = 10000;

    //총 구간이 8 * 8보다 클 수 있기 때문에 여러 구간을 탐색하기 위해 i, j 반복문 실행
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int w_first = 0, b_first = 0;
            int value;

            //현재 8 * 8에서 WBWB / BWBW 중 덜 변형해서 도달할 수 있는 패턴을 탐색하기 위해 k, l 반복문 실행
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 8; l++) {
                    int loc = (k + l) % 2;  //x, y 좌표의 합이 짝수인지, 홀수인지 파악후 비교하여 일관성 유지
                    if (!loc) {
                        if(board[k][l] == 'B')
                            w_first++;
                        if(board[k][l] == 'W')
                            b_first++;
                    } else {
                        if(board[k][l] == 'B')
                            b_first++;
                        if(board[k][l] == 'W')
                            w_first++;
                    }
                }
            }

            if (w_first <= b_first) value = w_first;
            else value = b_first;

            if (min > value) min = value;
        }
    }

    printf("%d\n", min);

    return 0;
}