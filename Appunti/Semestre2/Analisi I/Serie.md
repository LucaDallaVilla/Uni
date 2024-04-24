> TODO: copia appunti

$\lim\limits_{n=1}^{+\infty} \dfrac{1}{n^\alpha}$ converge se $\alpha >1$, diverge se $\alpha \leq 1$.
Per avere convergenza, $a_n$ deve tendere a 0 "abbastanza rapidamente".
se $0<\alpha<\beta$
$n^{\alpha} < n^{\beta} \Rightarrow \dfrac{1}{n^{\alpha}} > \dfrac{1}{n^{\beta}}$ 
Quindi, più l'esponente è grande, più il termine $\dfrac{1}{n^{\beta}}$ è piccolo.

### Criterio del Confronto
Siano $\{a_n\}$ e $\{b_n\}$ 2 successioni con $a_n, b_n \geq 0$  $\forall n$. Supponiamo che $\{a_n\} \leq \{b_n\}$  $\forall n$ (o almeno per $n \to +\infty$), allora:
- $\sum\limits_{n=0}^{+\infty} b_n$ converge $\Rightarrow \sum\limits_{n=0}^{+\infty} a_n$ converge.
- $\sum\limits_{n=0}^{+\infty} a_n$ diverge $\Rightarrow \sum\limits_{n=0}^{+\infty} b_n$ diverge.
<u>Osservazione</u>: Ricordiamo che il carattere di una serie non cambia se cambiamo l'indice di partenza (o se eliminiamo/aggiungiamo un numero finito di termini). Interessa che le ipotesi valgano per $n \to +\infty$.
> Abbiamo visto che $\sum\limits_{n=0}^{+\infty} \dfrac{1}{n}=+\infty$.
> Mostriamo che $\sum\limits_{n=0}^{+\infty} \dfrac{1}{n^{\alpha}}=+\infty$ $\forall \alpha < 1$
> Usando il criterio del confronto, $\sum\limits_{n=0}^{+\infty} \dfrac{1}{n}=+\infty \Rightarrow \sum\limits_{n=0}^{+\infty}\dfrac{1}{n^{\alpha}}=+\infty$  $\forall \alpha < 1$.

### Criterio del confronto asintotico
Siano $\{a_n\}$, $\{b_n\}$ successioni a termini $\geq 0$. Supponiamo che $a_n \sim b_n$ per $n \to \infty$ $\left(\lim\limits_{n \to +\infty} \dfrac{a_n}{b_n}=1\right)$.
Allora $\sum\limits_{n=0}^{+\infty} a_n$ converge $\iff \sum\limits_{n=0}^{+\infty} b_n$ converge e
$\sum\limits_{n=0}^{+\infty} a_n$ diverge $\iff \sum\limits_{n=0}^{+\infty} b_n$ diverge.

> $\sum\limits_{n=0}^{+\infty} \dfrac{1}{3^n+\sqrt{n}}=\sum\limits_{n=0}^{+\infty} \dfrac{1}{3^n \left(1+\dfrac{\sqrt{n}}{3^n}\right)} \sim \sum\limits_{n=0}^{+\infty} \dfrac{1}{3^n}$ = base geometrica con base $\dfrac{1}{3} \in (-1,1) \Rightarrow$ converge.
> Quindi $\sum\limits_{n=0}^{+\infty} \dfrac{1}{\sqrt{n}+3^n}$ converge per confronto asintotico.

> $\sum\limits_{n=2}^{+\infty} \dfrac{1}{(\log n)^{\alpha}}$ => diverge.

### Serie a termini di segno variabile
In generale, lo studio di $\sum\limits a_n$, dove $a_n$ cambia segno $+\infty$ volte, è complesso.
<u>Definizione</u>: $\sum a_n$ converge assolutamente, se converge, la serie $\sum |a_n|$.

### Criterio di convergenza assoluta
Se $\sum a_n$ converge assolutamente $\implies \sum a_n$ converge se $\sum |a_n|$ converge.