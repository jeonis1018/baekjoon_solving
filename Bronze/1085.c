/*백준 1085(직사각형에서 탈출)
도출할 수 있는 4개의 값 중에서 최솟값을 찾아서 출력 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    int x, y, w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    int x_min, y_min;

    if (w - x <= x) x_min = w - x;
    else x_min = x;

    if (h - y <= y) y_min = h - y;
    else y_min = y;

    if (x_min <= y_min) printf("%d\n", x_min);
    else printf("%d\n", y_min);

    return 0;
}