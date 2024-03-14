/**
 * @brief Converte una stringa in naturale (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non trova nessuna cifra valida
 *           (e in tal caso il valore all'indirizzo r non è significativo).
 *           Altrimenti restituisce 1, e scrive all'indirizzo r il numero intero rappresentato nella stringa nella base data.
 *           Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato3 tipicamente scorretto).
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <assert.h>


int stoub(char *s, unsigned short b, int* r) {
    char number[strlen(s)];
    int res = 0;
    int ret = 0;
    int length = 0;
    
    printf("STRING: %s\n", s);
    printf("LENGTH: %ld\n", strlen(s));
    printf("BASE: %d\n", b);
    
    if (b < 2 || b > 36) {
        ret = 1;
    }
    
    for (size_t i=0; s[i] != '\0'; i++) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            number[length] = s[i];
            printf("%c", number[length]);
            length++;
        }
    }
    number[length] = '\0';
    
    for (size_t i=length-1; i>=0; i--) {
        res += number[i] * pow(b, i);
    }
    
    *r = res;
    
    return ret;
}


int main(void) {
    int risultato;
    printf("RESULT: %d\n", stoub("\t -1", 12, &risultato));
    printf("NUMERO: %d\n", risultato);
}