#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(void) {
    for (int i=-50000000; i<INT_MAX; i-=100) {
        printf("%d\n", i);
    }
}

