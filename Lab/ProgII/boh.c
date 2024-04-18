#include <stdio.h>

int main() {
    size_t size = 16;
    int array[] = {12, 2, 1, 3, 5, 1, 7, 1, -1, 4, -2, -3, 1, 9, -6, 10};
    int result = array[0];

    for (int i=1; i<size; i++) {
        if (array[i] > result) {
            result = array[i];
        }
    }

    printf("%d\n", result);
}