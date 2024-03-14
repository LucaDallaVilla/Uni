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
$\exists y \in R^n : Ay=0 c^Ty>0 y_j \geq 0 \space \forall j:\bar x_j=0$
$x'=\bar x+\epsilon y \in S_a$ -> $Ax'=b$ e $x' \geq 0$
$Ax'=A\bar x + \epsilon Ay=b$

![[Pasted image 20240313093251.png|800]]

$c^T x'=c^T \bar x + \epsilon c^Ty > c^T \bar x$
[dimostrazione in direzione opposta]

### Th. fondamentale della prog. lineare
Se un programma lineare ammette soluzione ottimale, allora almeno una delle soluzioni è un vertice della regione ammissibile.
