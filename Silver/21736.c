/* 백준 21736(헌내기는 친구가 필요해)
입력받은 이차원 배열의 정보를 담은 구조체를 구현하여 dfs/bfs로 만날 수 있는 친구의 수를 카운트 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int value;  //벽, 공간, 친구를 확인하기 위한 변수
    int visited;    //dfs 사용을 위한 방문 여부 표시 변수
} campus;

void dfs(campus** c, int x, int y, int n, int m, int* cnt) {    //깊이 우선 탐색
    c[y][x].visited = 1;
    if (c[y][x].value == 2) (*cnt)++;

    //배열 끝 여부, 벽, 방문 여부를 검사한 후 재귀호출로 dfs 구현
    if (x > 0 && c[y][x - 1].value != 0 && c[y][x - 1].visited == 0) dfs(c, x - 1, y, n, m, cnt);
    if (x < m - 1 && c[y][x + 1].value != 0 && c[y][x + 1].visited == 0) dfs(c, x + 1, y, n, m, cnt);
    if (y > 0 && c[y - 1][x].value != 0 && c[y - 1][x].visited == 0) dfs(c, x, y - 1, n, m, cnt);
    if (y < n - 1 && c[y + 1][x].value != 0 && c[y + 1][x].visited == 0) dfs(c, x, y + 1, n, m, cnt);
}

int main(void) {
    int n, m;

    scanf("%d %d", &n, &m);

    campus** c; //문제에 제시된 campus 형태와 같은 이차원으로 선언

    c = malloc(n * sizeof(campus*));
    for (int i = 0; i < n; i++) {
        c[i] = malloc(m * sizeof(campus));
    }

    char info;
    int x, y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j].visited = 0;

            scanf(" %c", &info);    //알파벳 하나씩 입력받기 위해서 " %c"로 입력받기

            if (info == 'O') c[i][j].value = 1;     //입력받은 값에 따라 분류하여 value값에 저장
            else if (info == 'P') c[i][j].value = 2;
            else if (info == 'X') c[i][j].value = 0;
            else if (info == 'I') {
                c[i][j].value = 1;
                x = j;
                y = i;
            } else return 1;
        }
    }

    int cnt = 0;

    dfs(c, x, y, n, m, &cnt);

    if (cnt == 0) printf("TT\n");
    else printf("%d\n", cnt);

    for (int i = 0; i < n; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}