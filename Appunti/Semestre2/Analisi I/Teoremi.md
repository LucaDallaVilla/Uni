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

### Th. Formula di Taylor con resto di Lagrange
Sia $f:I(c) \to R$ di classe $C^{n+1}$ in $I(c)$.
Allora $\forall x \in I(c)$ $\exists \alpha_x$ compreso tra $c$ e $x$ tale che $E_n(x)=\dfrac{f^{(n+1)}(\alpha x)}{(n+1)!} (x-c)^{n+1}$.
$f(x)=T_{n,c}(x)+\dfrac{f^{(n+1)}(\alpha x)}{(n+1)!} (x-c)^{n+1}$.
<u>Osservazione</u>: $\alpha_x$ non è noto a priori.
<u>Osservazione</u>: $E_n(x)$ è più piccolo quanto più $n$ è grande per $x \to c$.

> $|(x-c)^{n+1}| \leq |(x-c)^n|$   per $x \sim c$
> $(n+1)! > n!$

<u>Osservazione</u>: $n=0$    $f(x)=f(c)+f'(\alpha_c)(x-c)$ è esattamente il th. di Lagrange.
<u>Osservazione</u>: Il th. ci dà una stima quantitativa dell'errore $E_n(x)=\dfrac{f^{(n+1)}(\alpha_x)}{(n+1)!} (x-c)^{n+1}$


> Supponiamo di sapere che $0<e<3$. Vogliamo stimare $\sqrt{2}$ usando il polinomio di Mac Laurin di $e^x$ di ordine 3.
> $T_{3,0}(x)=1+x+\dfrac{x^2}{2}+\dfrac{x^3}{6}$.
> $\sqrt{e}=e^{\frac{1}{2}}$
> $T_{3,0}(\frac{1}{2})=1,64583 ...$
>Quanto è fedele l'approssimazione $\sqrt{e} \sim T_{3,0}(\frac{1}{2})$?
>Il th. dice che $\left|E_3(\frac{1}{2})\right|=\left|\dfrac{f^{(4)}(\alpha x)}{4!}*\dfrac{1}{2}^4\right| leq \dfrac{M_3}{4!}*\dfrac{1}{16}$, dove $M_3=max \space t\in [0,\frac{1}{2}] e^t$ 
>Effettivamente $E_3$ è piccolo! => $|\sqrt{e}-1.64583| \leq 0,00451 ...$
>$|\sqrt{e}-1.64583|=0,00289 ... < 0.00451$


### Th. punto fisso di una successione
Sia $g:R \to R$ continua e sia $\{x_n\}$ una soluzione di (SD). Se $\exists\lim\limits_{n \to +\infty} x_n=l \in R$, allora $l$ è punto fisso di $g$.
<u>Dimostrazione</u>: Sappiamo che $\exists l=\lim\limits_{n \to \infty} x_n$. Ma allora $\lim\limits_{n \to \infty} x_{n+1}=l$ per la proprietà di base delle successioni.
$x_{n+1}=g(x_n) \Rightarrow \lim\limits_{n \to \infty} g(x_n)=l$. (1)
Ora, $g$ è continua: $\lim\limits_{x \to c} g(x)=g(c)$
$\lim\limits_{n \to \infty} x_n=l \Rightarrow \lim\limits_{n \to \infty} g(x_n)=g(\lim\limits_{n \to \infty x_n})=g(l) (2)$
Confrontando le equazioni (1) e (2) risulta $l=g(l)$, cioè la definizione di punto fisso. $\square$
<u>Osservazione</u>: Questo teorema dice che un sistema dinamico può convergere soltanto ad un punto di equilibrio.


### Teorema
Sia $g:R \to R$ di classe c', e sia $x^*$ un punto fisso di g. Allora:
- $|g'(x^*)|<1 \Rightarrow x^*$ è punto di equilibrio asintoticamente stabile.
- $|g'(x^*)|>1 \Rightarrow x^*$ è punto di equilibrio instabile.
<u>Osservazione</u>: Nel caso $g(x)=ax+b$, $g'(x)=a$.
per $|a|=1$ il teorema non dà informazioni

> $g(x)=qx(1-x)$, $q \in (0,4]$
> $\begin{cases} x_{n+1}=g(x_n) \\ x_0 \text{ assegnato in } (0, 1) \end{cases}$ 
> Questo modello viene usato in dinamica delle popolazioni (mappa logistica). Per questo motivo, si considera $x \geq 0$, $g(x)=qx-qx^2$ è una famiglia di parabola passanti per (0,0) e (1,0).
> Punti fissi di $g: x=g(x)$. 
> $x=qx-qx^2$
> $qx^2+x-qx=0$
> $x(qx+1-q)=0$
> $x_1=0$ e $x_2=\dfrac{q-1}{q} (\in (0,1) \forall q>1)$ sono i punti di equilibrio.
> Consideriamo i casi in cui:
> - $0<q<1$. Se si fa il grafico a ragnatela si vede che tutte le soluzioni con $x_0 \in (0,1)$ tendono a 0 per $n \to \infty$.
> - $q \in (0,1) \Rightarrow$ il teorema ci conferma che 0 è punto di equilibrio asintoticamente stabile.
> - $q>1$ Le soluzioni con dato iniziale in $(0,1)$ sembrano tendere a $x_2$ nel grafico a ragnatela, ma calcolando $g'(x_2)$ vediamo $x_2$ che è punto di equilibrio solo se $1<q<3$.
> <u>Osservazione</u>: In questo caso specifico, abbiamo asintoticamente stabilità anche per $q=1$. Ma non possiamo usare il teorema.

### Th. di esistenza degli zeri
Sia $f:[a,b] \to R$ continua. Se $f(a)*f(b)<0$, allora $\exists c \in (a,b) \text{ tale che } f(c)=0$. 
<u>Osservazione</u>: Se $f$ è continua e, negli estremi $a$ e $b$ ha segno opposto, allora $f(x)=0$ ha almeno una soluzione in $(a,b)$.
<u>Osservazione</u>: $f(c)=0 \to c$ si dice zero di $f$.
<u>Dimostrazione</u>: (metodo di bisezione). Supponiamo che $f(a)<0<f(b)$ per fissare le idee. Definiamo $c_1=\dfrac{a+b}{2}$, punto medio tra $a$ e $b$, e consideriamo $f(c_1)$.
- $f(c_1)=0 \Rightarrow$ il teorema è dimostrato.
- $f(c_1)>0$
Allora poniamo $a_1=a$ e $b_1=c_1$
- $f(c_1)<0$
Allora poniamo $a_1=c_1$ e $b_1=b$
In casi 2 e 3, abbiamo definito un nuovo intervallo $[a_1, v_1] \subset [a,b]$ tale che $f(a_1)<0<f(b_1)$, e $b_1-a_1=\dfrac{b-a}{2}$.
(Su $[a_1, b_1]$, valgono le ipotesi del teorema, ma $[a_1,b_1]$ ma lunghezza pari a quella di $[a,b]$ diviso 2).
Iteriamo e definiamo $c_2=\dfrac{a_1+b_1}{2}$, e consideriamo $f(c_2)$.
Nei casi 2 e 3 si definisce $[a_2,b_2] \subseteq [a_1,b_1]$ seguendo le stesse regole usate in precedenza. In questo modo, ci sono 2 possibilità: O in un numero finito di iterazioni, si giunge a un punto medio che è uno zero di $f$, o $\exists$ una successione di intervalli $[a_n,b_n]$ tale che:
1) $[a,b] \supseteq [a_1,b_1] \supseteq [a_2,b_2]$...
2) $b_n-a_n=\dfrac{b-a}{2^n}$
3) $f(a_n)<0<f(b_n)$
Da 1, possiamo dire che $a_{n+1} \geq a_n$ $\forall n$ e $b_{n+1} \leq b_n$ $\forall n$ $\Rightarrow$ $\{a_n\}$ e $\{b_n\}$ sono monotone, $a_n \to l_1 \in R$ e $b_n \to l_2 \in R$.
Per il punto 2, $l_2-l_1=\lim\limits_{n \to \infty}{(b_n-a_n)}=\lim\limits_{n \to \infty} \dfrac{b-a}{2^n}=0 \Rightarrow l_2=l_1$.
Poiché $f$ è continua $\lim\limits_{n \to \infty} f(a_n)=f(\lim\limits_{n\ to \infty}a_n)=f(l)$.
Per il punto 3 e per la permanenza del segno $f(l)=\lim\limits_{n \to \infty} f(a_n) \leq 0$ e $f(l)=\lim\limits_{n \to \infty} f(b_n) \geq 0$ $\to f(l)=0$. E $l$ è $l_0$ o cercato.

<u>Osservazione</u>:
- L'ipotesi di continuità è essenziale.
- Il teorema dà una condizione sufficiente, ma non necessaria.
- La procedura di dimostrazione ci dà un algoritmo per ottenere un valore approssimato di uno zero di $f$. Nel caso peggiore, l'errore vale $b_n-a_n=\dfrac{b-a}{2^n}$, cioè l'ampiezza dell'intervallo considerato. La condizione per avere un valore con un errore massimo di $\epsilon$ è: $n>log_2{\left(\dfrac{b-a}{\epsilon}\right)}$.
### Th. dei valori intermedi
Si combina il [[Teoremi#Th. Weierstrass]] e [[Teoremi#Th. di esistenza degli zeri]].
$f:[a,b] \to R$ continua, $[a,b]$ chiuso e limitato. Detti $m$ e $M$ il minimo e il massimo di $f$ su $[a,b]$, $\forall \lambda \in [m,M] \exists c_{\lambda} \in [a,b] \text{ tale che } f(c_{\lambda})=\lambda$.

### Th. di esistenza degli zeri (2)
$f:[a,b] \to R$ di classe $C^2$. Supponiamo che: 
1. $f(a)*f(b) < 0$
2. $f'$ e $f''$ non cambiano segno in $[a,b]$
3. $f(a)*f''(a)>0$, oppure
	3'. $f(b)*f''(b)>0.$

Allora $\exists ! c \in (a,b)$ tale che $f(c)=0$ e la successione $\{x_n\}$ definita da
$\begin{cases} x_0=a \\ x_{n+1}=x_n-\dfrac{f(x_n)}{f'(x_n)} \end{cases}$ se vale la 3.
oppure:
$\begin{cases} x_0=b \\ x_{n+1}=x_n-\dfrac{f(x_n)}{f'(x_n)} \end{cases}$ se vale la 3'.
converge a $c$.

<u>Osservazione</u>: L'ipotesi 2. dice che siamo in uno dei casi seguenti: $f$ è strettamente monotona e non cambia concavità.
$f''(a)*f''(b)>0$. Quindi, ricordando che $f(a)*f(b)<0$, una tra 3. e 3'. vale sempre.

<u>Dimostrazione</u>: Dall'esistenza degli zeri, già sappiamo che $\exists c \in (a,b) : f(c)=0$. $f$ è strettamente monotona per l'ipotesi 2. Quindi lo zero è unico.
Dobbiamo mostrare che:
1. $\{x_n\}$ è convergente 
2. $\lim\limits_{n \to \infty} x_n=c$

Dimostrazione 1.:
Supponiamo $f(a)>0$ e $f''(a)>0$ (caso $f$ crescente e convessa).
Definiamo la funzione $g(x)=x-\dfrac{f(x)}{f'(x)}$   $\forall x \in [a,b]$ e notiamo che:
- $g(c)=c-\dfrac{f(c)}{f'(c)}=c$ perché $f(c)=0$ ($c$ è punto fisso di $g$).
- $g$ è derivabile e $g'(x)=1-\dfrac{f'(x)*f'(x)-f(x)*f''(x)}{(f'(x))^2}=\dfrac{(f'(x))^2-(f'(x))^2+f(x)*f''(x)}{(f'(x))^2}=\dfrac{f(x)*f''(x)}{(f'(x))^2}>0$   $\forall x \in\ [a,c)$.
Se $x \in [a,c), f(x)>0, f''(x)>0$
$g$ è strettamente crescente in $[a,c)$.

Dimostriamo che $x_n<x_{n+1}<c$   $\forall n$ $(*)$
Se $n=0$, si ha $x_0=a$ e $x_1=x_0-\dfrac{f(x_0)}{f'(x_0)}=a-\dfrac{f(a)}{f'(a)}>a$
Inoltre, $x_1=g(x_0)=g(a)<g(c)=c$
Quindi $x_0<x_1<c \Rightarrow g(x_0)<g(x_1)<g(c)$, cioè $x_1<x_2<c$.
Iterando per induzione, $(*)$ vale $\forall n$.
$(*)$ ci dice che $\{x_n\}$ è crescente e limitata, $a \leq x_n < c$. Per l'esistenza del limite per successioni monotone, $\lim\limits_{n \to \infty} x_n=l \in R \cup \{+\infty\}$. Siccome $\{x_n\}$ è limitata, $l \in R$ e $\{x_n\}$ è convergente.

Dimostrazione 2.:
Dobbiamo mostrare che $l=c$. $x_{n+1}=x_n-\dfrac{f(x_n)}{f'(x_n)}$ passiamo al limite per $n \to \infty$. Siccome $f$ e $f'$ sono continue, otteniamo ($x_n \to l \Rightarrow x_{n+1} \to l$) $l=l-\dfrac{f(l)}{f'(l)}$.
L'unica soluzione è $f(l)=0$ in quanto $f'(l) \neq 0$. Quindi $l=c$ per unicità.

> $f(x)=e^x+x-3=0$
> Usando il metodo delle tangenti in $[0,3]$ si ottiene un valore approssimato con un errore $<10^{-4}$ in sole 5 iterazioni. Quindi molto più efficienti.
>Verifichiamo che le ipotesi del teorema siano soddisfatte.
>$f \in C^2([0,3])$
>$f'(x)=e^x+1>0$   $\forall x$
>$f''(x)=e^x>0$    $\forall x$
>$f(0)<0<f(3)$ in questo caso vale 3', $f(3)*f''(3)>0$ e $f(0)*f''(0)<0$
>$\begin{cases} x_0=3 \\ x_{n+1}=x_n-\dfrac{f(x_n)}{f'(x_n)} \end{cases}$
