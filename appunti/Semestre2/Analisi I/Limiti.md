### Rapporto incrementale
È il tasso medio di variazione della $f$ nel passaggio da due punti $x_0$ e $x_1$.
Si calcola facendo il rapporto tra l'incremento della della $y$ e quello della $x$: $\dfrac{\Delta f}{\Delta x} = \dfrac{f(x_1)-f(x_0)}{x_1-x_0}$.

<u>Proposizione</u>: $m$, il coefficiente angolare di una retta, corrisponde al rapporto incrementale, a prescindere dai punti scelti.
<u>Dimostrazione</u>: $\dfrac{\Delta f}{\Delta x} = \dfrac{f(x_1)-f(x_0)}{x_1-x_0} = \dfrac{mx_1+q-(mx_0+q)}{x_1-x_0} = \dfrac{m(x_1-x_0)}{x_1-x_0} = m$

Questo vale per le rette, le quali mantengono lo stresso rapporto incrementale per qualsiasi 2 punti scelti, ma come si può calcolare la pendenza di una funzione curvilinea in un dato punto? Per fare ciò abbiamo bisogno di diminuire $\Delta x = x_1-x_0$ fino a quando tenderà a 0. In questo modo, il rapporto incrementale si avvicinerà sempre più al valore effettivo della pendenza di f in $x_0$.
$p_f=\lim\limits_{\Delta x \to 0}\left(\dfrac{f(x_0+\Delta x)-f(x_0)}{\Delta x}\right)$.
La retta tangente alla funzione nel punto $x_0$ avrà equazione $y=p_f(x_0)(x-x_0)+f(x_0)$.

### Punti dove il limite non esiste
- $f(x)=|x|$
	![[Pasted image 20240226184421.png]]
	È impossibile calcolare il limite di $f(x)$ in $x_0=0$ in quanto è un punto angoloso. Infatti se calcoliamo il rapporto incrementale tra $x_0$ e $x_1$ con quest'ultimo arbitrario, troviamo 2 soluzioni: $\dfrac{\Delta f}{\Delta x} = \dfrac{f(x_1)-f(x_0)}{x_1-x_0} = \dfrac{f(x_1)}{x_1} = \dfrac{|x_1|}{x_1} = \begin{cases} +1 \quad x_1>0 \\ -1 \quad x_1<0 \end{cases}$

- $f(x)=\sqrt[3]{x}$
	![[Pasted image 20240226185658.png]]
	Quando $x_1$ si avvicina a $x_0$ il rapporto incrementale aumenta fino a tendere ad infinito, non assumendo nessun valore reale.

La distanza di $x$ da 0 sulla retta reale è la lunghezza del segmento di estremi $[0,x]$.
Quindi $d(x,0)\begin{cases} x \quad x\geq0 \\ -x \quad x\leq0 \end{cases}=|x|$.
La distanza di $x$ da $y$ è la lunghezza del segmento di estremi $x$ e $y$, cioè:
$d(x,y)=\begin{cases} y-x \quad y\geq x \\ x-y \quad y<x \end{cases} = |y-x|$.

<u>Esercizi</u>:
1. Quali sono i punti della retta che distano al più 2 dall'origine.
> $\{x \in R:d(x,0)\leq 2\} = \{x \in R: |x| \leq 2\} = \{x \in R: -2 \leq x \leq 2\} = [-2, 2]$.
2. Quali sono i punti della retta che distano meno di 2 dall'origine.
> $\{x \in R:d(x,0)<2\} = \{x \in R: |x|<2\} = \{x \in R: -2<x<2\} = (-2, 2)$.
3. Quali sono i punti della retta che distano meno di 3 da punto 1.
> $\{x \in R:d(x,1)<3\}=\{x \in R: |x-1|<3\}=\{x \in R -3<x-1<3\} = \{x \in R: -2<x<4\}$

### Intorno
<u>Definizione</u>: Dato $c \in R$, si dice intorno di centro $c$ e raggio $r>0$, l'insieme $\{x \in R: d(x,c)<r\}=(c-r, c+r)\} = I_r(c)$.
Si dice che una proprietà vale definitivamente per $x$ che tende a $c$ (vale def. per $x \to c$) se esiste $r>0$ tale che la proprietà vale $\forall x \in I_r(c)$, tranne al più, che nel punto $c$.

<u>Esempio</u>: $\dfrac{1}{x^2}>1$ def. per $x \to 0$.
Infatti $\dfrac{1}{x^2}>1 \iff \begin{cases} x^2<1 \\ x \neq 0 \end{cases}$ $\iff \begin{cases} -1<x<1 \\ x \neq 0 \end{cases}$

### Retta reale estesa
$\bar R = R \cup \{-\infty\}\cup\{+\infty\}$.
Un intorno di $+\infty$ è un insieme del tipo $I_a(+\infty)=(a,+\infty)$  $a \in R$.
Un intorno di $-\infty$ è un insieme $I_a(-\infty)=(-\infty,a)$.

<u>Definizione</u>: Si dice che una proprietà è definitamente vera per $x \to \infty$ se esiste $a \in R \space | \space P(x) \space \forall x \in I_a(+\infty)$.
<u>Esempio</u>: $x^3 > 8$ per $x \to \infty$. $x^3 > 8 \iff x>2 \iff \forall x \in I_2(+\infty)=(2,+\infty)$.

### Limite finito al finito
![[Pasted image 20240305094838.png]]
$\lim\limits_{x \to a} f(x)=l \in R$.
Limite finito al finito significa che entrambi $a$ e $l$ appartengono a $R$.
"$|x-c|$ piccolo $\to |f(x)-l$ piccolo"
<u>Definizione</u>: Sia $f:I_r(c) \textbackslash \{c\} \to R$ e sia $l \in R$ si dice che $f$ tende a $l$ per $x$ che tende a $c$, e si scrive: $\lim\limits_{x \to c} f(x)=l$, se $\forall \epsilon>0 \space \exists \delta>0: 0<|x-c|<\delta \to |f(x)-l|<\epsilon$.
In termini di intorni:
<u>Definizione</u>: $\forall \epsilon > 0 \space \exists \delta > 0: x \in I_\delta(c) \textbackslash \{c\} \to f(x) \in I_l(R)$.
<u>Osservazione</u>: $\lim\limits_{x \to c} f(x)=l \iff \forall \epsilon>0$ la proprietà $f(x) \in I_\epsilon(l)$ è vera per $x \to c$.
<u>Esempio</u>: Per $\lim\limits_{x \to 0} x^2 = 0$, verifichiamo che $\forall \epsilon>0 \space \exists \delta >0 : 0<|x|<\delta \to |x^2|<\epsilon$.
Fissiamo $\epsilon >0$. $|x^2|<\epsilon \iff x^2<\epsilon \iff -\sqrt{\epsilon}<x<\sqrt{\epsilon}$.
$\forall \epsilon >0 : 0<|x|<\sqrt{\epsilon} \to |x^2|<\epsilon$.
La definizione di limite è verificata con $\delta = \sqrt{\epsilon}$.
<u>Osservazione</u>: Sia ora $f(x)=\begin{cases} x^2 \space x\neq0 \\ 5 \space x=0 \end{cases}$ 
$\lim\limits_{x \to 0} f(x)=0$. Nella definizione di limite non è coinvolto il valore della funzione in $x=c$, ma solo i valori "vicini".
In generale:
1. $f$ non definita in $c$.
2. $f$ definita in $c$ con $f(c)=l$
3. $f$ definita in $c$ ma con $f(c)\neq l$
In tutti questi casi $\lim\limits_{x \to c} f(x)=l$.

### Limite infinito al finito
$f(x)=e^{-x}$
![[Pasted image 20240305094909.png|400]]
$\lim\limits_{x \to +\infty} f(x)=l \in R$

<u>Definizione</u>: Sia $f:(a,+\infty) \to R$ e sia $l \in R$ si dice che $f$ tende a $l$ per $x$ che tende a $+\infty$, $\lim\limits_{x \to \infty} f(x)=l$ se $\forall \epsilon>0 \space \exists N>0 : x>N \to |f(x)-l|<\epsilon$.
In termini di intorni:
<u>Definizione</u>: $\forall \epsilon >0 \space \exists N>0 : x \in I_N(+\infty) \to f(x) \in I_\epsilon(l)$.
Se $\lim\limits_{x \to +\infty} f(x)=l \in R$, si dice che $y=l$ è un asintoto orizzontale destro per $f$.
<u>Osservazione</u>: Nel caso di limiti finiti, a volte si può parlare di limiti per eccesso o per difetto.
<u>Definizione</u>: $c \in \bar R, l \in R$. Se $\lim\limits_{x \to c} f(x)=l$ r $f(x)>l$ per $x \to c$, si dice che $f$ tende a $l$ per eccesso e si scrive $\lim\limits_{x \to c} f(x) = l^+$. Al contrario, se $\lim\limits_{x \to c} f(x)=l$ e $f(x)<l$ per $x \to c$, si dice che $f$ tende a $l$ per difetto e si scrive $\lim\limits_{x \to c} f(x)=l^-$.
<u>Esempio</u>: $\lim\limits_{x \to 0} x^2=0^+$
![[Pasted image 20240305102208.png|300]]

<u>Osservazione</u>: Non tutti i limiti sono per eccesso o per difetto.
<u>Esempio</u>: $f(x)=\dfrac{sin(x)}{x}$ 
![[Pasted image 20240305103021.png|700]]
$f(x) \to 0$ per $x \to +\infty$ ma né per eccesso né per difetto.

### Limite finito all'infinito
$f(x)=\dfrac{1}{x^2}$
![[Pasted image 20240306111240.png]]
$\lim\limits_{x \to c} f(x)=\pm \infty$
<u>Definizione</u>: $f:I_f(c)\backslash \{c\} \to R$. Si dice che $f(x)$ tende a $+\infty$ per $x$ che tende a $c$ se $\forall M>0 \space \exists \delta >0 : 0<|x-c|<\delta \to f(x)>M$
In termini di intorni:
$\lim\limits_{x \to c} f(x)=+\infty \iff \forall M>0 \space \exists \delta >0 : x \in I_f(c) \backslash \{c\} \to f(x) \in I_M(+\infty)$
Quando $\lim\limits_{x \to c} f(x)=\pm \infty$, si dice che $x=c$ è un asintoto verticale di $f(x)$.
<u>Osservazione</u>: Nel caso del grafico di $f(x)=\dfrac{1}{x}$, non si può dire che il $\lim\limits_{x \to 0} f(x) = \pm \infty$ per la definizione usata di $f(x)>M$.
Bisogna quindi parlare di $lim$ destro e sinistro e quindi di ramo destro o sinistro di intorno.
<u>Definizione</u>: Diciamo che $f(x)$ tende a $l \in R$ er $x$ che tende a $c$ da destra o sinistra, $\lim\limits_{x \to c^{\pm}} f(x)=l$, se $\forall \epsilon>0 \space \exists \delta >0 : 0<|x-c|<\delta \to |f(x)-l|<\epsilon$.
![[Pasted image 20240306113644.png]]

### Limite infinito all'infinito
$f(x)=x^2$
![[Pasted image 20240306114632.png|500]]
$\lim\limits_{x \to \pm \infty} f(c) = \pm \infty$
<u>Definizione</u>: diciamo che $f(x)$ tende a $+\infty$ per $x$ che tende a $+\infty$, $\lim\limits_{x \to +\infty} f(x)=+\infty$, se $\forall M>0 \space \exists N>0 : x>N \to f(x)>M$
In termini di intorni:
$\lim\limits_{x \to +\infty} f(x)=+\infty \iff \forall M>0 \space \exists N>0 : x \in I_N(+\infty)$

### Definizione generale di limite
siano $c,l \in \bar R$
$\lim\limits_{x \to c} f(x) = l \iff \forall \text{ intorno } I(l) \space \exists \text{ un intorno } I(c) : x \in I(c) \backslash \{c\} \Rightarrow f(x) \in I(l)$.

### Proprietà algebriche dei limiti finiti
Sia $c \in \bar R$ e siano $f,g:I_\delta(c) \backslash \{c\} \to R$, siano $l,m \in R$.
Supponiamo che $\lim\limits_{x \to c} f(x)=l$ e $\lim\limits_{x \to c} g(x)=m$.
Allora:
- $\lim\limits_{x \to c} (f(x)+g(x))=l+m$
- $\lim\limits_{x \to c} f(x)g(x)=l*m$
- $m \neq 0 \space \lim\limits_{x \to c} \dfrac{f(x)}{g(x)}=\dfrac{l}{m}$

<u>Disuguaglianza triangolare</u>:
$|a+b|<|a|+|b|$   $\forall a,b \in R$
<u>Dimostrazione</u>: per definizione $-|a|\leq a\leq |a|$   $\forall a \in R$
sommando per tutti i termini: $-|a|-|b| \leq a+b \leq |a|+|b|$ ovvero $|a+b| \leq |a|+|b|$

[...] dimostrazione somma del limite di 2 funzioni (vedi punto 1 proprietà algebriche limiti finiti)

### Proprietà algebriche dei limiti parziali
Sia $c \in \bar R$, e siano $f, g, h, k: I(c) \backslash\{c\} \to R$ :
- $\lim\limits_{x \to c} f(x)=l \in R$
- $\lim\limits_{x \to c} g(x)=\lim\limits_{x \to c} h(x)=+\infty$
- $\lim\limits_{x \to c} k(x)=0^+$
allora:
1. $\lim\limits_{x \to c} (f(x)\pm g(x))=\pm \infty$
2. $\lim\limits_{x \to c} (g(x)+h(x))=+\infty$
3. $\lim\limits_{x \to c} \dfrac{f(x)}{g(x)}=0$ 
4. $\lim\limits_{x \to c} g(x)h(x)=+\infty$ 
5. $\lim\limits_{x \to c} \dfrac{f(x)}{k(x)}=\begin{cases}+\infty \text{    se l>0} \\ -\infty \text{   l<0} \\ \text{?    se l=0} \end{cases}$ 
<u>Osservazione</u>: Se cambiamo il segno di $g$ o di $h$, valgono le solite regole della moltiplicazione dei segni.
<u>Osservazione</u>: Non si può stabilire a priori il risultato di
- $\dfrac{+\infty}{+\infty}$
- $\dfrac{0}{0}$
- $+\infty -\infty$
- $+\infty * 0$

### Limiti notevoli
Sono una serie di limiti che danno luogo a delle forme indeterminate. Si possono risolvere studiando le funzioni coinvolte.
1. $\lim\limits_{x \to 0} \dfrac{sin(x)}{x}=1$      $\left( =\dfrac{0}{0} \right)$ 
	$sin(x) \sim x$   per $x \to 0$.
	![[Pasted image 20240313122808.png]]
2. $\lim\limits_{x \to 0} \dfrac{1-cos(x)}{x^2}=\dfrac{1}{2}$
	$1-cos(x) \sim \dfrac{1}{2}x^2$    per $x \to 0$
	<u>Dimostrazione</u>: $\dfrac{1-cos(x)}{x^2}*\dfrac{1+cos(x)}{1+cos(x)} = \dfrac{1-cos^2(x)}{x^2(1+cos(x))}=\dfrac{sin^2(x)}{x^2}*\dfrac{1}{1+cos(x)}=\left(\dfrac{sin(x)}{x}\right)^2*\dfrac{1}{1+cos(x)}=1^2*\dfrac{1}{2}=\dfrac{1}{2}$.
	![[Pasted image 20240313123451.png]]
3. $\lim\limits_{x \to 0}=\dfrac{log(1+x)}{x}=1$
	$log(1+x) \sim x$    per $x \to 0$
	![[Pasted image 20240313123704.png]]
4. $\lim\limits_{x \to 0} \dfrac{e^x-1}{x}=1$
	<u>Dimostrazione</u>: prendiamo $e^x-1=y$. Quindi $x=log(1+y)$. $y=e^x-1$, quindo $x \to 0$, $y=0$.
	$\lim\limits_{x \to 0} \dfrac{e^x-1}{x}=\lim\limits_{y \to 0} \dfrac{y}{log(1+y)}=1^{-1}=1$.
5. $\lim\limits_{x \to 0} \dfrac{(1+x)^{\alpha}-1}{\alpha x}=1$     $\forall \alpha \in R$
	cioè $(1+x)^{\alpha}-1 \sim \alpha x$    per $x \to 0$
	$(1+x)^{\alpha} \sim 1+ \alpha x$
	![[Pasted image 20240313124632.png]]

<u>Osservazioni</u>: In tutti i punti, eccetto il 2, abbiamo trovato la retta tangente alle funzioni.
Abbiamo quindi approssimato al 1° ordine (con potenze di grado 1).
Nel punto 2, abbiamo invece un'approssimazione di grado 2.
### Gerarchia degli infiniti
1. $\lim\limits_{n \to \infty} \dfrac{log_2 n}{n^x}=0$ perché i logaritmi tendono a infinito più lentamente delle potenze.
2. $\lim\limits_{n \to \infty} \dfrac{n^k}{n^j}=0$   $\forall j>k>0$
3. $\lim\limits_{n \to \infty} \dfrac{n^j}{q^n}=0$   $\forall j>0$, $\forall q>1$

