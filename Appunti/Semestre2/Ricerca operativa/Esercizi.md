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

sos