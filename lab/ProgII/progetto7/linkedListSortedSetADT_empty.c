#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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

// for debug: stampa un insieme
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
    ListNodePtr cur;
    if(!ss) printf("Insieme non esiste\n");
    else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
    else {
        printf("Insieme: (size %d) ",ss->size);
        for(cur = ss->first; cur; cur=cur->next) (*stampaelem)(cur->elem);
        printf("\n");
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
        ssptr = NULL;
        return true;
    }
    ssptr = NULL;

    return false;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) { 
    if (ss) {
        if (sset_member(ss, elem)) return false;
        if (!ss->first) { // caso in cui ss è vuota 
            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            if (newNode) {
                newNode->elem = elem;
                newNode->next = NULL;
                ss->first = newNode;
                ss->last = newNode;

                return true;
            }

            return false;
        } else {
            ListNodePtr precNode = ss->first;
            ListNodePtr node = ss->first->next;
            for (; node; node = node->next) {
                if (node->elem > elem && precNode->elem < elem) break;
                precNode = precNode->next;
            }

            ListNodePtr newNode = (ListNodePtr) malloc(sizeof(ListNode));
            if (newNode) {
                newNode->elem = elem;
                newNode->next = node;
                precNode->next = newNode;
                ss->compare = NULL;
            }

            return false;
        }

        ss->size++;
    }
}  

// toglie un elemento all'insieme 
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
    if (ss) {
        ListNodePtr precNode = ss->first;
        for (ListNodePtr node = ss->first->next; node; node=node->next) {
            if (node->elem == elem) {
                precNode->next = node->next;
                free(node);
                ss->size--;
                return true;
            }
        }
    }
    return false;
}

// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
    if (ss) {
        for (ListNodePtr node = ss->first; node; node=node->next) {
            if (node->elem == elem) return 1;
        }
    }
    return 0;
}
    
// controlla se l'insieme e' vuoto    
int isEmptySSet(const SortedSetADT* ss) {
    if (!ss) return false;
    return ss->size == 0;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
    if (!ss) return -1;
    return ss->size;
} 

_Bool sset_extract(SortedSetADTptr ss, void**ptr) { // toglie e restituisce un elemento a caso dall'insieme
    if (!ss || ! ss->first) return false;

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
    return -1;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
    return -1;
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    return -1;
} 

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
    return NULL;   
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
    return NULL; 
} 

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
    return NULL;
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
    return false;
}

// restituisce l'ultimo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
    return false;
}

// toglie e restituisce il primo elemento 
_Bool sset_extractMin(SortedSetADTptr ss, void**ptr) {
    return false;    
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(SortedSetADTptr ss, void**ptr) {
    return false;       
}
