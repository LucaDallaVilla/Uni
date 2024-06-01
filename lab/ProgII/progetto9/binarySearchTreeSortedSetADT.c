#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
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
};

void stampa_array(void** array, size_t size) {
	printf("[");
	for (int i=0; i<size-1; ++i) {
		printf("%d, ", *(int*)array[i]);
	}
	printf("%d]", *(int*)array[size-1]);
}

void stampaint(void* elem) {
    printf("%d ",(*(int*)elem));
}

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
        set->compare = compare;
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

	TreeNodePtr newNode = (TreeNodePtr) malloc(sizeof(TreeNode));
	if (!newNode) return false;
	newNode->elem = elem;
	newNode->left = NULL;
	newNode->right = NULL;

	// insieme vuoto
	if (!ss->root)
		ss->root = newNode;
	else {
		TreeNodePtr node = ss->root;
		while (node) {
			int comparison = ss->compare(elem, node->elem);
			if (comparison == 1) {
				if (!node->right) {
					node->right = newNode;
					break;
				}
				node = node->right;
			} else if (comparison == -1) {
				if (!node->left) {
					node->left = newNode;
					break;
				}
				node = node->left;
			} else { // l'elemento è già presente nell'albero
				return false;
			}
		}
	}

	ss->size++;
	return true;
}

void sset_extractMin_rec(TreeNodePtr* cur, void** minElem, int (*compare)(void*, void*)) {
    if ((*cur)->left == NULL) {
        *minElem = (*cur)->elem;
        TreeNodePtr temp = *cur;
        *cur = (*cur)->right;
        free(temp);
    } else {
        sset_extractMin_rec(&((*cur)->left), minElem, compare);
    }
}

void sset_extractMax_rec(TreeNodePtr* cur, void** maxElem, int (*compare)(void*, void*)) {
    if ((*cur)->right == NULL) {
        *maxElem = (*cur)->elem;
        TreeNodePtr temp = *cur;
        *cur = (*cur)->left;
        free(temp);
    } else {
        sset_extractMax_rec(&((*cur)->right), maxElem, compare);
    }
}

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
    if (!ss) return -1;
	if (ss->size == 0) return 0;

	TreeNodePtr node = ss->root;
	while(node) {
		if (elem > node->elem) {
			node = node->right;
		} else if (elem < node->elem) {
			node = node->left;
		} else {
			return 1;
		}
	}

	return 0;
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
	if (!ss) return -1;
    return ss->size == 0;
} 

// restituisce il numero di elementi presenti nell'insieme
int sset_size(const SortedSetADT* ss) {
    if (!ss) return -1;
	return ss->size;
}



// {3, 5, 7} - {7, 5, 3}
int sset_equals_rec(const SortedSetADT* s1, const SortedSetADT* s2, TreeNodePtr node1, TreeNodePtr node2) {
	if (!node1 && !node2) return true;
	if (!node1 || !node2) return false;

	if (sset_member(s1, node2->elem)) return true;
	if (sset_member(s2, node1->elem)) return true;

	if (!sset_equals_rec(s1, s2, node1->left, node2->left) || !sset_equals_rec(s1, s2, node1->right, node2->right))
		return false; 

	// printf("compare %d e %d: %d\n", *(int*)node1->elem, *(int*)node2->elem, compare(node1->elem, node2->elem));
	return true;
}

// controlla se due insiemi sono uguali
int sset_equals(const SortedSetADT* s1, const SortedSetADT* s2) { 
    if (!s1 || !s2) return -1;

	return sset_equals_rec(s1, s2, s1->root, s2->root) && s1->size == s2->size;
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

	return sset_subseteq_rec(s1, s2, s1->root);
}

// controlla se il primo insieme e' incluso strettamente nel secondo
int sset_subset(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return -1;
    
    return sset_subseteq(s1, s2) && (s1->size < s2->size);
} 

SortedSetADTptr sset_subtraction_rec(const SortedSetADT* s1, const SortedSetADT* s2, SortedSetADT* s3, TreeNodePtr node) {
	if (!node) return s3;

	sset_subtraction_rec(s1, s2, s3, node->left);
	sset_subtraction_rec(s1, s2, s3, node->right);

	if (!sset_member(s2, node->elem)) {
		sset_add(s3, node->elem);
	}
	
	return s3;
}

// restituisce la sottrazione primo insieme meno il secondo, NULL se errore
SortedSetADTptr sset_subtraction(const SortedSetADT* s1, const SortedSetADT* s2) {
	if (!s1 || !s2) return NULL;
	SortedSetADTptr s3 = mkSSet(s1->compare);
	if (!s3) return NULL;
	return sset_subtraction_rec(s1, s2, s3, s1->root);
} 

// restituisce l'unione di due insiemi, NULL se errore
SortedSetADTptr sset_union(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return NULL;
    SortedSetADTptr s3 = mkSSet(s1->compare);

	for (TreeNodePtr node = s1->root; node; node = node->left) 
		sset_add(s3, node->elem);

	for (TreeNodePtr node = s1->root; node; node = node->right) 
		sset_add(s3, node->elem);

	for (TreeNodePtr node = s2->root; node; node = node->left) 
		sset_add(s3, node->elem);

	for (TreeNodePtr node = s2->root; node; node = node->right) 
		sset_add(s3, node->elem);

	return s3;
} 

SortedSetADTptr sset_intersection_rec(const SortedSetADT* s1, const SortedSetADT* s2, SortedSetADTptr s3, TreeNodePtr node) {
	if (!node) return NULL;

	sset_intersection_rec(s1, s2, s3, node->left);
	sset_intersection_rec(s1, s2, s3, node->right);

	if (sset_member(s2, node->elem)) 
		sset_add(s3, node->elem);
		
	return s3;
}

// restituisce l'intersezione di due insiemi, NULL se errore
SortedSetADTptr sset_intersection(const SortedSetADT* s1, const SortedSetADT* s2) {
    if (!s1 || !s2) return NULL;
	SortedSetADTptr s3 = mkSSet(s1->compare);
	if (!s3) return NULL;

	sset_intersection_rec(s1, s2, s3, s1->root);
	sset_intersection_rec(s2, s1, s3, s2->root);

	return s3;
}

void* sset_min_rec(const SortedSetADT* ss, void** ptr, TreeNodePtr node) {
	if (!node->left)
		return node->elem;

	return sset_min_rec(ss, ptr, node->left);
}

// restituisce il primo elemento 
_Bool sset_min(const SortedSetADT* ss, void**ptr) {
	if (!ss) return false;
	if (!ss->root) return false;

	*ptr = sset_min_rec(ss, ptr, ss->root);
	return true;
}

void* sset_max_rec(const SortedSetADT* ss, void** ptr, TreeNodePtr node) {
	if (!node->right)
		return node->elem;

	return sset_max_rec(ss, ptr, node->right);
}

// restituisce il primo elemento 
_Bool sset_max(const SortedSetADT* ss, void**ptr) {
	if (!ss) return false;
	if (!ss->root) return false;

	*ptr = sset_max_rec(ss, ptr, ss->root);
	return true;
}

// toglie e restituisce il primo elemento 
_Bool sset_extractMin(const SortedSetADTptr ss, void**ptr) {
    if (!ss) return false;
	if (!ss->root) return false;

	sset_extractMin_rec(&ss->root, ptr, ss->compare);
	return true;
}

// toglie e restituisce l'ultimo elemento (0 se lista vuota, -1 se errore, 1 se restituisce elemento)
_Bool sset_extractMax(const SortedSetADTptr ss, void**ptr) {
    if (!ss) return false;
	if (!ss->root) return false;

	sset_extractMax_rec(&ss->root, ptr, ss->compare);
	return true;   
}

void** sset_toArray_rec(void** array, size_t* i, TreeNodePtr node, size_t size) {
	if (!node) return NULL;
	
	array[*i] = node->elem;
	(*i)++;
	sset_toArray_rec(array, i, node->left, size);
	sset_toArray_rec(array, i, node->right, size);

	return array;
}

// crea un array con i contenuti del set in ordine di visita pre-order, NULL se errore
void** sset_toArray(const SortedSetADT* ss) {
    if (!ss) return NULL;
	void** array = (void**) malloc(sizeof(void*) * ss->size);
	size_t i = 0;
	if (array) {
		sset_toArray_rec(array, &i, ss->root, ss->size);
	}
	return array;
}