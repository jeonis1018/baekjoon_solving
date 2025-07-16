/* 백준 1012(유기농 배추)
dfs를 통해서 배추흰지렁이의 최소 개수를 구한다 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int exist;  //배추가 있는지 여부를 담는 변수
    int visited;    //dfs에서 방문 여부를 확인하는 변수
} cell;

void dfs(cell** farm, int x, int y, int m, int n) {
    farm[y][x].visited = 1;

    //배열의 끝부분 여부, 배추가 있는지 여부, 방문 여부를 확인한 후 재귀함수를 통해 dfs 구현
    if (x > 0 && farm[y][x - 1].exist == 1 && farm[y][x - 1].visited == 0) dfs(farm, x - 1, y, m, n);
    if (x < m - 1 && farm[y][x + 1].exist == 1 && farm[y][x + 1].visited == 0) dfs(farm, x + 1, y, m, n);
    if (y > 0 && farm[y - 1][x].exist == 1 && farm[y - 1][x].visited == 0) dfs(farm, x, y - 1, m, n);
    if (y < n - 1 && farm[y + 1][x].exist == 1 && farm[y + 1][x].visited == 0) dfs(farm, x, y + 1, m, n);
}

int main(void) {
    int t, m, n, k;
    int *x, *y;
    cell** farm;

    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        int cnt = 0;

        scanf("%d %d %d", &m, &n, &k);

        x = malloc(k * sizeof(int));
        y = malloc(k * sizeof(int));
        farm = malloc(n * sizeof(cell*));
        for (int j = 0; j < n; j++) {
            farm[j] = (cell*)calloc(m, sizeof(cell));
        }

        for (int j = 0; j < k; j++) {
            scanf("%d %d", &x[j], &y[j]);
            farm[y[j]][x[j]].exist = 1;
        }

        for (int j = 0; j < k; j++) {
            if (farm[y[j]][x[j]].visited == 0) {
                dfs(farm, x[j], y[j], m, n);
                cnt++;
            }
        }

        printf("%d\n", cnt);

        free(x);
        free(y);
        for (int j = 0; j < n; j++) {
            free(farm[j]);
        }
        free(farm);
    }

    return 0;
}