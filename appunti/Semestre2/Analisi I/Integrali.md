Data una funzione $f:(a,b) \to R$












### Integrale indefinito
<u>Teorema</u>: Sia $f:(a,b) \to R$, allora:
1. $g$ è una primitiva di $f$ in $(a,b) \Rightarrow g+c$ è una primitiva $\forall c \in R$
2. $g$ e $h$ sono primitive della funzione in $(a,b) \Rightarrow g(x)-h(x)=c \forall x \in (a,b)$ per un certo c $\in R$

<u>Osservazione</u>: Le primitive sono univocamente determinate a meno di constanti additive.
<u>Definizione</u>: $f:(a,b) \to R$. L'insieme di tutte le primitive di $f$ si dice integrale indefinito di $f$: $\displaystyle\int f(x)dx$.

> Esercizio: Dato il grafico di $v(t)$:
> ![[Pasted image 20240227092012.png]]
> 1. descrivi il moto.
	Nell'intervallo [0,1] accelera, in [1,2] rallenta. 
	Il punto inverte il moto e si sposta verso sinistra in [2,3].
>2. sapendo che $s(0)=2$ tracciare un grafico qualitativo di $s(t)$.
	Non conosco alcun punto per $s$, possiamo quindi solo descrivere la monotonia e la convessità della funzione.

### Integrale definito
Calcolo delle aree: $f:[a,b] \to R$.

Fissiamo $n \geq 1$ Dividiamo $[a,b]$ in $n$ sotto intervalli di ampiezza $\dfrac{b-a}{n}$ con $x_i=a+i\dfrac{b-a}{n}$ per $i=0, ..., n$.
Scegliamo dei punti di campionamento $z_{i-1} \in [x_i,...,x_i$] in modo arbitrario.
Poi definiamo $g:[a.b] \to R$ ponendo $g(x)=f(z_i) se \space x \in [x_{i-1}, x_i)$
$g$ è una costante a tratti che descrive un plurirettangolo: la sua area è la somma delle aree dei singoli rettangoli.
$\sum\limits_{i=0}^{n}\dfrac{b-a}{n}*f(z_i) = S_n(f;z_1,...,z_n)$ è la somma di Riemann.
La somma di Riemann è un valore approssimato dell'area sottesa al grafico di $f$.
Se prendo $n$ sempre più grande, otterrò un'approssimazione migliore.

<u>Definizione</u>: se $\lim\limits_{n \to \infty} S_n(f;z_1, ..., z_n)$ esiste finito e non dipende dalla scelta degli $z_i$. Diciamo che $f$ è integrabile su $[a,b]$.
Il valore $\lim\limits_{n \to \infty} S_n(f; z_1, ..., z_n)$ si dice integrale definito di $f$ in $[a,b]$: $\displaystyle\int\limits_{a}^{b} f(x)dx$.
<u>Osservazione</u>:
- L'integrale definito è un numero, mentre l'integrale indefinito è un insieme di funzioni. In partenza, si tratta di oggetti completamente diversi.
- $\displaystyle\int\limits_{a}^{b}f(x)d(x) = \displaystyle\int\limits_{a}^{b}f(\sigma)d(\sigma) \space \forall \sigma \in R$.
- $\displaystyle\int\limits_{a}^{b}f(x)d(x)$ è un'area con segno e può essere negativa! Per ottenere l'area geometrica, calcolare $\displaystyle\int\limits_{a}^{b}|f(x)| d(x)$.
- L'integrale è usato per calcolare il lavoro di una forza (motore se favorisce lo spostamento, resistente se si oppone).
	Se $F$ è costante, allora $L_{F;[a,b]}=F*(b-a)$  se $F$ non è costante, $L_{F;[a,b]}=\displaystyle\int\limits_{a}^{b} F(s)ds$
- L'integrale si può anche considerare come un valore medio di una funzione. Dati $n$ numeri $y_1,...,y_n$ la loro media è $m=\dfrac{y_1+...+y_n}{n}$. Se $f:[a,b] \to R$ è una funzione, si può pensare di definire il suo valore medio prendendo n punti $z_1,...,z_n \in [a,b]$ e calcolando $\dfrac{f(z_1)+...+f(z_n)}{n}$ se $z_1,...,z_n$ sono presi come nella definizione di integrale $(z_i) \in [x_{i-1}{i}] \space \forall i$ allora $\dfrac{f(z_i)+...+f(z_n)}{n} = \sum\limits_{i=1}^{n} \dfrac{1}{b-a}*\dfrac{b-a}{n} f(z_i)=\dfrac{1}{b-a} \sum\limits_{i=1}^{n} \dfrac{b-a}{n}f(z_i)=\dfrac{1}{b-a} \displaystyle\int\limits_{a}^{b}f$.
<u>Definizione</u>: $\displaystyle\int\limits_{a}^{b} f(x)dx$ si dice media integrale di $f$ in $(a,b)$.
$\int\limits_{a}^{b} v(t)dt = \lim\limits_{n \to \infty} \sum\limits_{i=1}^{n} v(z_i)*\dfrac{b-a}{n} \simeq  \lim\limits_{n \to \infty} \sum\limits_{i=1}^{n}(s(t_1)-s(t_{t_1-1})) = \lim\limits_{n \to \infty}[(s(t_1)-s(t_0))+(s(t_2)-s(t_1))+(s(t_3)-s(t_2))+...+(s(t_n)-s(t_{n-1}))]$ si cancellano tutti i termini $s(t_i)$ con $i>0$.
Quindi risulta che: $\lim\limits_{n \to \infty} [(s(t_b)-s(t_a)] = s(b)-s(a)$.
In buona approssimazione: $\displaystyle\int\limits_{a}^{b} v(t)dt \simeq s(b)-s(a)$. Dimostreremo in futuro che in realtà corrispondono e non si tratta di un'approssimazione.
$\dfrac{1}{b-a}\displaystyle\int_{a}^{b}v(t)dt = \dfrac{s(b)-s(a)}{b-a}$ è il valore medio della velocità in un intervallo $[a,b]$.

$s(b)-s(a)=\displaystyle\int_{a}^{b} v(t)dt$ è un caso particolare del th. Torricelli-Barrow, il quale dice:
### Primo teorema fondamentale del calcolo integrale
se F è una primitiva di f, allora $\displaystyle\int_{a}^{b} f(x)dx=F(b)-F(a)$.
<u>Osservazione</u>: il calcolo di integrali definiti è ricondotto a quello di integrali indefiniti e viceversa.
Si può scrivere, più in generale, $F(x)=F(a)+\displaystyle\int_{a}^{x} f(t)dt \space \forall x \in [a,b]$ ed è definita come "funzione integrale" o "funzione di accumulazione".
$F(a)$ è una costante, mentre $F(x)$ varia in funzione di x.

### Secondo teorema fondamentale del calcolo integrale
<u>Definizione</u>: Sia $f:[a,b] \to R$ una funzione  e sia $G(x)=\displaystyle\int_{a}^{x}f(t)dt$, allora G è derivabile e $G'(x)=f(x)$, cioè $G$ è una primitiva di $f$.

### Proprietà
- <u>Linearità</u>: se $f$ e $g$ sono integrabili in $[a,b]$ e $\alpha$ e $\beta \in R$, allora $\alpha f+\beta g$ è integrabile su $[a,b]$ e $\displaystyle\int_{a}^{b} \left(\alpha f(x)+\beta g(x)\right)dx=\alpha \int\limits_{a}^{b} f(x)dx+\beta \int\limits_{a}^{b} g(x) dx$.
- <u>Additività rispetto al dominio</u>: se $f$ è integrabile su $[a,b]$ e $c \in (a,b)$, allora $f$ è integrabile su $[a,c]$ e su $[c,b]$, e $\displaystyle\int_{a}^{b} f=\int\limits_{a}^{c} f + \int\limits_{c}^{b} f$.
- <u>Area con segno</u>: l'integrale rappresenta l'area sottesa al grafico della funzione $f$. Bisogna però sottrarre le aree sotto l'asse delle ascisse.
	L'area geometrica invece somma i valori assoluti delle aree.

- <u>Integrale di costante</u>: equivale alla costante moltiplicata per $(b-a)$.