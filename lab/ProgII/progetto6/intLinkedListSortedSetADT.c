#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <assert.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

typedef struct intSortedSet IntSortedSet, *IntSortedSetADT;

void printSetPtr(IntSortedSetADT ss) {
    printf("Set Ptr: {");
    for (ListNodePtr node = ss->first; node != NULL; node = node->next) {
        if (node == ss->last) {
            printf("%p}\n", node);
        } else {
            printf("%p, ", node);
        }
    }
}

void printSet(IntSortedSetADT ss) {
    printf("Set: {");
    for (ListNodePtr node = ss->first; node != NULL; node = node->next) {
        if (node == ss->last) {
            printf("%d}\n", node->elem);
        } else {
            printf("%d, ", node->elem);
        }
    }
}

IntSortedSetADT mkSSet() {
    IntSortedSetADT newSet = (IntSortedSetADT) malloc(sizeof(IntSortedSet));

    if (newSet != NULL) {
        newSet->first = NULL;
        newSet->last = NULL;
        newSet->size = 0;
    }

    return newSet;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    if (ssptr != NULL && *ssptr != NULL) {
        free(*ssptr);
        *ssptr = NULL;
        return true;
    }

    return false;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if (ss != NULL) {
        // se l'insieme contiene già elem, ritorna 0
        if (sset_member(ss, elem)) return 0;
        if (ss->size == 0) {
            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            if (newNode) {
                newNode->elem = elem;
                newNode->next = NULL;
                ss->first = newNode;
                ss->last = newNode;
                ss->size = 1;
            }

        } else if (elem < ss->first->elem) {
            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            if (newNode) {
                newNode->elem = elem;
                newNode->next = ss->first;
                ss->first = newNode;
                ss->size++;
            }
        } else if (ss->last->elem > elem) {
            bool aggiunto = false;
            for (ListNodePtr node = ss->first; node->next != NULL; node = node->next) {
                if (node->next->elem > elem) {
                    ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
                    if (newNode) {
                        aggiunto = true;
                        newNode->elem = elem;
                        newNode->next = node->next;
                        node->next = newNode;
                        ss->size++;
                    }
                    break;
                }
            }
            printf("Aggiunto: %d. Size: %d\n", aggiunto, ss->size);
        } else {
            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            if (newNode) {
                newNode->elem = elem;
                newNode->next = NULL;
                ss->last->next = newNode;
                ss->last = newNode;
                ss->size++;
            }
        }
        printSet(ss);
        return 1;
    }
    return 0;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if (ss != NULL && ss->first != NULL) {
        // controlla prima se il primo nodo contiene l'elemento elem
        // nel caso, sposto il puntatore di first al secondo nodo
        if (ss->first->elem == elem) {
            ListNodePtr temp = ss->first->next;
            free(ss->first);
            ss->first = temp;
            ss->size--;
            return 1;
        } else {
            ListNodePtr prec = ss->first;
            for (ListNodePtr node = ss->first->next; node != NULL; node = node->next) {
                if (node->elem == elem) {
                    prec->next = node->next;
                    free(node);
                    ss->size--;
                    return 1;
                }
                prec = prec->next;
            }
        }
        return 0;
    }
    return 0;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if (ss != NULL) {
        for (ListNodePtr node = ss->first; node != NULL; node = node->next) {
            if (node->elem == elem) return true;
        }
        return false;
    }

    return false;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    if (ss == NULL) return false;
    return ss->size == 0;
}

int sset_size(const IntSortedSetADT ss) {
    if (ss == NULL) return -1;
    return ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->first == NULL) return false;

    srand(time(NULL));
    int random = rand() % ss->size;

    ListNodePtr node = ss->first;
    for (int i=0; i<random; i++) {
        node = node->next;
    }

    *ptr = node->elem;
    sset_remove(ss, node->elem);
    return true;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->size != s2->size) return false;
    printf("SOS\n");

    ListNodePtr node1 = s1->first;
    ListNodePtr node2 = s2->first;
    for (int i=0; i<s1->size; i++) {
        bool test1 = sset_member(s1, node2->elem);
        bool test2 = sset_member(s2, node1->elem);
        printf("%d (%d) - %d (%d)\n", test1, node2->elem, test2, node1->elem);
        if (!test1) return false;
        if (!test2) return false;
        node1 = node1->next;
        node2 = node2->next;
    }

    return true;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 != NULL && s2 != NULL) {
        for (ListNodePtr node1 = s1->first; node1 != NULL; node1 = node1->next) {
            bool elem_found = false;
            for (ListNodePtr node2 = s2->first; node2 != NULL && !elem_found; node2 = node2->next) {
                if (node1->elem == node2->elem) elem_found = true;
            }
            if (!elem_found) return false;
        }

        return true;
    }

    return false;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return sset_subseteq(s1, s2) && (s1->size < s2->size);
}

void set_order(IntSortedSetADT set, bool ascending) {
    ListNodePtr maxPtr = NULL;
    ListNodePtr minPtr = NULL;

    if (ascending) {
        for (ListNodePtr node1 = set->first; node1 != NULL; node1 = node1->next) {
            minPtr = node1;
            for (ListNodePtr node2 = node1->next; node2 != NULL; node2 = node2->next) {
                if (node2->elem < minPtr->elem) {
                    minPtr = node2;
                }
            }
            if (minPtr != NULL) {
                int temp = node1->elem;
                node1->elem = minPtr->elem;
                minPtr->elem = temp;
            }
        }
    } else {
        for (ListNodePtr node1 = set->first; node1 != NULL; node1 = node1->next) {
            maxPtr = node1;
            for (ListNodePtr node2 = node1->next; node2 != NULL; node2 = node2->next) {
                if (node2->elem > maxPtr->elem) {
                    maxPtr = node2;
                }
            }
            if (maxPtr != NULL) {
                int temp = node1->elem;
                node1->elem = maxPtr->elem;
                maxPtr->elem = temp;
            }
        }
    }
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return NULL;

    IntSortedSetADT s3 = mkSSet();
    for (ListNodePtr node1 = s1->first; node1 != NULL; node1 = node1->next) {
        if (!sset_member(s3, node1->elem)) {
            sset_add(s3, node1->elem);
        }
    }
    for (ListNodePtr node2 = s2->first; node2 != NULL; node2 = node2->next) {
        if (!sset_member(s3, node2->elem)) {
            sset_add(s3, node2->elem);
        }
    }

    set_order(s3, true);
    return s3;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return NULL;

    IntSortedSetADT s3 = mkSSet();
    for (ListNodePtr node = s1->first; node != NULL; node = node->next) {
        if (sset_member(s2, node->elem)) {
            sset_add(s3, node->elem);
        }
    }

    return s3;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return NULL;

    IntSortedSetADT s3 = mkSSet();
    for (ListNodePtr node = s1->first; node != NULL; node = node->next) {
        if (!sset_member(s2, node->elem)) {
            sset_add(s3, node->elem);
        }
    }

    return s3;
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->size == 0) return false;

    int min = INT_MAX;
    for (ListNodePtr node = ss->first; node != NULL; node = node->next) {
        if (node->elem < min) {
            min = node->elem;
        }
    }

    *ptr = min;
    return true;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ss->size == 0) return false;

    int max = INT_MIN;
    for (ListNodePtr node = ss->first; node != NULL; node = node->next) {
        if (node->elem > max) {
            max = node->elem;
        }
    }

    *ptr = max;
    return true;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    int min;
    if (sset_min(ss, &min)) {
        *ptr = min;
        return sset_remove(ss, min);
    }

    return false;
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    int max;
    if (sset_max(ss, &max)) {
        *ptr = max;
        return sset_remove(ss, max);
    }

    return false;  
}