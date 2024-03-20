<u>Lemma</u>: $\bar x \in S_a$ ottima $\iff \nexists y \in R^n :$
- $Ay = 0$
- $c^Ty>0$
- $y_j \geq 0 \space \forall j : \bar x_j=0$

<u>Esempio</u>: $max \space z=c^Tz$
soggetto a: 
- $Ax=b$
- $x \geq 0$

$\bar x \in S_a$ ottimo $\iff \nexists y \in R^n :$
- $Ay=0$
- $c^Ty >0$
- $y_j \geq 0 \space \forall j \space \bar x_j=0$

troviamo $\bar x$ ottimo per assurdo:
$\exists y \in R^n : Ay=0 c^Ty>0 \space y_j \geq 0 \space \forall j:\bar x_j=0$
$x'=\bar x+\epsilon y \in S_a$ -> $Ax'=b$ e $x' \geq 0$
$Ax'=A\bar x + \epsilon Ay=b$

![[Pasted image 20240313093251.png|800]]

$c^T x'=c^T \bar x + \epsilon c^Ty > c^T \bar x$
[dimostrazione in direzione opposta]

### Vertici della regione ammissibile
// TODO
Si dice vertice se è impossibile trovare un segmento interno alla regione ammissibile tale che il punto in questione sia il punto medio del segmento.

### Th. fondamentale della prog. lineare
Se un programma lineare ammette soluzione ottimale, allora almeno una delle soluzioni è un vertice della regione ammissibile $S_a$.
$x^*$ ottimo con il minimo numero di variabili >0.
- se $x^*=0 \Rightarrow x^*$ vertice
- se $x^* \neq 0$  $x_1^*,x_2^*,...,x_n^* >0$ $x_{k+1},...,x_{k+m} <0$
	1. se $x^*$ vertice $\Rightarrow$ STOP
	2. se $x^*$ non è vertice $\Rightarrow \exists x' \in S_a$ ottimo e con numero di componenti positive $<k$.
		$\exists u,v \in S_a$ distinti tale che $x^*=\dfrac{1}{2}u+\dfrac{1}{2}v$.
		$i\in \{k,...,n\} \space x^*_i=\dfrac{1}{2}u_i+\dfrac{1}{2}v_i \Rightarrow u_i=v_i=0$.
		$u$ e $v$ sono anche loro soluzioni ottime.
		$c^Tu<z^*$
		$c^Tv<z^*$
		$z^*=c^Tx^*=c^T\left[\dfrac{1}{2}u+\dfrac{1}{2}v\right]=\dfrac{1}{2}c^Tu+\dfrac{1}{2}c^Tv<z^* \Rightarrow z^* < z^*$ assurdo!
		$\Rightarrow u, v$ soluzioni ottime.
		$y=u-v$
		C'è almeno una $y_i<0$.
		$x'=x^*+\epsilon y \in S_a$   $\epsilon >0$.
		$Ax'=b$ e $x' \geq 0$.
		$Ax'=A(x^*+\epsilon y=Ax^*+\epsilon Ay=Ax^*+\epsilon Au-\epsilon Av=b+b-b=b$
		$x'=x^*+\epsilon y \geq 0$
		$x_i'=x_i^*+\epsilon y_i$

 