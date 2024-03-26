Siano $c \in R, I(c)=(c-\delta, c+\delta)$ e sia $f$ derivabile in $c$. Allora $f(x) \sim f(c)+f'(c)(x-c)$ per $x$ vicino a $c$. Definito come polinomio di Taylor di ordine 1 centrato in $c$ ($T_{1,c}(x)$).
Si tratta di un'approssimazione lineare e locale.

> $sinx \sim x$ per $x \to 0$
> $cosx \sim 1$ per $x \to 0$

analogamente:
> $h(x)=cosx \Rightarrow h'(x)=-sinx$
> $h(0)=1, h'(0)=0 \Rightarrow h(0)+h'(0)x=x$.

Sappiamo d'altra parte anche che:
$cosx \sim 1-\dfrac{x^2}{2}$ per $x \to 0$ (approssimazione migliore).

L'equazione della retta tangente è caratterizzata da $\begin{cases}T_{1,c}(c)=f(c) \\ T_{1,c}'(c)=f'(c) \end{cases}$ .
Questo suggerisce, volendo considerare un'approssimazione di grado 2, di cercare un polinomio $T_{2,c}(x)$ tale che $\begin{cases} T_{2,c}(c)=f(c) \\ T'_{2,c}(c)=f'(c) \\ T''_{2,c}(c)=f''(c) \end{cases}$.
$T_{2,c}(x)=\alpha + \beta (x-c)+\gamma(x-c)^2$
con $\alpha$ $\beta$ $\gamma$ da determinare.
$T'_{2,c}(x)= \beta +2 \gamma (x-c)$
$T''_{2,c}(x)=2 \gamma$
$T'_{2,c}(c)=f'(c) \Rightarrow \beta=f'(c)$
$T''_{2,c}=f''(c) \Rightarrow 2\gamma = f''(c)$
In conclusione:
$T_{2,c}(x)=f(c)+f'(c)(x-c)+\dfrac{f''(c)}{2}(x-c)^2$
Questo polinomio si dice polinomio di Taylor di ordine 2 centrato in c.
Iterando il ragionamento:
<u>Proposizione</u>: Sia $f:I(c) \to R$ derivabile $n$ volte in c.
Allora esiste un unico polinomio $T_{n,c}(x)$ di grado $\leq n$ tale che $T_{n,c}^{(k)}=f^{(k)}(c)$    $\forall k \in N$.
Tale polinomio si chiama polinomio di Taylor di $f$ di ordine $n$ centrato in $c$ ed è definito da $T_{n,c}(x)=f(c)+f'(c)(x-c)+\dfrac{1}{2}f''(c)(x-c)^2+\dfrac{f^{(n)}(c)}{n!}(x-c)^n$.
<u>Osservazione</u>: $T_{n,c}(x)$ rappresenta un'approssimazione di $f$ per $x$ vicino a $c$. Più $n$ è grande, migliore è l'approssimazione.
<u>Osservazione</u>: più $f$ è derivabile tante volte, meglio è approssimabile con un polinomio.
<u>Osservazione</u>: $T_{n,c}(x)=\sum\limits_{k=0}^{n} \dfrac{f^{(k)}(c)}{j!}(x-c^k)$.
<u>Osservazione</u>: $T_{n,c}$ ha grado $\leq n$ perché $f^{(c)}(c)$ potrebbe essere 0.
<u>Osservazione</u>: se $c=0$, $T_{n,c}$ si dice anche polinomio di Mac Laurin di ordine $n$.

> $f(x)=e^x$.
> $f^{(k)}(x)=e^x$
> $\Rightarrow f^{(k)}(0)=1$ per qualsiasi $k$.
> $e^x \sim 1+x+\dfrac{x^2}{2}+\dfrac{1}{3!}x^3+\dfrac{1}{4!}x^4+...+\dfrac{1}{n!}x^n$.

Altri importanti polinomi di Mac Laurin:
> $f(x)=sinx$
> $T_{2n+1,0}(x)=x-\dfrac{x^3}{3!}+\dfrac{x^5}{5!}-\dfrac{x^7}{7!}+...+(-1)^n \dfrac{x^{2n+1}}{(2n+1)!}$.

> $f(x)=cosx$
> $\Rightarrow '' \sim 1-\dfrac{x^2}{2}+\dfrac{x^4}{4!}-\dfrac{x^6}{6!}+...$

> $f(x)=log(1+x) \sim x-\dfrac{x^2}{2}+\dfrac{x^3}{3}-\dfrac{x^4}{4}+...$

> $f(x)=(1+x)^{\alpha} \sim 1+\alpha x + \dfrac{\alpha(\alpha -1)}{2}x^2+\dfrac{\alpha(\alpha-1)(\alpha-2)}{3!}x^3$.

Quando diciamo che $T_{n,c}(x)$ approssima $f$ per $x$ vicino a $c$, intendiamo che $f(x)=T_{n,c}(x)+E_n(x)$ per $x \to c$.
Cfr. [[Teoremi#Th. Formula di Taylor con resto di Lagrange]]
