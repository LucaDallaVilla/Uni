### Th. permanenza del segno (1)
$c,l \in \bar R, \space f:I(c)\backslash \{c\} \to R$
supponiamo che esista $\lim\limits_{x \to c} f(x)=l$.
1. Se $l>0 \space (o \space l=+\infty) \Rightarrow f(x)>0 \space x \to c$ 
2. Se $l<0 \space (o \space l=-\infty) \Rightarrow f(x)<0 \space x \to c$
In altre parole, $f(x)$ calcolata nell'intorno di $c$ mantiene lo stesso segno di $l$.

<u>Dimostrazione</u>: caso $l\in R, \space l>0, \space c\in R$
per ipotesi: $\lim\limits_{x \to c} f(x)=l \iff \space \forall \epsilon >0 \space \exists \delta >0:0<|x-c|<\delta \Rightarrow |f(x)-l|<\epsilon$

Scegliamo $\epsilon = \dfrac{l}{2}>0:$ allora $\exists \delta >0 : 0<|x-c|<\delta \Rightarrow l-\dfrac{l}{2}<f(x)<l+\dfrac{l}{2}$.
abbiamo dimostrare che $\exists \delta >0 : 0<|x-c|<\delta$ cioè $x \in I_\delta (c) \backslash \{c\}$, allora $f(x)>\dfrac{l}{2}>0$, cioè abbiamo trovato un intorno di $c$ in cui $f$ è $>0$.
<u>Osservazione</u>: Non si può dire nulla sul segno di $f$ se $\lim\limits_{x \to c} f(x)=0$. In generale, se $l=0$, $f$ potrebbe cambiare segno infinite volte vicino a $c$.
<u>Esempio</u>: $f(x)=x*sin\left(\dfrac{1}{x}\right)=0$. $f$ cambia segno infinite volte vicino a 0.

### Th. confronto (1) - limiti finiti
 $c \in \bar R$  $l \in R$   $f, g, h:I(c)\backslash\{c\} \to R$
 supponiamo:
 - $f(x) \leq g(x) \leq h(x)$    $\forall x \in I(c)\backslash \{c\}$
 - $\lim\limits_{x \to c} f(x)=l=\lim\limits_{x \to c} h(x)$
allora: $\lim\limits_{x \to c} g(x)=l$

<u>Dimostrazione</u>:
Vogliamo dimostrare che $\forall \epsilon >0$ $\exists I(c):x \in I(c)\backslash\{c\} \Rightarrow |g(x)-l|<\epsilon$.
Per ipotesi $\lim\limits_{x \to c} f(x)=l \Rightarrow$ per $\epsilon$ come sopra.
$\exists \space \tilde I(c):x \in \tilde I(c)\backslash\{c\} \Rightarrow |f(x)-l|<\epsilon$.
$\exists \hat I(c) : x \in \hat I(c)\backslash\{c\} \Rightarrow |h(x)-l|<\epsilon$.
Definiamo $I'(c)=\tilde I(c) \cap \hat I(c)$ in questo modo: $x \in I'(c)\backslash\{c\} \Rightarrow \begin{cases} l-\epsilon < f(x) < l+\epsilon \\ l-\epsilon < h(x) < l+\epsilon \end{cases}$ 
Se $x \in I'(c)\backslash\{c\}$, allora $l-\epsilon < f(x) \leq g(x) \leq h(x) < l+\epsilon$.
quindi $\forall \epsilon >0$ $\exists I'(c): x \in I'(c)\backslash\{c\} \Rightarrow l-\epsilon <g(x) < l+\epsilon$.

### Th. confronto (2) - limiti infiniti
$c \in \bar R$   $f, g:I(c)\backslash\{c\} \to R$
Supponiamo che $f(x) \leq g(x)$  $\forall x \in I(c)\backslash \{c\}$
Allora:
- se $\lim\limits_{x \to c} f(x)=+\infty \Rightarrow \lim\limits_{x \to c} g(x)=+\infty$
- se $\lim\limits_{x \to c} g(x)=-\infty \Rightarrow \lim\limits_{x \to c} f(x)=-\infty$
<u>Dimostrazione</u>:
- Vogliamo dimostrare che $\forall M>0$ $\exists I'(c):x \in I'(c)\backslash \{c\} \Rightarrow g(x) > M$
	Sappiamo che $\forall M>0$ $\exists \tilde I(c) : x \in \tilde I(c)\backslash\{c\} \Rightarrow f(x) > M$
	Quindi, dato $M>0$, poniamo $I'(c)=\tilde I(c)$
	$x \in I'(c) \backslash \{c\} \Rightarrow g(x) \geq f(x) > M$
	$x \in I'(c) \backslash \{c\} \Rightarrow g(x) > M$

### Esistenza dei limiti
$\nexists$ limite se $\exists$ limite sinistro e destro, diversi tra loro
Vi sono anche dei casi in cui non esistono né limite sinistro, né limite destro.
- $\lim\limits_{x \to +\infty} sin(x)$ continua a oscillare tra -1 ed 1 in ogni intervallo di ampiezza $2\pi$.
- $\lim\limits_{x \to 0} sin \left(\dfrac{1}{x}\right)$ fa infinite oscillazioni vicino a 0.
In entrambi i casi, le infinite oscillazioni comportano la non-esistenza del limite.

### Monotonia di una funzione
<u>Definizione</u>: $f:I\subseteq R \to R$, $f$ si dice:
- monotona crescente se $\forall x_1, x_2 \in I$, $x_1<x_2 \Rightarrow f(x_1)\leq f(x_2)$
- monotona strettamente crescente se $\forall x_1, x_2 \in I$, $x_1<x_2 \Rightarrow f(x_1) < f(x_2)$
- monotona decrescente se $\forall x_1, x_2 \in I$, $x_1<x_2 \Rightarrow f(x_1) \geq f(x_2)$
- monotona strettamente decrescente se $\forall x_1, x_2 \in I$, $x_1 < x_2 \Rightarrow f(x_1) > f(x_2)$

### Funzione limitata sup./inf.
<u>Definizione</u>: $f:I \subseteq R \to R$. $f$ si dice:
- limitata superiormente se $\exists b \in R : f(x) \leq b$  $\forall x \in I$.
- limitata inferiormente se $\exists a \in R : f(x) \geq a$   $\forall x \in I$.
- limitata se è limitata sia inferiormente, sia superiormente.
	$\exists a,b \in R: a\leq f(x) \leq b$   $\forall x \in I$

### Th. esistenza del limite per $f$ monotone.
Sia $f:(a, +\infty) \to R$  $a \in R$ monotona. Allora $\exists \lim\limits_{x \to +\infty} f(x)=l$.
1. se $f$ è crescente e superiormente limitata da $B$, allora $l \in R$ e $l \leq B$ (con $f(x) \leq B$  $\forall x \in (a, +\infty)$).
2. se $f$ è crescente ma non superiormente limitata da B, allora $l=+\infty$.
3. se $f$ è decrescente e inferiormente limitata da $b$, allora $l \in R$ e $l \geq b$ (con $f(x) \geq b$  $\forall x \in R$).
4. se $f$ è decrescente ma non inferiormente limitata da $b$, allora $l=-\infty$.

<u>Osservazioni</u>:
- Vale un enunciato analogo se $f:(-\infty, a) \to R$.
- Vale un enunciato simile se $f:(a,b) \to R$.
	>$f:(a,b) \to R$ monotona. Allora $\exists \lim\limits_{x \to b^-} f(x)=l$ e $\exists \lim\limits_{x \to a^+} f(x)=l$.
- Ci sono casi di funzioni che oscillano ma hanno limite. Vedi $\lim\limits_{x \to 0} x sin\left(\dfrac{1}{x}\right)=0$. Qui ci sono infinite oscillazioni di ampiezza sempre più piccola.
### Th. Weierstrass
Sia $f:[a,b] \to R$ continua nell'intervallo chiuso e limitato. Allora esistono $x_m$ e $x_M$ in $[a,b]$ tali che $f(x_m) \leq f(x) \leq f(x_M)$   $\forall x \in [a,b]$.
- $x_m$ e $x_M$ si dicono punti di minimo (assoluto) e punto di massimo (assoluto).
- $f(x_m)$ e $f(x_M)$ si chiamano minimo (assoluto) e massimo (assoluto).

<u>Osservazione</u>: In generale, $x_m$ e $x_M$ non sono unici, ma i minimi e massimi assoluti sì.
![[Pasted image 20240313121908.png]]

### Th. Continuità-derivabilità
Sia $f:I(c) \to R$. Se $f$ è derivabile in $x=c$, allora $f$ è continua in $c$.

<u>Dimostrazione</u>: Dobbiamo dimostrare che $\lim\limits_{x \to c} f(x)=f(c)$. Ovvero che $\lim\limits_{x \to c} f(x)-f(c)=0$.
$\forall x \neq c$   $f(x)-f(c)=\dfrac{f(x)-f(c)}{x-c}*(x-c)$. Essendo $f$ derivabile per ipotesi, $f'(c) \in R$. Quindi $\lim\limits_{x \to c} (f(x)-f(c))=f'(c)*0=0$.
<u>Osservazione</u>: Il viceversa è falso. Una funzione continua in un punto, può non essere derivabile in quel punto. [[Limiti#Punti dove il limite non esiste]]

### Th. di Lagrange
Sia $f:[a,b] \to R$ continua in $[a,b]$ chiuso e limitato, e derivabile in $(a,b)$. Allora $\exists c \in (a,b)$ tale che $f'(c)=\dfrac{f(b)-f(a)}{b-a}$.
![[Pasted image 20240319103734.png|800]]
Questo teorema dice sostanzialmente che esiste almeno una retta tangente alla funzione all'interno dell'intervallo con la stessa pendenza della retta che passa per gli estremi dell'intervallo (AB).
Nella interpretazione cinematica, quindi in un grafico spazio-tempo, il teorema ci dice che in almeno un punto di un percorso, il corpo ha avuto velocità pari a quella media.

<u>Corollario</u>: Caratterizzazione di funzioni a derivata =0. Sia $f:(a,b) \to R$ derivabile. Allora $f'(x)=0$  $\forall x \in (a,b) \iff \exists k \in R$ tale che $f(x)=k$  $\forall x \in (a,b)$.
<u>Corollario</u>: Caratterizzazione di funzione a derivata seconda =0. Sia $f:(a,b) \to R$ 2 volte derivabile. Allora $f''(x)=0$  $\forall x \in (a,b) \iff \exists m,q \in R$ tale che $f(x)=mx+q$.
<u>Corollario</u>: Caratterizzazione di primitive di una $f$. Sia $f:(a,b) \to R$. Allora
- $F$ è una primitiva di $f \Rightarrow F(x)+c$ è ancora una primitiva $\forall c \in R$
- se $F_1$ e $F_2$ sono 2 primitive di $f$, allora $\exists c \in (a,b)$ tale che $F_1(x)-F_2(x)=c$    $\forall x \in (a,b)$.

### Th. test di monotonia
Sia $f:(a,b) \to R$ derivabile. Allora
- $f$ è crescente su $(a,b) \iff f'(x) \geq 0$   $\forall x \in (a,b)$
- $f$ è decrescente su $(a,b) \iff f'(x) \leq 0$    $\forall x \in (a,b)$
<u>Osservazione</u>: è importante che $f$ sia definita su un intervallo.

<u>Dimostrazione</u>: Dimostriamo il punto 1, in quanto le altre dimostrazioni sono analoghe.
- $\Rightarrow$
	Supponiamo che $f$ sia crescente su $(a,b)$:
	$\forall x,z \in (a,b), x \neq z \Rightarrow \begin{cases} x<z \Rightarrow f(x) \leq f(z) \\ x>z \Rightarrow f(x) \geq f(z) \end{cases}$ 
	Fissiamo $x \in (a,b)$ arbitrariamente, quindi consideriamo il quoziente di Newton: $\dfrac{f(z)-f(x)}{z-x}=\begin{cases} x<z \Rightarrow \dfrac{\geq 0}{>0}=\geq 0 \\ x>z \Rightarrow \dfrac{\leq 0}{<0}=\geq 0 \end{cases} \Rightarrow \geq 0$
	$\forall z \in (a,b)$. Passiamo al limite $z \to x$: $f'(x)=\lim\limits_{z \to x} \dfrac{f(z)-f(x)}{z-x} \geq 0$ (cfr. [[Teoremi#Th. permanenza del segno (1)]])
- $\Leftarrow$ 
	Supponiamo $f'(x) \geq 0$  $\forall x \in (a,b)$
	Vogliamo dimostrare che $\forall x_1, x_2 \in (a,b):x_1<x_2 \Rightarrow f(x_1) \leq f(x_2)$. Usiamo il [[Teoremi#Th. di Lagrange]] in $[a,b]$.
	$\exists c \in (x_1, x_2)$ tale che $f'(c)=\dfrac{f(x_2)-f(x_1)}{x_2-x_1} \Rightarrow f(x_2)-f(x_1)=f'(c)(x_2-x_1) \geq 0$
	cioè $f(x_2) \geq f(x_1)$.
<u>Corollario</u>: Sia $f:(a,b) \to R$ 2 volte derivabile. Allora:
- $f'$ è crescente su $(a,b) \iff f''(x) \geq 0$   $\forall x \in (a,b)$
- $f'$ è decrescente su $(a,b) \iff f''(x) \leq 0$   $\forall x \in (a,b)$

### Th. test di concavità
Sia $f:(a,b) \to R$ derivabile. Allora:
- $f$ è convessa su $(a,b) \iff f'$ è crescente su $(a,b)$.
- $f$ è concava su $(a,b) \iff f'$ è decrescente su $(a,b)$.

<u>Dimostrazione</u>: Dimostriamo il punto 1.
- $\Rightarrow$
	$f$ è convessa su $(a,b)$ per ipotesi. Vogliamo dimostrare che $\forall x_1, x_2 \in (a,b)$ con $x_1<x_2$: $f'(x_1) \leq f'(x_2)$
	$f(x) \leq f(x_1)+\dfrac{f(x_2)-f(x_1)}{x_2-x_1}*(x-x_1)$   $\forall x \in [x_1, x_2]$
	Consideriamo la funzione ausiliaria $g:[x_1,x_2] \to R$
	$g(x)=f(x)-f(x_1)-\dfrac{f(x_2)-f(x_1)}{x_2-x_1} (x_2-x_1)$  (1)
	Sappiamo che $g(x) \leq 0$  $\forall x \in [x_1, x_2]$ sempre perché $f$ è convessa.
	Si può calcolare che $g(x_1)=0$ e $g(x_2)=0$.
	Dimostriamo che $g'(x_1) \leq 0$ e $g'(x_2) \geq 0$  (2)
	1. se $x>x_1 \Rightarrow \dfrac{g(x)-g(x_1)}{x-x_1} \leq 0$
		$g'(x_1)=\lim\limits_{x \to x_1^+} \dfrac{g(x)-g(x_1)}{x-x_1} \leq 0$  per [[Teoremi#Th. permanenza del segno (1)]]
	2. se $x<x_2 \Rightarrow \dfrac{g(x)-g(x_2)}{x-x_2}=\geq 0$ 
		$g'(x_2)=\lim\limits_{x \to x_2^-} \dfrac{g(x)-g(x_2)}{x-x_2} \geq 0$ per [[Teoremi#Th. permanenza del segno (1)]]
	$g'(x)=f'(x)-\dfrac{f(x_2)-f(x_1)}{x_2-x_1}$   $\forall x \in [x_1, x_2]$ (3)
	(2) ci suggerisce che $f'(x_1) \leq \dfrac{f(x_2)-f(x_1)}{x_2-x_1}$ e $f'(x_2) \geq \dfrac{f(x_2)-f(x_1)}{x_2-x_1}$.
	Quindi $f'(x_2) \geq \dfrac{f(x_2)-f(x_1)}{x_2-x_1} \geq f'(x_1)$.
- $\Leftarrow$
	Supponiamo che $f'$ sia crescente in $(a,b)$ e mostriamo che $f$ è convessa, cioè che $\forall x_1, x_2 \in (a,b)$, la funzione $g$ definita nella (1) sia tale che $g(x) \leq 0$   $\forall x \in [x_1, x_2]$. Ricordiamo che $g(x_1)=0 e g(x_2)=0$. 
	Per la (3) $g'$ è crescente $\iff f'$ è crescente in quanto differiscono solo per una costante.
	$\Rightarrow g'$ è crescente per ipotesi.
	Per [[Teoremi#Th. di Lagrange]] $\exists c \in (x_1, x_2)$ tale che $g'(c)=\dfrac{g(x_2)-g(x-1)}{x_2-x_1}=0$.
	Sappiamo dunque che la funzione è crescente, ma anche che si annulla per un punto $c$ intermedio a $[x_1, x_2]$.
	![[Pasted image 20240320121843.png]]
	Abbiamo che: $g'(x) \leq 0$   $\forall x \in [x_1, c]$ e $g'(x) \geq 0$   $\forall x\ \in [c, x_2]$
	Quindi necessariamente $g(x) \leq 0$   $\forall x \in [x_1, x_2]$

<u>Corollario</u>: $f:(a,b) \to R$ derivabile 2 volte. Allora:
- $f$ è convessa su $(a,b) \iff f''(x) \geq 0$   $\forall x \in (a,b)$
- $f$ è concava su $(a,b) \iff f''(x) \leq 0$   $\forall x \in (a,b)$