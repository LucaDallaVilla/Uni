#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "contactOpq.h"

struct contact {
   char* name; 
   char* surname;
   char* mobile;
   char* url;
};

_Bool stringEq(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    
    for (int i=0; i<strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    
    return true;
}

ContactPtr mkContact(char* name, char* surname, char* mobile, char* url) {
    ContactPtr newContact = malloc(sizeof(struct contact));
    
    if (name == NULL || surname == NULL) {
        newContact = NULL;
    } else {
        newContact->name = name;
        newContact->surname = surname;
        newContact->mobile = mobile;
        newContact->url = url;   
    }
    
    return newContact;
}


void dsContact(ContactPtr* cntptr) {
    if (*cntptr != NULL) {
        free(*cntptr);
    }
    *cntptr = NULL;
}

void updateMobile(ContactPtr cnt, char* newMobile) {
    cnt->mobile = newMobile;
}


void updateUrl(ContactPtr cnt, char* newUrl) {
    cnt->url = newUrl;
}


char* getName(const ContactPtr cnt) {
    return cnt->name;
}

char* getSurname(const ContactPtr cnt) {
    return cnt->surname;
}

char* getMobile(const ContactPtr cnt) {
    return cnt->mobile;
}

char* getUrl(const ContactPtr cnt) {
    return cnt->url;
}

_Bool equalsContact(const ContactPtr cnt1, const ContactPtr cnt2) {
    return (stringEq(cnt1->name, cnt2->name) && stringEq(cnt1->surname, cnt2->surname));
}   

int cmpContact(const ContactPtr cnt1, const ContactPtr cnt2) {
    // printf("'%s' '%s' - '%s' '%s'\n", cnt1->name, cnt1->surname, cnt2->name, cnt2->surname);
    if (equalsContact(cnt1, cnt2)) return 0;

    for (int i=0; cnt1->surname[i] != '\0' && cnt2->surname[i] != '\0'; i++) {
        if (cnt1->surname[i] < cnt2->surname[i]) {
            return 1;
        } else if (cnt1->surname[i] > cnt2->surname[i]) {
            return -1;
        }
    }
    
    // stesso cognome -> controllo per nome
    for (int i=0; cnt1->name[i] != '\0' && cnt2->name[i] != '\0'; i++) {
        // printf("%c - %c (%d)\n", cnt1->name[i], cnt2->name[i], cnt1->name[i] < cnt2->name[i]);
        if (cnt1->name[i] < cnt2->name[i]) {
            return 1;
        } else if (cnt1->name[i] > cnt2->name[i]) {
            return -1;
        }
    }

    // nel caso vladmiro-vladimir ritorna 0 in quanto la cnt2->name è più corto al pari di nomi quasi uguali.
    return (strlen(cnt1->name) > strlen(cnt2->name))*2-1;
}