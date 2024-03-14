```C
/∗∗ @brief Dato l’input x 1,...,x n (n >= 0) restituisce l’output z ∗
P−IN(x 1,...,x n): una condizione su x 1,...,x n (detta ‘‘predicato di input’’) ∗
P−OUT(x 1,...,x n,z): una condizione su x1,...,x n e z (detta ‘‘predicato di output’’) ∗/

t prog(t 1 x 1, ..., t n x n) {
	/∗ CORPO DELLA FUNZIONE ∗/
}
```

- <u>Correttezza parziale</u>: per ciascun parametro valido, se il programma termina, la funzione restituisce il valore corretto.
- <u>Terminazione</u>: se i parametri sono validi, il programma termina.
- <u>Correttezza</u>: entrambi i punti precedenti sono rispettati.

### Regole
Nei cicli, scrivere prima:
1. corpo del ciclo
2. condizione del ciclo
3. inizializzazione

### Procedimenti per scrivere una funzione
1. Inserire un commento in testa alla funzione per spiegare i parametri di ingresso e i valori in uscita.
2. Creo test per verificare la bontà della funzione.
3. Penso ad una soluzione in "pseudo-codice".
4. Scrivo la funzione.

