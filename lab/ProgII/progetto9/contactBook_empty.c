#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "contactBook.h"
#include "sortedSetADT.h"

/**
 Un tipo di dato per una rubrica di contatti
*/
struct contactBookADT {
    SortedSetADTptr contacts; // Puntatore al primo contatto
};

struct sortedSetADT {
    ContactPtr root; /* Punta alla radice dell'albero, se l'insieme e' vuoto vale NULL */
    int (*compare)(void*, void*); /* confronto tra due elementi: -1,0,1 se primo precede, uguale o segue il secondo */
    int size; /* Numero di elementi presenti nell'insieme */
};

struct contact {
    
   char* name; 
   char* surname;
   char* mobile;
   char* url;
};

void stampaContact(void* elem) {
    ContactPtr contact = (ContactPtr)elem;
    printf("%s %s: %s (%s)", getName(contact), getSurname(contact), getMobile(contact), getUrl(contact));
}

int contact_cmp(void* c1, void* c2) {
    return cmpContact((ContactPtr)c1, (ContactPtr)c2);
}

_Bool strcmp(char* str1, char* str2) {
    size_t i = 0;
    for (; str1[i] && str2[i]; ++i) {
        if (str1[i] != str2[i]) return false;
    }
    return str1[i] == str2[i] // controlla se entrambe le stringhe hanno il terminatore "\0" nella stessa posizione
}

// restituisce una rubrica vuota, NULL se errore
ContactBookADTptr mkCBook() {
    ContactBookADTptr newBook = (ContactBookADTptr) malloc(sizeof(ContactBookADT));

    if (newBook) {
        newBook->first = NULL;
        newBook->size = 0;
    }

    return newBook;
}

// distrugge la rubrica, recuperando la memoria, false se errore
_Bool dsCBook(ContactBookADTptr* book) {
    if (!book || !(*book)) return false;

    free(*book);
    book = NULL;
    return true;
}

// controlla se la rubrica e' vuota, -1 se NULL
int isEmptyCBook(const ContactBookADT* book) {
    if (!book) return -1;
    return book->size == 0;
}

// restituisce il numero di contatti presenti nella rubrica, -1 se NULL
int cbook_size(const ContactBookADT* book) {
    if (!book) return -1;
    return book->size;
}

// aggiunge un contatto alla rubrica (restituisce false se l'elemento era gia' presente, true altrimenti)
_Bool cbook_add(ContactBookADTptr book, ContactPtr cnt) {
    if (!book) return false;
    if (cbook_search(book, cnt->name, cnt->surname)) return false;

    SortedSetADTptr set = book->first;
    while (set->nextContact)
        set = set->nextContact;

    set->nextContact = cnt;
    return true;
}

// toglie un elemento all'insieme (restituisce false se l'elemento non era presente, true altrimenti)
_Bool cbook_remove(ContactBookADTptr book, char* name, char* surname) {
    if (!book || !book->first) return false;
    ContactPtr prevContact = book->first->contact;
    ContactPtr contact = book->first->nextContact;
    while (contact) {
        if (strcmp(contact->name, name) && strcmp(contact->surname, surname)) {

        }
    }
}

// restituisce un puntatore al contatto con dato nome e cognome (può essere usata per accedere o modificare il numero e url del contatto), NULL se non presente
ContactPtr cbook_search(const ContactBookADT* book, char* name, char* surname) {
    return NULL;
}

// carica una rubrica da file, NULL se errore
ContactBookADTptr cbook_load(FILE* fin) {
    return NULL;
}

// salva una rubrica su file, false se errore
_Bool cbook_dump(const ContactBookADT* book, FILE* fout) {
    return false;
}