Vedi [[Risoluzione appr. di equazioni]]
$f:I(c) \to R$ derivabile n volte in $x=c$. Allora $\exists$ un polinomio (chiamato polinomio di Taylor di ordine n centrato in $x=c$) $T_{n,c}(x)$ tale che $T_{n,c}^{(k)} (x)=f^{(k)} (c)$ $\forall k=0,1,...,n$.
$T_{n,c}(x)=\sum\limits_{k=0}^{n} \dfrac{f^{(k)}(c)}{k!} (x-c)^k=\dfrac{f^{(0)}(x)}{0!}(x-c)^0+...+\dfrac{f^{(n)}(x)}{n!} (x-c)^n$.
<u>Osservazione</u>: 
- $T_{n,c}(x)$ approssima la funzione $f$ vicino a $x=c$.
- Se $c=0$, si chiama Polinomio di Mclaurin.

> ![[Pasted image 20240503092457.png]]
> $T_{3,1}(x)=\sum\limits_{k=0}^{3} \dfrac{f^{(k)}(1)}{k!}(x-1)^k=1-x+1+(x-1)^2-(x-1)^3=-x^3+4x^2-6x+4$
> con $k=0$: $\dfrac{f^{(0)}(1)}{0!}(x-1)^0=f(1)=1$
> con $k=1$: $\dfrac{f'(1)}{1!}(x-1)=-(x-1)$
> con $k=2$: $...=(x-1)^2$
> con $k=3$: $...=-(x-1)^3$

> ![[Pasted image 20240503093617.png]]
> $T_{4,0} (x) = \sum\limits_{k=0}^{4} \dfrac{f^{(k)}(0)}{k!} x^k = 0+x-\dfrac{1}{2}x^2+\dfrac{1}{3}x^3-\dfrac{1}{4}x^4$
> $T_{4,0}(x)=\sum\limits_{k=0}^{4} \dfrac{f^{(k)}(0)}{k!} x^k=x-\dfrac{x^3}{6}$
> con $k=0$: $0$
> con $k=1$: $x$
> con $k=2$: $0$
> con $k=3$: $-\dfrac{x^3}{6}$
> con $k=4$: $0$

Se $f(x)=\log(1+x)$     $T_{n,0}(x)=\sum\limits_{k=1}^{n} (-1)^{k+1} \dfrac{x^k}{k}$ 
Se $f(x)$ è dispari, tutti i valori per $k$ pari sono nulli.

$T_{2n+1, 0}(x)=T_{2n+2, 0}=\sum\limits_{k=0}^{n} (-1)^k \dfrac{x^{2k+1}}{(2k+1)!}$.