#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "intSetADT.h"
#include "intLinkedListSet.h"


char *myToString(IntSetADT set) {
    char *sout = malloc(100*sizeof(char));

    ListNodePtr nptr = set->front;
    sprintf(sout, "{");
    while (nptr) {
        if (nptr == set->front)
            sprintf(sout+strlen(sout), "%d", nptr->data);
        else
            sprintf(sout+strlen(sout), ",%d", nptr->data);
        nptr = nptr->next;
    }

    sprintf(sout+strlen(sout), "}");

    return sout;
}

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
    if (set != NULL) {
        // empty set 
        if (set->front == NULL) {
            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            newNode->data = elem;
            newNode->next = NULL;
            set->size++;
            set->front = newNode;
            return true;
        } 
        // set size >= 1
        else {
            ListNodePtr node = set->front;
            while (node->next != NULL) {
                // se trovo l'elemento esco dalla funzione senza aggiungerlo nuovamente
                if (node->data == elem) {
                    return false;
                }
                node = node->next;
            }
            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            newNode->data = elem;
            newNode->next = NULL;
            set->size++;
            node->next = newNode;
            return true;
        }
    }

    return false;
}

int mySize(IntSetADT set) {
    int size = 0;

    if (set != NULL) {
        ListNodePtr node = set->front;
        while (node != NULL) {
            node = node->next;
            size++;
        }
    }

    return size;
}

_Bool set_remove(IntSetPtr set, const int elem) {
    if (set != NULL) {
        ListNodePtr curr = set->front;
        ListNodePtr prev = NULL;

        // Scorrimento della lista fino a trovare l'elemento da rimuovere
        while (curr != NULL && curr->data != elem) {
            prev = curr;
            curr = curr->next;
        }

        // Se l'elemento non è stato trovato, ritorna falso
        if (curr == NULL) {
            return 0;
        }
        // Se l'elemento è il primo della lista
        if (prev == NULL) {
            set->front = curr->next;
        } else {
            prev->next = curr->next;
        }

        // Deallocazione della memoria del nodo rimosso
        free(curr);
        set->size--;
        return 1;
    }

    return 0;
}

_Bool set_member(const IntSetADT set, const int elem) {
    if (set != NULL) {
        ListNodePtr node = set->front;

        while (node != NULL) {
            if (node->data == elem) {
                return true;
            }
            node = node->next;
        }
    }

    return false;
}

_Bool isEmptySet(const IntSetADT set) {
    if (set != NULL) {
        return set->front == NULL;
    }
    return false;
}

int set_size(const IntSetADT set) {
    if (set != NULL) {
        return set->size;
    }
    return -1;
}

_Bool set_extract(IntSetADT set, int *datap) {
    if (set != NULL && set->front != NULL) {
        // gets random integer between 0 and set->size-1
        srand(time(NULL));
        int random = rand() % set->size;

        // loop trough the set until the chosen random node
        ListNodePtr node = set->front;
        for (int i=0; i<random; i++) {
            node = node->next;
        }

        // printf("Chosen one: %d, so... %d\n", random, node->data);
        *datap = node->data;
        set_remove(set, node->data);

        return true;
    }
    return false;
}

_Bool set_equals(const IntSetADT set1, const IntSetADT set2) {
    if (set1 != NULL && set2 != NULL) {
        if (set1->size != set2->size) return false;

        ListNodePtr node1 = set1->front;
        ListNodePtr node2 = set2->front;
        while (node1 != NULL && node2 != NULL) {
            if (node1->data != node2->data) {
                return false;
            }
            node1 = node1->next;
            node2 = node2->next;
        }

        return true;
    } else if (set1 == NULL && set2 == NULL) return true;

    return false;
}

_Bool subseteq(const IntSetADT set1, const IntSetADT set2) {
    if (set1 != NULL && set2 != NULL) {
        for (ListNodePtr node1 = set1->front; node1 != NULL; node1 = node1->next) {
            bool elem_found = false;
            for (ListNodePtr node2 = set2->front; node2 != NULL && !elem_found; node2 = node2->next) {
                if (node1->data == node2->data) elem_found = true;
            }
            if (!elem_found) return false;
        }

        return true;
    }

    return false;
}

_Bool subset(const IntSetADT set1, const IntSetADT set2) {
    return subseteq(set1, set2) && (set1->size < set2->size);
}

void set_order(IntSetADT set, bool ascending) {
    ListNodePtr maxPtr = NULL;

    for (ListNodePtr node1 = set->front; node1 != NULL; node1 = node1->next) {
        maxPtr = node1;
        for (ListNodePtr node2 = node1->next; node2 != NULL; node2 = node2->next) {
            if (node2->data > maxPtr->data) {
                maxPtr = node2;
            }
        }
        if (maxPtr != NULL) {
            int temp = node1->data;
            node1->data = maxPtr->data;
            maxPtr->data = temp;
        }
    }
}

IntSetADT set_union(const IntSetADT set1, const IntSetADT set2) {
    if (set1 == NULL || set2 == NULL) return NULL;

    IntSetADT set3 = mkSet();
    for (ListNodePtr node1 = set1->front; node1 != NULL; node1 = node1->next) {
        if (!set_member(set3, node1->data)) {
            set_add(set3, node1->data);
        }
    }
    for (ListNodePtr node2 = set2->front; node2 != NULL; node2 = node2->next) {
        if (!set_member(set3, node2->data)) {
            set_add(set3, node2->data);
        }
    }

    set_order(set3, false);
    return set3;
}

IntSetADT set_intersection(const IntSetADT set1, const IntSetADT set2) {
    if (set1 == NULL || set2 == NULL) return NULL;

    IntSetADT set3 = mkSet();
    for (ListNodePtr node1 = set1->front; node1 != NULL; node1 = node1->next) {
        bool elem_found = false;
        for (ListNodePtr node2 = set2->front; node2 != NULL && !elem_found; node2 = node2->next) {
            if (node1->data == node2->data) {
                elem_found = true;
                set_add(set3, node1->data);
            }
        }
    }

    return set3;
}

IntSetADT set_subtraction(const IntSetADT set1, const IntSetADT set2) {
    if (set1 == NULL || set2 == NULL) return NULL;

    IntSetADT set3 = mkSet();
    for (ListNodePtr node1 = set1->front; node1 != NULL; node1 = node1->next) {
        bool elem_found = false;
        for (ListNodePtr node2 = set2->front; node2 != NULL && !elem_found; node2 = node2->next) {
            if (node1->data == node2->data) {
                elem_found = true;
            }
        }
        if (!elem_found) {
            set_add(set3, node1->data);
        }
    }

    return set3;
}