### Tipi di discontinuità
Sia $c \in R$ e sia $I(c)=(c-\delta, c+\delta)$ un suo intorno.
<u>Definizione</u>: Una funzione $f:I(c) \to R$ si dice continua in $c$ se $\lim\limits_{x \to c} f(x)=f(c)$, cioè se $\forall \epsilon>0$ $\exists \delta >0 : |x-c|<\delta \Rightarrow|f(x)-f(c)|<\epsilon$.
![[Pasted image 20240313111457.png|800]]
$f$ è continua in $c$ se il suo grafico, vicino a $c$, si può disegnare senza "staccare la penna dal foglio".
<u>Osservazione</u>: $f(x) = \begin{cases} x*sin\left(\dfrac{1}{x}\right)\text{ se x}\neq 0 \\ 0\text{ se x}=0 \end{cases}$
$f$ è continua in 0. Il grafico di una funzione continua può essere complicato.

Ci sono 2 (o anche 3) modi in cui $f$ può non essere continua in $c$ (cfr. immagine):
1. $\lim\limits_{x \to c} f(x)=l \in R$. Ma $f(c) \neq l$ o $f$ non è definita in $c$. Si può ottenere una funzione continua cambiando il suo valore in $c$.
2. $\lim\limits_{x \to c} f(x)$  $\nexists$ oppure tende a $\pm \infty$. In questo caso non è possibile modificare il valore di $f$ in $c$ di modo da renderla continua in $c$.
> Funzione "segnale": $f(x)=\begin{cases} 0 \text{   se x}<0 \\ 1 \text{   se x}\geq0 \end{cases}$ 

<u>Definizione</u>: $I \subseteq R$ intervallo, $f:I \rightarrow R$. Si dice che $f$ è continua su $I$ se è continua in ogni punto di $I$.
<u>Osservazione</u>: se $I=[a,b]$, per continuità in $a$ (rispettivamente in $b$) si intende $\lim\limits_{x \to a^+} f(x)=f(a)$ (e rispettivo $b^-$).

### Proprietà delle funzioni continue
1. Continuità delle funzioni elementari. Queste sono continue nel loro dominio.
> $x^n$   $n \in N$ è continua per tutto il dominio ($D=R$)
> $\sqrt[n]{x}$  $n \in N$ è continua per tutto il dominio $\left(\begin{cases} R \text{   se n è dispari} \\ (0, +\infty) \text{    se n è pari} \end{cases}\right)$ 
> $\dfrac{1}{x}$ è continua nel suo dominio in quanto il dominio esclude $x=0$, punto di discontinuità.
	
<u>Proposizione</u>: se $f,g:I(c) \rightarrow R$ sono continue in $c$, allora:
- $f \pm g$ 
- $f*g$
- $\dfrac{1}{f}$ purché $f(c) \neq 0$
sono funzioni continue in $c$

<u>Proposizione</u>: $I \subseteq R \rightarrow J \subseteq R \rightarrow R$.
$x \rightarrow f(x) \rightarrow g(f(x))=(g \circ f)(x)$ funzione composta.
Se $f$ è continua in $c$ e $g$ è continua in $f(c)$, allora $g \circ f$ è continua in $c$.