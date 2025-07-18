/* 백준 1389(케빈 베이컨의 6단계 법칙)
플로이드-워셜 알고리즘을 통해 각 노드들 간의 최소 거리들을 전부 구해서 저장하고, 각 행의 합계가 가장 작은 행 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

#define INF 1e9;

int main(void) {
    int n, m;

    scanf("%d %d", &n, &m);

    int** dist;
    dist = malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dist[i] = malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) dist[i][j] = 0;     //자기자신의 거리는 0으로 설정
            else dist[i][j] = INF;      //다른 노드들과의 거리는 임시로 전부 INF로 설정
        }
    }

    int n1, n2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &n1, &n2);

        //연결되어 있는 노드는 거리를 1로 설정
        dist[n1][n2] = 1;
        dist[n2][n1] = 1;
    }

    //k는 거쳐갈 수 있는 다른 노드를 확인하기 위한 값
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //플로이드-워셜 알고리즘, dp와 유사한 구조로 모든 노드들 간의 최소 거리를 구해 저장 (dist[i][j]는 i와 j간의 최소 거리)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int* bacon = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        bacon[i] = 0;
    }

    int min = 5000, min_num;
    for (int i = 1; i <= n; i++) {
        //각 행의 합산을 구한 뒤, 최소 합산 값을 가진 행 탐색
        for (int j = 1; j <= n; j++)
            bacon[i] += dist[i][j];
        
        if (min > bacon[i]) {
            min = bacon[i];
            min_num = i;
        }
    }

    printf("%d\n", min_num);

    free(bacon);
    for (int i = 0; i <= n; i++) {
        free(dist[i]);
    }
    free(dist);

    return 0;
}