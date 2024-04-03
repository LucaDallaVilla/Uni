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
### Definizioni
Tipicamente ci sono 2 modi di assegnare una successione:
1. <u>Formula esplicita</u>: $a_n=\dfrac{1}{n}$
>$a_n:\{n \in N:n \geq 1\} \to R$
>$n \to \dfrac{1}{n}$
2. <u>Formula ricorsiva</u>: 
> $\begin{cases} a_0=3 \\ a_{n+1}=a_n^2-a_n \end{cases}$ 

<u>Definizione</u>: Una successione $\{a_n\}$ si dice:
- monotona crescente se $a_{n+1} \geq a_n$   $\forall n$
- monotona decrescente se $a_{n+1} \leq a_n$   $\forall n$
- inferiormente limitata se $\exists m \in R$ tale che $a_n \geq m$   $\forall n$
- superiormente limitata se $\exists M \in R$ tale che $a_n \leq M$   $\forall n$
- limitata se $\exists m, M \in R$ tale che $m \leq a_n \leq M$    $\forall n$

Per le successioni si definiscono anche i limiti quando $n \to +\infty$.
<u>Definizione</u>: Si dice che $a_n \to l \in R$ per $n \to +\infty$, $\lim\limits_{n \to +\infty}a_n=l$, se $\forall \epsilon >0$ $\exists N_{\epsilon} \in N$ tale che $n>N_{\epsilon} \Rightarrow |a_n-l|<\epsilon$
In questo caso, si dice che $\{a_n\}$ è convergente.
<u>Definizione</u>: $\{a_n\}$ tende a $\pm \infty$ per $n \to \infty$, $\lim\limits_{n \to \infty} a_n=\pm \infty$ se $\forall M>0$ $\exists N_{\epsilon} \in N : n>N_{\epsilon} \Rightarrow a_n >M$ oppure $a_n <-M$.
In questo caso si dice che $\{a_n\}$ è divergente.
<u>Definizione</u>: $\{a_n\}$ si dice indeterminata se non è né convergente né divergente (cioè se non ha limite).

<u>Osservazione</u>: Lo studio dei limiti di successione spesso è analogo a quello di funzione per $x \to \infty$.
> Algebra dei limiti, aritmetica di $\infty$, e alcuni teoremi ([[Teoremi#Th. permanenza del segno (1)]], [[Teoremi#Th. confronto (1) - limiti finiti]], [[Teoremi#Th. confronto (2) - limiti infiniti]]) si trasportano alle successioni senza grosse differenze.

> $\dfrac{1}{n+1}$ diventa $\lim\limits_{n \to +\infty} \dfrac{1}{+\infty}=0^+$
> $n^2$ diventa $+\infty$ per $n \to +\infty$
> $(-1)^n = \begin{cases} -1 \text{   se n è dispari} \\ +1 \text{   se n è pari} \end{cases}$

### Teoremi
1. Se $\{a_n\}$ è convergente $\Rightarrow$ la successione è limitata.
	<u>Osservazione</u>: Non vale il viceversa!
2. Se $\{a_n\}$ è una successione monotona, allora ha limite. In tutti i casi di monotonia crescente/decrescente e limite superiore/inferiore si ha un limite finito o infinito.
3. Se $\{a_n\}$ è tale che $\lim\limits_{n \to \infty} a_n=l \in \bar R$.
	Consideriamo per $m \in R$ fissato, $\{a_{n+m}\}_n$ (successione shiftata di $m$ indici) ha limite $\lim\limits_{n \to \infty} a_{n+m}=l$

### Successione geometrica
<u>Definizione</u>: Una successione si dice geometrica se $\exists q \in R$ ($q$ = base della successione) tale che $a_{n+1}=q*a_n$   $\forall n \in N$.

> se $a_0=0 \Rightarrow a_n=0$  $\forall n$
> se $a_0 \neq 0 \Rightarrow a_1=q*a_0, a_2=q*a_1=q^2*a_0, a_n=q^n*a_0$ (formula esplicita).

Fissiamo $a_0=1$ e studiamo $a_n=q^n$, $n \in N$ al variare del parametro $q \in R$.
1. $q=0 \to a_n=0$  $\forall n$ (limitata, costante, convergente)
2. $q=1 \to a_n=1^n=1$  $\forall n$ (limitata, costante, convergente)
3. $q=-1 \to a_n=(-1)^n$   $\forall n$ (limitata, non monotona, indeterminata)
4. $q>1 \to a_n=q^n$ (inf. limitata, sup. illimitata, crescente, divergente)
5. $0<q<1$ (limitata, decrescente, convergente)
6. $-1<q<0 \to a_n=(-1)^n |q|^n$ (limitata, non monotona, convergente)
7. $q<-1 \to a_n=(-1)^n |q|^n$ (illimitata sup. e inf., non monotona, indeterminata)

### Confronti di crescita
Date 2 successioni $\{a_n\}$ e $\{b_n\}$ tali che $\lim\limits_{n \to \infty} a_n=\lim\limits_{n\to \infty} b_n=+\infty$, quale è più grande?

| $n$    | $log_{2} n$ | $n^2$  | $3n^2+n$    | $n^3$  | $2^n$       |
| ------ | ----------- | ------ | ----------- | ------ | ----------- |
| 2      | 1           | 4      | 14          | 8      | 4           |
| 10     | 3,322       | $10^2$ | $3,1*10^2$  | $10^3$ | $>10^3$     |
| $10^2$ | 6,644       | $10^4$ | $3,01*10^4$ | $10^6$ | $>>10^{25}$ |
Si procede considerando il rapporto delle successioni: $\dfrac{a_n}{b_n}$.
<u>Definizione</u>: se $\lim\limits_{b \to \infty} \dfrac{a_n}{b_n}=0$, $\{a_n\}$ tende a $+\infty$ più lentamente di $\{b_n\}$.
Infatti, se i limiti risultano essere
- $\dfrac{+\infty}{+\infty}=F.I$
- $0=b_n$ è più grande
- $+\infty=a_n$ è più grande.
- $l \in (0, +\infty)=$ entrambe le successioni crescono con velocità analoga.

### Simboli di Landau
<u>Definizione</u>: $\{a_n\}$. Diciamo che una proprietà vale definitivamente per $a_n$ se la proprietà è vera $\forall n \geq n_0$, cioè è vera da un certo indice in poi.
<u>Definizione</u>: $\{a_n\}$ e $\{b_n\}$ successioni tali che $b_n \neq 0$ definitivamente. Diciamo che:
- $\{a_n\}$ è o-piccolo di $\{b_n\}$, $a_n=0(b_n)$ se $\lim\limits_{n \to \infty} \dfrac{a_n}{b_n}=0$.
- $\{a_n\}$ è o-grande di $\{b_n\}, a_n=O(b_n)$, se $\exists c>0$ tale che $\left|\dfrac{a_n}{b_n}\right| \leq c$  definitivamente per $n \to \infty$
- $\{a_n\}$ è theta-grande di $\{b_n\}$, a_n=$\theta (b_n)$ se $\exists c, C>0$ tali che $c \leq \left|\dfrac{a_n}{b_n}\right| \leq C$ definitivamente per $n \to \infty$
- $\{a_n\}$ è equivalente a $\{b_n\}$, $a_n \sim b_n$ se $\lim\limits_{n \to \infty} \dfrac{a_n}{b_n}=1$

<u>Osservazione</u>:
1. $a_n=o(b_n)$ vuol dire che $\{a_n\}$ cresce più lentamente di $\{b_n\}$. Quindi ad esempio:
	$\log_{a}n=o(n^k)$   $\forall a>1$ e $k>0$
	$n^k=o(n^j)$   $\forall 0<k<j$
	$n^j=o(q^n)$   $\forall j>0, q>1$
	$\lim\limits_{n \to \infty} \dfrac{a_n}{b_n}=+\infty \iff b_n=o(a_n)$

2. ...

	$\lim\limits_{n \to \infty} \left|\dfrac{a_n}{b_n}\right|=l$ esiste, allora $a_n=O(b_n)$ equivale a dire che $l\in [0, +\infty)$.

3. $a_n=\theta (b_n)$ vuol dire che $\{a_n\}$ cresce non più lentamente e non più velocemente di $\{b_n\}$. Quindi $a_n=\theta(b_n) \iff \begin{cases} a_n=O(b_n) \\ a_n \text{ non è } o(b_n) \end{cases}$
4. Se $\exists l=\lim\limits_{n \to \infty} \left| \dfrac{a_n}{b_n} \right|$, allora $a_n=\theta(b_n) \iff l \in (0, +\infty)$. Quindi $\{a_n\}$ e $\{b_n\}$ crescono con la stessa velocità.
5. $a_n \sim b_n$ vuol dire che non solo le due successioni crescono con la stessa velocità ma "sono sempre più simili".
	$a_n \sim b_n \Rightarrow a_n=\theta(b_n)$

In generale, $P(n)=a_0 n^k+a_1n^{k-1}+...+a_{k-1}n+a_k$  con $k \in N, k \geq 1, a_0, a_1, a_2,...,a_k \in R, a_0 \neq 0$
Allora, $P(n) \sim a_0n^k$
Infatti $\dfrac{P(n)}{a_0n^k}=\dfrac{a_0n^k(1+\dfrac{a_1n^{k-1}}{a_0n^k}+...+\dfrac{a_{k-1}n}{a_0n^{k-1}}+\dfrac{a_k}{a_0n^k}}{a_0n^k}=\dfrac{1+0}{1}=1$ per $n \to \infty$.
In conclusione, nello studio asintotico dei polinomi basta studiare i membri con grado massimo.
<u>Osservazione</u>: I simboli di Landau si possono introdurre anche per le funzioni $f,g:[a,+\infty) \to R$, con $g(x) \neq 0$ definitivamente per $x \to \infty$.
$f=0(g)$ se $\lim\limits_{x \to +\infty} \dfrac{f(x)}{g(x)}=0$.