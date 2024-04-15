#include <stdlib.h>
#include <stdbool.h>

#include "intSetADT.h"
#include "intLinkedListSet.h"


IntSetADT mkSet() {
    IntSetADT newSet = (IntSetADT) malloc(sizeof(IntSet) * sizeof(int));
    if (newSet != NULL) {
        newSet->size = 0;
        newSet->front = NULL;
    }

    return newSet;
}

_Bool dsSet(IntSetADT *sp) {
    if (*sp != NULL && sp != NULL) {
        while ((*sp)->front != NULL) {
            ListNodePtr temp = (*sp)->front;
            (*sp)->front = (*sp)->front->next;
            free(temp);
        }
        free(*sp);

        return true;
    }

    sp = NULL;
    return false;
}

_Bool set_add(IntSetADT set, const int elem) {
    return false;
}

_Bool set_remove(IntSetADT set, const int elem) {
    return false;
}

_Bool set_member(const IntSetADT set, const int elem) {
    return false;
}

_Bool isEmptySet(const IntSetADT set) {
    return false;
}

int set_size(const IntSetADT set) {
    return -1;
}

_Bool set_extract(IntSetADT set, int *datap) {
    return false;
}

_Bool set_equals(const IntSetADT set1, const IntSetADT set2) {
    return false;
}

_Bool subseteq(const IntSetADT set1, const IntSetADT set2) {
    return false;
}

_Bool subset(const IntSetADT set1, const IntSetADT set2) {
    return false;    
}

IntSetADT set_union(const IntSetADT set1, const IntSetADT set2) {
    return NULL;
}

IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2) {
    return NULL;
}

IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2) {
    return NULL;
}