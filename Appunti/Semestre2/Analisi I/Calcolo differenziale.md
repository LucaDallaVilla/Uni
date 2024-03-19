Siano $c \in R$ e $I(c)=(c-\delta, c+\delta)$ un suo intorno.
<u>Definizione</u>: Una funzione $f:I(c) \to R$ si dice derivabile in $c$ se esiste finito $\lim\limits_{h \to 0} \dfrac{f(c+h)-f(c)}{h}$.
In tal caso, il limite si denota con il simbolo $f'(c)$ e si chiama derivata (prima) di $f$ in $c$: $\lim\limits_{h \to 0} \dfrac{f(c+h)-f(c)}{h}$.
<u>Osservazione</u>: $\lim\limits_{h \to 0} \dfrac{f(c+h)-f(c)}{h}=\lim\limits_{x \to c} \dfrac{f(x)-f(c)}{x-c}$

> $f(x)=sin x$, $c=0$
> $\lim\limits_{h \to 0} \dfrac{f(h)-f(c)}{h}=\lim\limits_{h \to 0} \dfrac{sinh-sin0}{h}=\lim\limits_{h \to 0} \dfrac{sinh}{h}=1$ ([[Limiti#Limiti notevoli]], punto 1).
>$\Rightarrow f'(0)=1$

> $f(x)=e^x, c=0$
> $\lim\limits_{h \to 0} \dfrac{f(h)-f(0)}{h}=\lim\limits_{h \to 0} \dfrac{e^h-e^0}{h}=\lim\limits_{h \to 0} \dfrac{e^h-1}{h}=1$ ([[Limiti#Limiti notevoli]], punto 4).

<u>Definizione</u>: Sia $I \subseteq R$ un intervallo e sia $f:I \to R$. Si dice che $f$ è derivabile su $I$ se lo è in ogni punto di $I$. In tal caso, si definisce la funzione derivata:
$f':I \to R$
$x \to f'(x) \in R$
> $f(x)=e^x$. Vogliamo calcolare la derivata nel generico punto $x \in R$.
> $\dfrac{f(x+h)-f(x)}{h}=\dfrac{e^{x+h}-e^x}{h}=\dfrac{e^x*e^h-e^x}{h}=e^x*\dfrac{e^h-1}{h}$.
> $\lim\limits_{h \to 0} e^x * \dfrac{e^h-1}{h} = e^x$ ([[Limiti#Limiti notevoli]], punto 4).

<u>Definizione</u>: Sia $f:I \to R$ derivabile in $I$. Se $f'$ è a sua volta derivabile, possiamo considerare $(f')'=f''$ e si chiama derivata seconda.
Iterando questo ragionamento, si possono definire derivate di ordine qualsiasi.

<u>Definizione</u>: $f:I \to R$. Si dice che $f$ è di classe $C^k$ su $I$, $f \in C^k(I)$, se esistono le derivate $f', f'',...,f^{(k)}$ su $I$, e se $f^{(k)}$ è continua in $I$.
> $\forall k \in N, f(x)=e^x$ è di classe $C^k$ su tutto $R$.

### Proprietà delle $f$ derivabili
- [[Teoremi#Th. Continuità-derivabilità]]