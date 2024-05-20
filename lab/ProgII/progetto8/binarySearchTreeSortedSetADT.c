#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "sortedSetADT.h"

typedef struct treeNode TreeNode, *TreeNodePtr;

struct treeNode {
    void* elem;
    TreeNodePtr left, right;
};

struct sortedSetADT {
    TreeNodePtr root; /* Punta alla radice dell'albero, se l'insieme e' vuoto vale NULL */
    int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
    int size; /* Numero di elementi presenti nell'insieme */
	int levels; /* Numero di livelli dell'insieme */
};

void stampaSet_rec(TreeNodePtr cur, void (*stampaelem)(void*)) {
    #ifdef DEBUG
    printf("( ");
    #endif
    if (cur) {
        stampaSet_rec(cur->left, stampaelem);
        (*stampaelem)(cur->elem);
        stampaSet_rec(cur->right, stampaelem);
    }
    #ifdef DEBUG
    printf(") ");
    #endif
}

// stampa i contenuti dell'insieme, data la funzione di stampa di un elemento
void stampaSet(SortedSetADTptr ss, void (*stampaelem)(void*)) {
    if(!ss) printf("Insieme non esiste\n");
    else if(sset_size(ss) == 0) printf("Insieme vuoto\n");
    else {
        printf("Insieme: (size %d) ",ss->size);
        stampaSet_rec(ss->root, stampaelem);
        printf("\n");
    }
}

// restituisce un insieme vuoto impostando funzione di confronto, NULL se errore
SortedSetADTptr mkSSet(int (*compare)(void*, void*)) {
    SortedSetADTptr set = (SortedSetADTptr) malloc(sizeof(SortedSetADT));

    if (set) {
        set->root = NULL;
        set->compare = NULL;
        set->size = 0;
    }

    return set;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(SortedSetADTptr* ssptr) {
    if (!ssptr) return false;

    if (*ssptr) {
        free(*ssptr);
        *ssptr = NULL;
        return true;
    }

    return false;
}

// aggiunge un elemento all'insieme 
_Bool sset_add(SortedSetADTptr ss, void* elem) {
	if (!ss) return false;
	if (!(ss->root)) {
		TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
		if (newNode) {
			newNode->elem = elem;
			newNode->left = NULL;
			newNode->right = NULL;
		}
		ss->levels = 1;
		ss->root = newNode;
		return true;
	}

	TreeNodePtr node = ss->root;
	while (node) {
		if (elem < node->elem) {
			if (!node->left) {
				TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
				if (newNode) {
					newNode->elem = elem;
					newNode->left = NULL;
					newNode->right = NULL;
				}
				node->left = newNode;
				if (!node->right) ss->levels++;
				return true;
			}
			node = node->left;
		}
		if (elem > node->elem) {
			if (!node->right) {
				TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
				if (newNode) {
					newNode->elem = elem;
					newNode->left = NULL;
					newNode->right = NULL;
				}
				node->right = newNode;
				if (!node->left) ss->levels++;
				return true;
			}
			node = node->right;
		}
	}

	return false;
}

void sset_extractMin_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*));
void sset_extractMax_rec(TreeNodePtr* cur, void**ptr, int (*compare)(void*, void*));

// funzione ausiliaria che toglie un elemento da un sottoalbero
_Bool sset_remove_rec(TreeNodePtr* cur, void* elem, int (*compare)(void*, void*)) {
    if (*cur == NULL) return false;
    int r = compare(elem, (*cur)->elem);
    if (r < 0) return sset_remove_rec(&((*cur)->left), elem, compare);
    if (r > 0) return sset_remove_rec(&((*cur)->right), elem, compare);
    void* ptr;
    if ((*cur)->left == NULL) {
        sset_extractMin_rec(cur, &ptr, compare);
    } else if ((*cur)->right == NULL) {
        sset_extractMax_rec(cur, &ptr, compare);
    } else {
        sset_extractMax_rec(&((*cur)->left), &ptr, compare);
        (*cur)->elem = ptr;
    }
    return true;
}

// toglie un elemento all'insieme
_Bool sset_remove(SortedSetADTptr ss, void* elem) {
    if (ss && sset_remove_rec(&(ss->root), elem, ss->compare)) {
        ss->size--;
        return true;
    }
    return false;
}

// controlla se un elemento appartiene all'insieme
int sset_member(const SortedSetADT* ss, void* elem) {
    if (!ss) return false;
	if (ss->size == 0) return false;

	TreeNodePtr node = ss->root;
	while(node) {
		if (elem > node->elem) {
			node = node->right;
		} else if (elem < node->elem) {
			node = node->left;
		} else {
			return true;
		}
	}

	return false;
}

// cerca un elemento nell'insieme che si compara uguale a quello dato, NULL se non trovato
void* sset_search(const SortedSetADT* ss, void* elem) {
    if (!ss) return false;
	if (ss->size == 0) return false;

	TreeNodePtr node = ss->root;
	while(node) {
		if (elem > node->elem) {
			node = node->right;
		} else if (elem < node->elem) {
			node = node->left;
		} else {
			return elem;
		}
	}

	return NULL;
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
    if (!ss) return false;

	srand(time(NULL));
    int random = rand() % ss->levels;
	TreeNodePtr node = ss->root;
	for (int i=0; i<random; ++i) {
    	int left = rand() % 2;
		if (left) node = node->left;
		else node = node->right;
	}
	sset_remove(ss, node->elem);
	return true;
} 

int sset_equals_rec(const SortedSetADT* s1, const SortedSetADT* s2, TreeNodePtr node) {
	if (!node) return true;
	
	int ret1 = sset_equals_rec(s1, s2, node->left);
	int ret2 = sset_equals_rec(s1, s2, node->right);
	
	if (!ret1 || !ret2) return false;
	return true;
}

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
    if (!s1 || !s2) return -1;

	return sset_equals_rec(s1, s2, s1->root);
}

int sset_subseteq_rec(const SortedSetADT* s1, const SortedSetADT* s2, TreeNodePtr node) {
	if (!node) return true;

	int ret1 = sset_subseteq_rec(s1, s2, node->left);
	int ret2 = sset_subseteq_rec(s1, s2, node->right);

	if (ret1 && ret2) {
		return sset_member(s2, node->elem);
	}

	return false;
}

// controlla se il primo insieme e' incluso nel secondo
int sset_subseteq(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return -1;

	return sset_equals_rec(s1, s2, s1->root);
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    return sset_subseteq(s1, s2) && (s1->size < s2->size);
} 

SortedSetADTptr sset_subtraction_rec(const SortedSetADT* s1, const SortedSetADT* s2, SortedSetADT* s3, TreeNodePtr node) {
	if (!node) return s3;

	if (!sset_member(s2, node->elem)) {
		sset_add(s3, node->elem);
	}

	sset_subtraction_rec(s1, s2, s3, node->left);
	sset_subtraction_rec(s1, s2, s3, node->right);
}

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
	if (!s1 || !s2) return NULL;
	SortedSetADTptr s3 = mkSSet(s1->compare);
	return sset_subtraction_rec(s1, s2, s3, s1->root);
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

// crea un array con i contenuti del set in ordine di visita pre-order, NULL se errore
void** sset_toArray(const SortedSetADT* ss) {
    return NULL;
}