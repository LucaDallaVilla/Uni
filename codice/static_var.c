#include <stdio.h>

int foo() {
    static int counter = 1;
    return counter++;
}

int main() {
    for (int i=0; i<5; i++) {
        printf("%d\n", foo());
    }
}