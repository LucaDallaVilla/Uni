- Somma: G primitiva di $g$ e F primitiva di $f$, G+F è primitiva di $g+f$.
- Prodotto: $\beta F$ è primitiva di $\beta f$.

### Esercizi
1. $f(x)=2cosx+\dfrac{1}{x^3}-\sqrt[3]{x}$
	$F(x)=2sinx-\dfrac{1}{2}x^{-2}-\dfrac{3}{4}x^{\frac{4}{3}}+c$
2. $f(x)=\dfrac{1}{3}cos(4x)$
	$F(x)=\dfrac{1}{12} sin(4x)+c$ 
3. $f(x)=sin(2x+1)$
	$F(x)=-\dfrac{1}{2} cos(2x+1)+c$
4. $f(x)=sin(3x)+e^{5x+1}$
	$F(x)=-\dfrac{1}{3}cos(3x)+\dfrac{1}{5}e^{5x+1}+c$
5. $f(x)=\dfrac{1}{(3x+2)^5}$
	$F(x)=-\dfrac{1}{12}(3x+2)^{-4}+c$

### Integrali generalizzati
$\displaystyle\int_a^{+\infty} f(x)dx$  $f\in C([a,+\infty])$ 
Significato geometrico: 
![[Pasted image 20240508111330.png]]

Se $f \geq 0$, si vuole definire (quando possibile) l'area della regione infinita compressa tra grafico di $f$ e asse $x$.
<u>Definizione</u>: $f \in C([a,+\infty])$. Allora $f \in C([a,b]), \forall b>a$, quindi è ben definito $\displaystyle\int_a^b f(x)dx$. Si definisce $\displaystyle\int_a^{+\infty} f(x)dx=\lim\limits_{b \to \infty} \displaystyle\int_a^b f(x)dx$.
Purché il limite esista. Il valore di questo limite si dice integrale generalizzato (o improprio) di $f [a, +\infty)$.
Inoltre:
- L'integrale è convergente, se il limite è finito.
- L'integrale è divergente, se il limite è $\pm \infty$.
- L'integrale è indeterminato (o non esistente) se il limite non esiste.
<u>Osservazione</u>: In termini di funzione integrale, data $f:[a, +\infty) \to R$ continua, definiamo $F(x)=\displaystyle\int_a^x f(t)dt$.

### Esempio fondamentale
Per $a>0$, consideriamo $f(x)=\dfrac{1}{x^{\alpha}}$ su $[1,+\infty)$ e studiamo $\displaystyle\int_1^{+\infty} \dfrac{1}{x^{\alpha}} dx = \lim\limits_{x \to +\infty} \displaystyle\int_1^x \dfrac{1}{t^{\alpha}} dt$.
Le primitive di $f(t)=\dfrac{1}{t^{\alpha}}=t^{-\alpha}$ sono:
- $\log t+c, c \in R$             se $a=1$
- $\dfrac{t^{1-\alpha}}{1-\alpha} +c$, $c \in R$         se $a \neq 1$

Problema fondamentale: saper stabilire se $\int_a^{+\infty} f$ converge come per le serie, usiamo dei criteri di convergenza.
1. Criterio del confronto
	Siano $f, g \in C([a,+\infty])$, e tale che $f(x), g(x) \geq 0$
	definitivamente per $x \to +\infty$.
	Supponiamo che $f(x) \leq g(x)$ definitivamente per $x \to +\infty$. Allora
	- $\int_a^{+\infty} g(x) dx$ converge => $\int_a^{+\infty} f(x)dx$ converge
	- $\int_a^{+\infty} f(x)dx$ diverge => $\int_a^{+\infty} g(x)dx$ diverge
2. Criterio del confronto asintotico
	Siano $f, g \in C[(a, +\infty)]$ tali che $f(x), g(x) \geq 0$ def. per $x \to +\infty$.
	 