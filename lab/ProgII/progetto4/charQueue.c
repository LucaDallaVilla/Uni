#include "charQueueADT.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

/* il valore 8 può essere cambiato */
#define INITIAL_CAPACITY 8

struct charQueue {
    int capacity; /* capacity == INITIAL CAPACITY*2^n, per qualche numero naturale n >= 1 */
    char* a; /* array, di dimensione capacity, che memorizza gli elementi presenti nella coda */
    int size; /* numero di elementi presenti nella coda (0 <= size <= capacity) */
    int back; /* prima posizione libera in a (dove sarà memorizzato il prossimo elemento della coda (0 <= back <= capacity-1) */
    int front; /* posizione in a dove (se size > 0) è memorizzato il primo elemento della coda (0 <= front <= capacity-1) */
    /* (front==back) se e solo se ((size == 0) || (size == capacity)) */
    /* Gli elementi della coda sono in: a[front..back-1] se back > front, e in a[front..capacity-1],a[0..back-1], se back <= front */
    /* L'array si espande di un fattore due quando si riempie, e si dimezza (se capacity > INITIAL_CAPACITY) */
    /* quando size scende a capacity/4 (parametri personalizzabili) */      
    /* Se capacity > INITIAL_CAPACITY, allora il numero di elementi in coda è >= capacity/4 */
};


/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    CharQueueADT newQueue = malloc(sizeof(struct charQueue));
    
    newQueue->capacity = INITIAL_CAPACITY;
    newQueue->size = 0;
    newQueue->back = 0;
    newQueue->front = 0;
    
    newQueue->a = malloc(INITIAL_CAPACITY);
    if (newQueue->a == NULL) {
        free(newQueue);
        return NULL;
    }
    
    return newQueue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
    if (*pq != NULL) {
        free(*pq);
    }
    *pq = NULL;
    pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda */
_Bool enqueue(CharQueueADT q, const char e) {
    if (q == NULL || q->a == NULL) return false;

    if (q->size >= q->capacity) {
        q->capacity = 2 * q->capacity;
        char *newArray = (char *) realloc(q->a, q->capacity);
        if (newArray == NULL) return false;
        q->a = newArray;
    }
    
    q->a[q->back] = e;
    q->back++;
    q->size++;
    
    if (q->back >= q->capacity) q->back = 0;
    
    return true;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda */
_Bool dequeue(CharQueueADT q, char* res) {
    if (q == NULL || q->a == NULL || q->size == 0) return false;
    
    *res = q->a[q->front];
    q->size--;
    q->front++;
    
    if (q->size <= q->capacity / 4 && q->capacity > INITIAL_CAPACITY) {
        q->capacity = q->capacity / 2;
        char *newArray = (char *) realloc(q->a, q->capacity);
        if (newArray == NULL) return false;
        q->a = newArray;
    }
    
    return true;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
    return q->size == 0;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    return q->size;
}

/* @brief Restituisce l'elemento nella posizione data (senza toglierlo) */
_Bool peek(CharQueueADT q, int position, char *res) {
    if (q != NULL && position < q->back && position >= q->front) {
        *res = q->a[position];
        return true;
    }
    
    return false;
}