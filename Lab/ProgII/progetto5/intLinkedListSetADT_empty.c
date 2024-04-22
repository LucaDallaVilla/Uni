#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "intSetADT.h"
#include "intLinkedListSet.h"


IntSetADT mkSet() {
    IntSetADT newSet = (IntSetADT) malloc(sizeof(IntSet));
    if (newSet != NULL) {
        newSet->size = 0;
        newSet->front = NULL;
    }

    return newSet;
}

_Bool dsSet(IntSetADT *sp) {
    if (sp != NULL && *sp != NULL) {
        free(*sp);
        *sp = NULL;

        return true;
    }

    return false;
}

_Bool set_add(IntSetADT set, const int elem) {
    bool found = false;

    if (set != NULL) {
        ListNodePtr temp = set->front;
        set = realloc(set, sizeof(set) + sizeof(ListNode));

        if (set != NULL) {
            while (true) {
                if (set->front->data == elem) {
                    found = true;
                }

                if (set->front->next == NULL) {
                    break;
                }
            }

            ListNodePtr newNode = malloc(sizeof(ListNode));
            if (newNode != NULL) {
                printf("LESGOWSKY\n");
                newNode->data = elem;
                newNode->next = NULL;

                set->front->next = newNode;
                set->front = temp;
                set->size++;
            }
        }
    }

    return found;
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