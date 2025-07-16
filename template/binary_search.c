#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

typedef int element;

element binary_search (element* arr, int size, element target) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main(void) {


    return 0;
}