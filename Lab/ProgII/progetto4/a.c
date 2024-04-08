#include <stdio.h>
#include <stdlib.h>

struct charQueue {
    int capacity;
    char* a;
};

void func(struct charQueue *q) {
    printf("%u\n", q->capacity);
}

int main(void) {
    struct charQueue *queue;
    queue = malloc(sizeof(struct charQueue));
    queue->capacity = 8;
    queue->a = "Luca";

    func(queue);
}

