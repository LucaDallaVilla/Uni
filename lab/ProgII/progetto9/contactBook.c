#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "contactBook.h"
#include "sortedSetADT.h"

/**
 Un tipo di dato per una rubrica di contatti
*/

/* struct contact {
   char* name; 
   char* surname;
   char* mobile;
   char* url;
};

// nodo dell'albero
struct treeNode {
    void* elem;
    TreeNodePtr left, right;
};

// struttura contenente i dati fondamentali di un albero
struct sortedSetADT {
    TreeNodePtr root; // Punta alla radice dell'albero, se l'insieme e' vuoto vale NULL
    int (*compare)(void*, void*); // confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo
    int size; /* Numero di elementi presenti nell'insieme 
};
*/

struct contactBookADT {
    SortedSetADTptr contacts; // Tutto quello che serve è già in questa struttura
};

void stampaContact(void* elem) {
    ContactPtr contact = (ContactPtr)elem;
    printf("%s %s: %s (%s)", getName(contact), getSurname(contact), getMobile(contact), getUrl(contact));
}

void stampaBook_rec(TreeNodePtr node) {
    if (!node) return;
    
    stampaBook_rec(node->left);
    ContactPtr contatto = (ContactPtr) node->elem;
    printf("%s - ", contatto->surname);
    stampaBook_rec(node->right);
}

void stampaBook(ContactBookADTptr book) {
    if (!book || !book->contacts->root) return;

    ContactPtr root = (ContactPtr) book->contacts->root->elem;
    printf("(Root: '%s', size: %d) ", root->surname, book->contacts->size);
    stampaBook_rec(book->contacts->root);
    printf("fine\n");
}

int contact_cmp(void* c1, void* c2) {
    return cmpContact((ContactPtr)c1, (ContactPtr)c2);
}

// restituisce una rubrica vuota, NULL se errore
ContactBookADTptr mkCBook() {
    ContactBookADTptr newBook = (ContactBookADTptr) malloc(sizeof(ContactBookADT));
    SortedSetADTptr newSet = (SortedSetADTptr) malloc(sizeof(SortedSetADT));

    if (newBook && newSet) {
        newBook->contacts = newSet;
        newSet->compare = &contact_cmp;
        newSet->root = NULL;
        newSet->size = 0;
    } else {
        // qualcosa è andato storto
        // libera gli eventuali malloc
        free(newBook);
        free(newSet);
        newBook = NULL;
        newSet = NULL;
    }

    return newBook;
}

// elimina i nodi dell'albero, recuperando spazio in memmoria
_Bool dsNodes_rec(TreeNodePtr node) {
    if (!node) return true;
    dsNodes_rec(node->left);
    dsNodes_rec(node->right);
    free(node);
    return true;
}

// distrugge la rubrica, recuperando la memoria, false se errore
_Bool dsCBook(ContactBookADTptr* book) {
    if (!book || !(*book)) return false;
    // libero prima tutti i nodi, per recuperare memoria
    dsNodes_rec((*book)->contacts->root);
    free((*book)->contacts);
    free(*book);
    *book = NULL;
    return true;
}

// controlla se la rubrica e' vuota, -1 se NULL
int isEmptyCBook(const ContactBookADT* book) {
    if (!book) return -1;
    return book->contacts->size == 0;
}

// restituisce il numero di contatti presenti nella rubrica, -1 se NULL
int cbook_size(const ContactBookADT* book) {
    if (!book) return -1;
    return book->contacts->size;
}

// aggiunge un contatto alla rubrica (restituisce false se l'elemento era gia' presente, true altrimenti)
_Bool cbook_add(ContactBookADTptr book, ContactPtr cnt) {
    if (!book) return false;
    return sset_add(book->contacts, cnt);
}

// Funzione per trovare il nodo minimo in un albero binario
// trovo il minimo spostandomi sempre verso sinistra nell'albero
TreeNodePtr findMin(TreeNodePtr node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// toglie un elemento all'insieme (restituisce false se l'elemento non era presente, true altrimenti)
_Bool cbook_remove(ContactBookADTptr book, char* name, char* surname) {
    if (!book) return false;
    return sset_remove(book->contacts, mkContact(name, surname, NULL, NULL));
}

ContactPtr cbook_search_rec(TreeNodePtr node, int (*compare)(void*, void*), char* name, char* surname) {
    if (!node) return NULL;
    ContactPtr contactNode = (ContactPtr) node->elem;
    // se sia il nome sia il cognome corrispondono ho trovato il contatto
    if (strcmp(contactNode->name, name) == 0 && strcmp(contactNode->surname, surname) == 0) return node->elem;

    ContactPtr ret1 = cbook_search_rec(node->left, compare, name, surname);
    ContactPtr ret2 = cbook_search_rec(node->right, compare, name, surname);
    // controllo se ho già trovato un contatto nelle chiamate precedenti
    if (ret1) return ret1;
    if (ret2) return ret2;
    return false;
}

// restituisce un puntatore al contatto con dato nome e cognome (può essere usata per accedere o modificare il numero e url del contatto), NULL se non presente
ContactPtr cbook_search(const ContactBookADT* book, char* name, char* surname) {
    if (!book) return NULL;
    return cbook_search_rec(book->contacts->root, book->contacts->compare, name, surname);
}

// funzione per rimuovre gli spazi vuoti data una stringa
void rm_spaces(char* str) {
    int c=0;

    for (size_t i=0; str[i]; ++i) {
        if (str[i] != ' ') {
            str[c] = str[i];
            c++;
        }
    }

    // terminatore stringa
    str[c] = '\0';
}

// carica una rubrica da file, NULL se errore
ContactBookADTptr cbook_load(FILE* fin) {
    if (!fin) return NULL;
    ContactBookADTptr newBook = mkCBook();
    if (!newBook) return NULL;

    while (!feof(fin)) { // controlla se si è arrivati alla fine della lettura del file
        /* char name[50] = {0};
        char surname[50] = {0};
        char mobile[50] = {0};
        char url[50] = {0}; */

        char* name = malloc(sizeof(char) * 50);
        char* surname = malloc(sizeof(char) * 50);
        char* mobile = malloc(sizeof(char) * 50);
        char* url = malloc(sizeof(char) * 50);

        int result = fscanf(fin, "%49[^,],%49[^,],%49[^,],%49[^\n]\n", name, surname, mobile, url);
        // Se non ottengo tutti i risultati aspettati esco dal ciclo

        if (result < 2) {
            // Controllo se è veramente la fine del file o un errore di lettura
            if (feof(fin)) break;
            dsCBook(&newBook);
            return NULL;
        }

        rm_spaces(name);
        rm_spaces(surname);
        rm_spaces(mobile);
        rm_spaces(url);

        // printf("%s %s %s %s", name, surname, mobile, url);
        ContactPtr newContact = mkContact(name, surname, mobile, url);
        // stampaContact(newContact);
        if (!newContact) {
            dsCBook(&newBook);
            return NULL;
        }
        // se non si riesce ad aggiungere il contatto elimino lo spazio occupato in memoria
        if (!cbook_add(newBook, newContact)) {
            printf("Errore ad aggiungere contatto '%s'\n", newContact->surname);
            free(newContact);
        }

        free(name);
        free(surname);
        free(mobile);
        free(url);
    }

    stampaBook(newBook);
    return newBook;
}

/////////////////////////////////////////////////////////


void cbook_dump_rec(TreeNodePtr node, FILE* fout) {
    if(node!=NULL){
        // scrivo nel file gli elementi del contatto col seguente formato:
            // name,surname,mobile,url\n
        fprintf(fout, "%s,%s,%s,%s\n",
            getName(node->elem),
            getSurname(node->elem),
            getMobile(node->elem),
            getUrl(node->elem));
        cbook_dump_rec(node->left,fout);
        cbook_dump_rec(node->right,fout);
    }
}

// salva una rubrica su file, false se errore
_Bool cbook_dump(const ContactBookADT* book, FILE* fout) {
    if(fout == NULL || book == NULL){
        return false;
    }
    cbook_dump_rec(book->contacts->root, fout);
    return true;
}





int main() {
    return 0;
}