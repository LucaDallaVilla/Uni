### Ripasso
$f: I \to R$
funzione pendenza: $p_f:I \to R$. Dato un punto $x$, fornisce la pendenza della retta tangente al grafico di $f$ in $x$.
- $f$ crescente $\iff p_f \geq 0$
- $f$ decrescente $\iff p_f \leq 0$
- $f$ convessa $\iff p_f$ crescente
- $f$ concava $\iff p_f$ decrescente

### Grafico della derivata
$f:(a,b) \to R$   $x_0 \in (a,b)$.
$f$ è derivabile in $x_0$ se esiste finito il limite: $p_f = \lim\limits_{h \to 0} \dfrac{f(x_0+h)-f(x_0)}{h}$. Questo mostra la pendenza della retta tangente a $f$ in $x_0$.
I passi per disegnare la funzione derivata a partire da un grafico:
1. Trovare gli zeri della $f'$, cioè i massimi e i minimi relativi della $f$.
2. Ricavare il segno di $f'$ dalla monotonia di $f$.
3. Studiamo la concavità di $f$ studiando la monotonia di $f'$.

<u>Esercizio 1</u>
![[Pasted image 20240301093702.png]]![[Pasted image 20240301093722.png]]

<u>Esercizio 2</u>
![[Pasted image 20240301094957.png]]![[Pasted image 20240301095129.png]]
$f(x)=\dfrac{1}{x}$. Dominio: $R - \{0\}$.

<u>Esercizio 3</u>
![[Pasted image 20240301095929.png]] ![[Pasted image 20240301102529.png|500]]

1. C'è solo un punto di massimo per $x=4$ e non ci sono punti di minimo.
2. $f'$ è positivo nell'intervallo $(0, 4)$ e negativo nell'intervallo $(4, +\infty)$.
3. $f$ è convessa in $(0,6)$ e concava in $(6, +\infty)$.

### Dinamica della popolazione
![[Pasted image 20240301102854.png]]

Per il tasso di crescita $\lim\limits_{\Delta t \to 0} \dfrac{N(\Delta t+t)-N(t)}{\Delta t}$:
- $N$ crescente $\rightarrow$ tasso $\geq 0$
- $N$ decrescente $\rightarrow$ tasso $\geq 0$ 

<u>Esercizio 1</u>
![[Pasted image 20240301103159.png]]

1. Descrivi l'andamento della popolazione (con massimi e minimi)
> Il grafico è crescente negli intervalli $\left[0, \dfrac{1}{2}\right]$ e $\left[\dfrac{13}{5}, +\infty\right]$.
> Il massimo relativo è per $x=\dfrac{1}{2}$, il minimo relativo per $x=\dfrac{13}{5}$.
2. Stimare il tasso di crescita per $x=0$ e $x=\dfrac{3}{2}$.
> Approssima $\Delta t$ a qualcosa vicino a 0, come 0.5 e calcola $\dfrac{N(t+\Delta t)-N(t)}{\Delta t} \simeq 1$.
3. Determinare in quali instanti il tasso di crescita della popolazione è positivo ed in quali è negativo, in quali intervalli è crescente o decrescente.
> Tasso è positivo quando $f' \geq 0$, cioè $[0, 0.6]$ e $[2.6, \infty]$.
4. Tracciare il grafico qualitativo del tasso di crescita
> ![[Pasted image 20240301104523.png]]

<u>Esercizio 2</u>
![[Pasted image 20240301104911.png|700]]
1. 6, 10, 3 rispettivamente per $x=0, x=6, x=18$.
2. $\dfrac{N(t+\Delta t)-N(t)}{\Delta t} \simeq -1$.
3. Crescente negli intervalli $[0, 6]$ e $[18, +\infty]$. Si cambia monotonia 2.
4. Grafico di $f'$:
	![[Pasted image 20240301110017.png|700]]


### FAQ
1. Flessi a tangente orizzontale
	$f(x)=x^3$
	![[Pasted image 20240308091335.png]]
	Cambia il segno della derivata seconda e quindi la concavità del grafico.
	
2. Come stimare il valore di un max/min di $f'$?
	Trova i punti di flesso e stima la pendenza della tangente in quei punti.
	$p_f(x)=\dfrac{f(x+\Delta x)-f(x)}{\Delta x}$