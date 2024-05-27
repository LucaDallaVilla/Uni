#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "sortedSetADT.h"

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   void* elem;
   ListNodePtr next;
};

struct sortedSetADT {
    ListNodePtr first; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    ListNodePtr last; /* Punta all'ultimo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
    int size; /* Numero di elementi presenti nell'insieme */
};

void stampaint(void* elem) {
    printf("%d", (*(int*)elem));
}

// for debug: stampa un insieme
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
    ListNodePtr cur;
    if(!ss) printf("Insieme non esiste\n");
    else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
    else {
        printf("Insieme: (size %d) ",ss->size);
        for(cur = ss->first; cur; cur=cur->next) (*stampaelem)(cur->elem);
    }
}

// restituisce un insieme vuoto impostando funzione di confronto, NULL se errore
SortedSetADTptr mkSSet(int (*compare)(void*, void*)) {
    SortedSetADTptr set = (SortedSetADTptr) malloc(sizeof(SortedSetADT));

    if (set) {
        set->compare = compare;
        set->first = NULL;
        set->last = NULL;
        set->size = 0;
    }

    return set;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
    if (ssptr && *ssptr) {
        free(*ssptr);
        *ssptr = NULL;
        return true;
    }
    ssptr = NULL;

    return false;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
    if (!ss) return false;
    if (sset_member(ss, elem)) return false;

    ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
    if (!newNode) return false;
    newNode->elem = elem;
    if (!ss->first) {
        newNode->next = NULL;
        ss->first = newNode;
        ss->last = newNode;
    } else {
        if (ss->compare(elem, ss->first->elem) == -1) { // controllo se elem è da inserire nella prima posizione
            newNode->next = ss->first;
            ss->first = newNode;
        } else if (ss->compare(elem, ss->last->elem) == 1) { // controllo se elem è da inserire nell'ultima posizione
            ss->last->next = newNode;
            newNode->next = NULL;
            ss->last = newNode;
        } else { // elem è da inserire in mezzo al set
            ListNodePtr node = ss->first;
            while (node) {
                if (ss->compare(elem, node->next->elem) == -1) break;
                node = node->next;
            }
            newNode->next = node->next;
            node->next = newNode;
        }
    }
    ss->size++;
    return true;
}

// toglie un elemento all'insieme 
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
    if (!ss) return false;
    if (!ss->first) return false;

    if (ss->first->elem == elem) {
        ListNodePtr temp = ss->first->next;
        free(ss->first);
        ss->first = temp;
        ss->size--;
        return true;
    }

    ListNodePtr precNode = ss->first;
    for (ListNodePtr node = ss->first->next; node; node=node->next) {
        if (node->elem == elem) {
            precNode->next = node->next;
            free(node);
            ss->size--;
            return true;
        }
        precNode = precNode->next;
    }
    return false;
}

// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
    if (ss) {
        for (ListNodePtr node = ss->first; node; node=node->next) {
            if (node->elem == elem) return 1;
        }
        return 0;
    }
    return -1;
}
    
// controlla se l'insieme e' vuoto    
int isEmptySSet(const SortedSetADT* ss) {
    if (!ss) return -1;
    return ss->size == 0;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
    if (!ss) return -1;
    return ss->size;
} 

_Bool sset_extract(SortedSetADTptr ss, void**ptr) { // toglie e restituisce un elemento a caso dall'insieme
    if (!ss || !ss->first) return false;

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

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
    if (!s1 || !s2) return -1;
    if (s1->size != s2->size) return 0;

    for (ListNodePtr node = s1->first; node; node = node->next) {
        if (!sset_member(s2, node->elem)) return 0;
    }

    return 1;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return -1;

    for (ListNodePtr node1 = s1->first; node1; node1 = node1->next) {
        if (!sset_member(s2, node1->elem)) return 0;
    }

    return 1;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return -1;

    return sset_subseteq(s1, s2) && s1->size != s2->size;
}

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return NULL;

    SortedSetADTptr s3 = mkSSet(s1->compare);
    if (!s3) return NULL;

    for (ListNodePtr node1 = s1->first; node1; node1 = node1->next) {
        if (!sset_member(s2, node1->elem)) {
            sset_add(s3, node1->elem);
        }
    }

    return s3;
}

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return NULL;
    SortedSetADTptr s3 = mkSSet(s1->compare);
    if (!s3) return NULL;

    for (ListNodePtr node1 = s1->first; node1; node1 = node1->next) {
        sset_add(s3, node1->elem);
    }

    for (ListNodePtr node2 = s2->first; node2; node2 = node2->next) {
        sset_add(s3, node2->elem);
    }

    return s3;
}

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return NULL;

    ListNodePtr node1 = s1->first;
    ListNodePtr node2 = s2->first;
    SortedSetADTptr s3 = mkSSet(s1->compare);

    while(node1 && node2) {
        if (sset_member(s2, node1->elem)) sset_add(s3, node1->elem);
        if (sset_member(s1, node2->elem)) sset_add(s3, node2->elem);
        node1 = node1->next;
        node2 = node2->next;
    }

    return s3;
}

// restituisce l'elemento minimo
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
    if (!ss || sset_size(ss) == 0) return false;

    void* min = ss->first->elem;
    for (ListNodePtr node = ss->first->next; node; node = node->next) {
        if (ss->compare(node->elem, min) == -1) {
            min = node->elem;
        }
    }

    *ptr = min;
    return true;
}

// restituisce l'elemento massimo
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
    if (!ss || sset_size(ss) == 0) return false;

    void* max = ss->first->elem;
    for (ListNodePtr node = ss->first->next; node; node = node->next) {
        if (ss->compare(node->elem, max) == 1) {
            max = node->elem;
        }
    }

    *ptr = max;
    return true;
}

// toglie e restituisce l'elemento minimo
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
    if (!ss) return false;
    if (sset_min(ss, ptr)) {
        sset_remove(ss, *ptr);
        return true;
    }
    return false;
}

// toglie e restituisce l'elemento massimo (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
    if (!ss) return false;
    if (sset_max(ss, ptr)) {
        sset_remove(ss, *ptr);
        return true;
    }
    return false;     
}

