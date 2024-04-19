![[Pasted image 20240412094117.png]]

1. $g \circ f = g(f(x))$ 
	$g(f(0))=1$
	$g(f(x))(-1)=0.4$ (corretto dalle slide)
	$f(g(x))(1)=2$
2. L'intervallo $(-1,0)$ corrisponde all'intervallo $(1.5, 2)$ nel grafico di $g$. Nei 2 intervalli corrispondenti le funzioni sono entrambe crescenti, quindi $g \circ f$ è crescente.
	L'intervallo $(0,1)$ corrisponde all'intervallo $(2, 3.75)$ nel grafico di $g$. Nei 2 intervalli corrispondenti le funzioni sono entrambe crescenti, quindi $g \circ f$ è crescente.
3. In $(0,1)$, $f \circ g$ è decrescente.
	In $(1,2)$, $f \circ g$ è crescente.

![[Pasted image 20240412101913.png]]

1. Dominio di $h$ è $D=(0,1) \cup (2,3)$ perché è dove la $f(x)$ è positiva.
	Per $x=0.9$, $h(x)=0$ perché in $f$ vale 1.
	$\lim\limits_{x \to 0^+} h(x)=\lim\limits_{x \to 0^+} log(f(x))=\lim\limits_{x \to 0^+} log(+\infty)=+\infty$ 
	$\lim\limits_{x \to 1^-} log(f(x))=log(0^+)=-\infty$ 
	$\lim\limits_{x \to 2^+} log(f(x))= log(0^+)=-\infty$
	$\lim\limits_{x \to 3^-} log(f(x))=log(0^+)=-\infty$ 

2. Il logaritmo è sempre crescente nel suo dominio, mentre $f(x)$ è crescente in $(2, 2.5)$.
	$h(x)$ decresce in $(0,1)$ e in $(2.5, 3)$

3. ![[Pasted image 20240412103957.png|500]]

### 19 aprile
![[Pasted image 20240419092443.png]]
$h(x)=arctan(f(x))$.
Il dominio dell'`arctan` è tutto il campo $R$.
Il dominio di $h$ è quindi il dominio di $f \Rightarrow D=R-\{0\}$.
$h(x)>0$ quando $arctan(f(x))>0 \Rightarrow f(x)>0$ e quindi nell'intervallo $(0,1) \cup (2,3)$.
$h(x)=0$ quando $x=1, x=2, x=3$.

$\lim\limits_{x \to -\infty} h(x)=\lim\limits_{x \to -\infty} arctan(f(x)) = \lim\limits_{x \to 0^-} arctan(y)=0$.
$\lim\limits_{x \to +\infty} h(x)=\lim\limits_{y \to -\infty} arctan(y)=-\dfrac{\pi}{2}$.
$\lim\limits_{x \to 0^-} h(x) = \lim\limits_{y \to -\infty} arctan(y) = -\dfrac{\pi}{2}$.
$\lim\limits_{x \to 0^+} h(x) = \lim\limits_{y \to +\infty} arctan(y) = +\dfrac{\pi}{2}$.

$h$ cresce e decresce in base alla monotonia di $f$, dato che $g$ è sempre crescente.
$h$ decresce in $(-\infty, 0) \cup (0,1.3) \cup (2.5, +\infty)$.
$h$ cresce in $(1.3, 2.5)$.
![[Pasted image 20240419094612.png|600]]


### 2
$k(x)=\sqrt{f(x)}$
D radice $=[0, +\infty)$
$D(f) = R-\{0\}$ 
$D(k) = (0, +\infty)$.

$k(x)>0$    $x \in (0,1) \cup (2,3)$
