/* 백준 11403(경로 찾기)
플로이드-워셜 알고리즘을 통해서 연결되어있는 경로를 전부 1로 바꿔서 출력한다 */

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

    int** graph;
    graph = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            scanf("%d", &num);

            if (num == 1)
                graph[i][j] = 1;
        }
    }

    for (int k = 0; k < n; k++) {   //플로이드-워셜 알고리즘
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}