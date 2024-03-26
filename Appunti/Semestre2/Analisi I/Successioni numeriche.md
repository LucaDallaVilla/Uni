<u>Definizione</u>: una successione (numerica) è una funzione
$a:N \to R$.
$n \to a_n$

> $a:N\{0\} \to R$
> $n \to \frac{1}{n}$

<u>Notazione</u>: $\{a_n\}_n$ oppure $\{a_n\}$.

### Possibili applicazioni
- Riproduzione cellulare
	$n$ generazione -> $a_n$= numero di cellule in vita all'n-esima generazione.
- Complessità algoritmo
	$n$ dimensione dell'array dove compiere le operazioni, $O(n)$ il numero di operazioni da compiere.
- Integrale di Riemann
	$S_n(f;z_1, ..., z_n)=\dfrac{b-a}{n} \sum\limits_{k=1}^{n}f(z_k)$

Tipicamente ci sono 2 modi di assegnare una successione:
1. <u>Formula esplicita</u>: $a_n=\dfrac{1}{n}$
	>$a_n:\{n \in N:n \geq 1\} \to R$
	$n \to \dfrac{1}{n}$
2. <u>Formula ricorsiva</u>: 
> $\begin{cases} a_0=3 \\ a_{n+1}=a_n^2-a_n \end{cases}$ 

