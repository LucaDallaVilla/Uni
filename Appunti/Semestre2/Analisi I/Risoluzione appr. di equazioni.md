La maggior parte delle equazioni non si risolve in forma esatta. Ad esempio $e^x+x-3=0$ con $x \in R$
Non si riesce a risolvere esplicitamente. 
Servono:
- Risultati teorici che garantiscano esistenza di soluzioni.
- Metodi numerici per il calcolo approssimato delle soluzioni.

### Metodo della bisezione
Data $f(x)=0, x \in I \subset R$ intervallo, come faccio a determinare $[a,b]$ in cui le ipotesi del teorema siano soddisfatte? Spesso può essere utile fare confronti grafici.
> $f(x)=e^x+x-3=0$   $x \in R$
> $e^x=3-x$    $g(x)=h(x)$
> ![[Pasted image 20240416093652.png]]
> Il punto di intersezione corrisponde a uno zero della funzione $f(x)$ ed è contenuto in $[0,3]$, intervallo valido per il [[Teoremi#Th. di esistenza degli zeri]].

### Metodo delle tangenti di Newton
$f:[a,b] \to R$ derivabile e tale che $f(a)f(b)<0$. $f$ è quindi anche continua nell'intervallo.
Preso $x_0 \in [a,b]$, consideriamo la tangente a $f$ in $x_0$ $y=f(x_0)+f'(x_0)(x-x_0)$.
![[Pasted image 20240416095159.png|700]]
Itero il procedimento: consideriamo la tangente a $f$ in $x_1$, e calcoliamo il suo zero $x_2=x_1-\dfrac{f(x_1)}{f'(x_1)}$.
Si definisce quindi una successione definita per ricorrenza: $x_{n+1}=x_n-\dfrac{f(x_n)}{f'(x_n)}$.
Sotto opportune ipotesi, $x_n \to c$, $c$ zero di $f$.

<u>Osservazione</u>: non è detto che $x_n$ tenda ad uno zero, senza ulteriori ipotesi.
Infatti, affinché la successione $\{x_n\}$ sia ben definita, si deve richiedere che $f'(x) \neq 0$    $\forall x \in [a,b]$.
Se $f \in C'([a,b])$, questo implica che $f$ sia strettamente monotona.
Anche con questa ipotesi, $\{x_n\}$ potrebbe non convergere.
> ![[Pasted image 20240416100203.png|700]]

