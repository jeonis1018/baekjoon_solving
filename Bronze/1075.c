#include <stdio.h>

int main() {
    int n, f;
    int res;

    scanf("%d %d", &n, &f);

    n = n - (n % 100);

    for (int i = 0; i < 100; i++) {
        if (n % f == 0) {
            res = i;
            break;
        }

        n++;
    }

    if (res >= 0 && res <= 9) {
        printf("0%d\n", res);
    } else {
        printf("%d\n", res);
    }

    return 0;
}