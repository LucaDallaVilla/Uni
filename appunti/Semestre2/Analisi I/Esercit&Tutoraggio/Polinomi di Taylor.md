Vedi [[Risoluzione appr. di equazioni]].
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
### logaritmo
Se $f(x)=\log(1+x)$     $T_{n,0}(x)=\sum\limits_{k=1}^{n} (-1)^{k+1} \dfrac{x^k}{k}$ 
Se $f(x)$ è dispari, tutti i valori per $k$ pari sono nulli.

$T_{2n+1, 0}(x)=T_{2n+2, 0}=\sum\limits_{k=0}^{n} (-1)^k \dfrac{x^{2k+1}}{(2k+1)!}$.

### 10/05
- Esercizio 1
Stimare il $\log(1.5)$ usando la funzione $f(x)=\log(1+x)$ e il suo polinomio di MacLaurin di ordine L.
$\log(1.5)=\log(1+0.5)$
$T_{0.2}^f (x)=x-\dfrac{x^2}{2}$ è noto dalla teoria ([[Polinomi di Taylor#logaritmo]]).
![[Pasted image 20240510092359.png]]
$x-\dfrac{x^2}{2}$ ha un'andatura simile a $\log(1+0.5)$ vicino a 0.
$T^f_{2.0}=0.5-\dfrac{(0.5)^2}{2}=0.5-\dfrac{0.25}{2}=0.375$
$\log(1.5) \sim 0.375$
Stimiamo ora l'errore commesso nel calcolare l'approssimazione.
Si ricorda, in generale, che:
$f(x)=T_{n,c}+\dfrac{f^{(n+1)}\chi}{(n+1)!}(x-c)^{n+1}$  ($\chi$ sta tra $x$ e $c$)
L'errore commesso è dunque:
$E_n(x)=|f(x)-T_{n,c}(x)|=\left|\dfrac{f^{(n+1)}(x)}{(n+1)!}(x-c)^{n+1}\right|$
$E_n(x) \leq \dfrac{M_{n+1}(x)}{(n+1)!}(x-c)$         dove $M_{n+1}(x)=max |f^{(n+)}(x)|$
Nello specifico $f(x)=\log(1+x)$   $c=0$
Calcoliamo $f'''(x)$:
$f(x)=\log(1+x)$
$f'(x)=\dfrac{1}{1+x}=(1+x)^{-1}$
$f''(x)=-(1+x)^{-2}$
$f'''(x)=2(1+x)^{-3}=\dfrac{2}{(1+x)^3}$
Otteniamo che $M_2(x)=max(\chi \in [0,0.5]) \left|\dfrac{2}{(1+\chi)^3}\right|=2$
$E_2(0.5)=\dfrac{2}{3!}(0.5)^3=\dfrac{1}{3}0.125=0.0416$
L'errore stimate è, in ultima analisi, $E_2(0.5)=0.0417$

<u>1.3) Valutare l'errore reale commesso tramite il polinomio di MacLaurin</u>
$\log(1.5)=0.4055$
$\log(1.5)-T_{0,2}(0.5)=|0.4055-0.375|=0.0305$
L'errore reale < l'errore stimato

- Esercizio 2
Tentativo:
$f(x)=\sqrt[3]{10}=10^{\frac{1}{3}}=(2+8)^\frac{1}{3}=2\left(1+\dfrac{1}{4}\right)^{\frac{1}{3}}$ -> $x=\dfrac{1}{4}$
$T_{1,0}^f(x)=1+\dfrac{1}{3}x$
$1+\dfrac{1}{3}*\dfrac{1}{4} = \dfrac{13}{12}$ ?
$E_n(x)=|f(x)-T_{n,c}(x)|=\left|\dfrac{f^2(x)}{2!}(x-c)^2\right|$
$f(x)=(1+x)^{\frac{1}{3}}$
$f'(x)=\dfrac{1}{3(1+x)^{\frac{2}{3}}}$
// $f''(x)=-\dfrac{2}{9}10^{-\frac{5}{3}}$

Soluzione:
$f(x)=\sqrt[3]{x}=2\sqrt[3]{1+\dfrac{1}{4}}$ 
$\sqrt[3]{10}=2f\left(\dfrac{1}{4}\right)$   con $f(x)=\sqrt[3]{1+x}$   con $x=\dfrac{1}{4}$ prossimo a 0
Polinomio di MacLaurin con $c=0$ e $n=1$
$T_{1,0}^f(x)=1+\dfrac{1}{3}x$
$\sqrt[3]{10}=2f\left(\frac{1}{4}\right) \sim 2*T^f_{1,0}\left(\dfrac{1}{4}\right)=2\left(1+\dfrac{1}{3}*\dfrac{1}{4}\right)=2.167$
Approssimazione di $\sqrt[3]{10}=2.167$

Stimiamo ora l'errore commesso:
$f(x)=T_{1,0}(x)+E_1(x)$
$E_1(x) \leq \dfrac{M_2(x)}{2}x^2$     dove $M_2 \in max(\chi \in [0;\frac{1}{4}]) \space |f''(\chi)|$ 
$f(\chi)=\sqrt[3]{1+\chi}=(1+\chi)^{\frac{1}{3}}$
$f'(\chi)=\dfrac{1}{3}(1+\chi)^{-\frac{2}{3}}$
$f''(\chi)=-\dfrac{2}{9} (1+\chi)^{-\frac{5}{3}}=-\dfrac{2}{9} \dfrac{1}{\sqrt[3]{(1+\chi)^5}}$
$max(\chi \in [0;1/4]) \space |f''(\chi)| = \dfrac{2}{9}$
$E_1(1/4)=\dfrac{1}{2}*\dfrac{2}{9}*\left(\dfrac{1}{4}\right)^2=\dfrac{1}{144}$
$\sqrt[3]{10}=2\left(f\left(\dfrac{1}{4}\right)\right)=2T_{0,2}\left(\dfrac{1}{4}\right)+2E_1\left(\dfrac{1}{4}\right)=0.014$
Concludiamo che $\sqrt[3]{10}=2.167 \pm 0.014$

- Esercizio 3
$\sin(0.1)$
$f(x)=\sin(x)$ 
$T_{0,3}(x)=x-\dfrac{x^3}{3!}=x-\dfrac{x^3}{6}$
$\sin(0.1)=T_{0,3} (0.1)=0.1-\dfrac{(0.1)^3}{6}=0.1-\dfrac{0.001}{6}=\dfrac{1}{10}-\dfrac{1}{6000}=\dfrac{599}{6000}$
Approssimazione $\sin(0.1)=\dfrac{599}{6000}=0.09983$

Stimiamo l'errore commesso:
$f(x)=T_{1,0}(x)+E_1(x)$
$E_3(x) \leq \dfrac{M_4(x)}{4!} x^4$
$M_4(x)=max(\chi \in [0,0.1] \space |f^{IV}(\chi)|$ 
$f^{IV}(\chi) = \sin \chi$ 
$M(0.1)=max(\chi \in [0;0.1] |\sin \chi|=\sin(0.1)$ 

Osserviamo che per $x \in \left[0;\dfrac{\pi}{2}\right]$
$E_3(0.1) \leq \dfrac{01}{4!}(0.1)^4=\dfrac{(0.1)^5}{24}=\dfrac{1}{24} \dfrac{1}{10^5}=4*10^{-7}$
$\sin(0.1)=0.9983 \pm 4*10^{-7}$
