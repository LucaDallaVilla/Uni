### 1
max z = $2x_1+3x_2$
$x_1+x_2 \leq 5$
$x_1+5x_2 \leq 15$
$x_1 \leq 4$
$x_1, x_2 \geq 0$

1. Risolvere metodo grafico
	$y=-x+5$
	$y=-\dfrac{1}{5}x+3$
	$x=4$
	$y=-\dfrac{2}{3}x+k$
	$z=2\left(\dfrac{5}{2}\right)+3\left(\dfrac{5}{2}\right)=\dfrac{25}{2}$ sostituisco le coordinate di B nell'equazione di $z$.
	![[Pasted image 20240403103829.png]]
2. Forma standard
	$x_1+x_2+x_3 = 5$
	$x_1+5x_2+x_4=15$
	$x_1+x_5=4$
	$x_1, x_2, ..., x_5 \geq 0$

3. Elencare basi ammissibili dei problemi

| 0   | $x_3,x_4,x_5$ |
| --- | ------------- |
| A   |               |
| B   |               |
| C   |               |
| D   |               |

4. Risolvere con simplesso
	max z$=0+2x_1+3x_2$
	$x_3=5-x_1-x_3$
	$x_4=15-x_1-5x_3$
	$x_5=4-x_1$

	max z$=9+\dfrac{7}{5}x_1-\dfrac{3}{5}x_4$
	$x_3=2-\dfrac{4}{5}x_1+\dfrac{1}{5}x_4$
	$x_2=3-\dfrac{1}{5}x_1-\dfrac{1}{5}x_4$
	$x_5=4-x_1$

	max z$=\dfrac{25}{2}-\dfrac{7}{4}x_3-\dfrac{1}{4}x_4$ ottimo
	$x_1=\dfrac{5}{2}-\dfrac{5}{4}x_3+\dfrac{1}{4}x_4$
	$x_2=\dfrac{5}{2}+\dfrac{1}{4}x_3-\dfrac{1}{4}x_4$
	$x_5=\dfrac{3}{2}+\dfrac{5}{4}x_3-\dfrac{1}{4}x_4$

### 2
$max z=2x_1+3x_2$
$x_1+2x_2 \leq 8$
$3x_1+x_2 \leq 9$
$2x_2 \leq 7$
$x_1, x_2 \geq 0$

![[Pasted image 20240430112112.png]]

$A(2,3)$ 
Forma standard
$x_1+2x_2+x_3=8$ $(u1)$
$3x_1+x_2+x_4=9$ $(u2)$
$2x_2+x_5=7$ $(u3)$
$x_1,x_2 \geq 0$

Duale
min $w=8u_1+9u_2+7u_3$
$(x_1)$ $u_1+3u_2 \geq 2$
$(x_2)$ $2u_1+u_2+2u_3 \geq 3$
$(x_3)$ $u_1 \geq 0$
$(x_4)$ $u_2 \geq 0$
$(x_5)$ $u_3 \geq 0$
metti variabili di surplus

$v^T x=0$
$\sum\limits_{j=1}^{n} v_jx_j=0$ 
$x_j>0 \Rightarrow v_j=0$
se $v_1, v_2, v_5 = 0$ ho un sistema stabile.

$w=8*\dfrac{7}{5} + 9*\dfrac{1}{5}=13$


### 3
max $z= 2x_1+x_2-2x_3$
$2x_1+3x_2-x_3 \leq 5$
$x_1+x_2+x_3 \leq 10$
$x_1, x_2, x_3 \geq 0$

$2x_1+3x_2+x_3+x_4=5$ $(u1)$
$x_1+x_2+x_3+x_5=10$ $(u2)$
$x_1,x_2,x_3, x_4, x_5 \geq 0$ 

min $w=5u_1+10u_2$
$(x1)$ $2u_1+u_2 \geq 2$
$(x2)$ $3u_1+u_2 \geq 1$
$(x3)$ $-u_1+u_2 \geq -2$
$(x_4)$ $u_1 \geq 0$
$(x_5)$ $u_2 \geq 0$

$2u_1+u_2-v_3=2$
$3u_1+u_2-v_4=1$
$-u_1+u_2-v_5=2$
$u_1-v_6=0$
$u_2-v_7=0$


### 4
max z = $2x_1+x_2$
$x_1-2x_2 \leq 3$
$2x_1+3x_2 \leq 8$
$x_2 \leq 2$
$x_1,x_2 \leq Z_1$

$x_1-2x_2+x_3 = 3$
$2x_1+3x_2+x_4=8$
$x_2+x_5=2$
$x_1,x_2 \leq Z$

(1)
max z = $\dfrac{52}{7}-\dfrac{4}{7}x_3-\dfrac{5}{7}x_4$
$x_1=\dfrac{25}{7}-\dfrac{3}{7}x_3-\dfrac{2}{7}x_4$
$x_2=\dfrac{2}{7}+\dfrac{2}{7}x_3-\dfrac{1}{7}x_4$
$x_5=\dfrac{12}{7}-\dfrac{2}{7}x_3+\dfrac{1}{7}x_4$

max z = $\dfrac{52}{7}-\dfrac{4}{7}x_3-\dfrac{5}{7}x_4$                   $x_1 \leq 3$ 
$x_1=\dfrac{25}{7}-\dfrac{3}{7}x_3-\dfrac{2}{7}x_4$                         $x_1+x_6=3$
$x_2=\dfrac{2}{7}+\dfrac{2}{7}x_3-\dfrac{1}{7}x_4$                           $x_6=3-x_1$
$x_5=\dfrac{12}{7}-\dfrac{2}{7}x_3+\dfrac{1}{7}x_4$
$x_6=-\dfrac{4}{7}+\dfrac{3}{7}x_3+\dfrac{2}{7}x_4$

(2)
max z = $\dfrac{20}{3}-\dfrac{4}{3}x_6-\dfrac{1}{3}x_4$
$x_1=3-x_6$
$x_2=\dfrac{2}{3}+\dfrac{2}{3}x_6-\dfrac{1}{3}x_4$
$x_5=\dfrac{4}{3}-\dfrac{2}{3}x_6+\dfrac{1}{3}x_4$
$x_3=\dfrac{4}{3}+\dfrac{7}{3}x_1-\dfrac{2}{3}x_4$

(3)
max z = $\dfrac{52}{7}-\dfrac{4}{7}x_3-\dfrac{5}{7}x_4$
$x_1=\dfrac{25}{7}-\dfrac{3}{7}x_3-\dfrac{2}{7}x_4$
$x_2=\dfrac{2}{7}+\dfrac{2}{7}x_3-\dfrac{1}{7}x_4$
$x_5=\dfrac{12}{7}-\dfrac{2}{7}x_3+\dfrac{1}{7}x_4$
$x_6=-\dfrac{3}{7}-\dfrac{3}{7}x_3-\dfrac{2}{7}x_4$ unfeasible

### fac-simile esame
max z = $x_1+x_2$
$x_1+x_2 \leq 4$
$x_1+x_2 \geq 2$
$2x_2 \leq 7$
$x_1, x_2 \in Z_+$
$x_1=\dfrac{1}{2}$
$x_2=\dfrac{7}{2}$
figli ottimizzatati sono nodi aperti o chiusi?

$x_1+x_2+x_3 = 4$
$x_1+x_2-x_4=2$
$2x_2+x_5 = 7$
$x_1, x_2 \in Z_+$
??????