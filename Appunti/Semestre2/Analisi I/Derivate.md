### Concavità/Convessità
Siano $I \in R$ un intervallo e $f:I \to R$
<u>Definizione</u>: Si dice che $f$ è convessa su $I$ se $\forall x_1, x_2 \in I$ con $x_1 < x_2$ risulta che $f(x) \leq f(x_1)+\dfrac{f(x_2)-f(x_1)}{x_2-x_1}*(x-x_1)$   $\forall x \in [x_1, x_2]$
![[Pasted image 20240320113542.png]]
$f(x_1)+\dfrac{f(x_2)-f(x_1)}{x_2-x_1}*(x-x_1)$ rappresenta la retta passante per i punti A e B di coordinate $A=(x_1, f(x_1))$ e $B=(x_2, f(x_2))$.
Dal punto di vista grafico, abbiamo definito convessa una funzione che sta sempre sotto alla retta passante per A e B generici.

<u>Definizione</u>: Si dice che $f$ è concava su $I$ se $\forall x_1, x_2 \in I$ con $x_1 < x_2$ risulta che $f(x) \geq f(x_1)+\dfrac{f(x_2)-f(x_1)}{x_2-x_1}*(x-x_1)$   $\forall x \in [x_1, x_2]$
![[Pasted image 20240320114138.png|]]
$f(x_1)+\dfrac{f(x_2)-f(x_1)}{x_2-x_1}*(x-x_1)$ rappresenta la retta passante per i punti A e B di coordinate $A=(x_1, f(x_1))$ e $B=(x_2, f(x_2))$.
Dal punto di vista grafico, abbiamo definito convessa una funzione che sta sempre sopra alla retta passante per A e B generici.


### Approssimazioni lineari
Abbiamo già visto che, se $f$ è crescente in $x-c$, la retta di equazione $y=f(c)+f'(c)(x-c)$ è la retta tangente a $f$ in $c$. Questa è la retta che meglio approssima $f$ localmente vicino a $c$.
$f(x) \sim f(c)+f'(c)(x-c)$

> $f(x)=sinx$, $c=0$. $f'(0)=1 \Rightarrow sinx \sim f(0)+f'(0)x=x$
> Vicino a zero, la funzione $sinx$ è simile alla retta.

### Funzioni elementari

| Funzione     | Derivata                   |
| ------------ | -------------------------- |
| $x^{\alpha}$ | $\alpha*x^{\alpha-1}$      |
| $k$          | 0                          |
| $e^x$        | $e^x$                      |
| $log(x)$     | $\dfrac{1}{x}$             |
| $sin(x)$     | $cos(x)$                   |
| $cos(x)$     | $-sin(x)$                  |
| $tan(x)$     | $\dfrac{1}{cos^2x}$        |
| $arcsin(x)$  | $\dfrac{1}{\sqrt{1-x^2}}$  |
| $arccos(x)$  | $-\dfrac{1}{\sqrt{1-x^2}}$ |
| $arctan(x)$  | $\dfrac{1}{1+x^2}$         |
### Regole di derivazione
- Somma: $(f+g)'(x)=f'(x)+g'(x)$
- Prodotto: $(\beta f)(x)=\beta (f'(x))$ 
		  $(f*g)'(x)=f'(x)g(x)+f(x)g'(x)$
- Rapporto: $\left(\dfrac{f}{g}\right)'(x)=\dfrac{f'(x)g(x)-f(x)g'(x)}{g^2(x)}$
- Funzione composta: $(g \circ f)(x)=g(f(x)$
					$(g(f(x))'=g'(f(x))*f'(x)$