### Modelli di Mix
max z$=(1+r_0)x_0 + \sum\limits_{i=1}^{6}[(1+r_i)p_i]x_i$ 
$x_0 + \sum\limits_{i=1}^{6}p_ix_i=500'000$
$x_0\geq150'000$
$p_ix_i\leq100'000$ $\forall i=1,...,6$
$p_5x_5+p_6x_6\leq\dfrac{20}{100}\sum\limits_{i=1}^{6}p_ix_i$ 
$p_2x_2\geq\dfrac{10}{100}\sum\limits_{i=1}^{6}p_ix_i$
$\sum\limits_{i=1}^{6}\delta_ip_ix_i \leq \dfrac{15}{100} \sum\limits_{i=1}^{6}p_ix_i$
$x_0\geq0$
$x_1,...,x_0 \in Z$ 

### Modelli di Copertura
>Problema di assunzione nel motel
>$x_i=$ numero di persone che montano in fascia $i$.
>min z$=\sum\limits_{i=1}^{6}z_i$ 
>1. $x_1+x_6\geq4$
>2. $x_1+x_2\geq8$ 
>3. $x_2+x_4\geq10$
>4. $x_3+x_4\geq7$
>5. $x_4+x_5\geq12$
>6. $x_3+x_4\geq4$

$x_i\in Z$ con $i=1,...,6$

|       | $S_1$ | $S_2$ | $S_3$ | $S_4$ |
| ----- | ----- | ----- | ----- | ----- |
| $T_1$ | 20    | 25    | 15    | 5     |
| $T_2$ | 12    | 14    | 18    | 30    |
| $T_3$ | 19    | 11    | 40    | 12    |

|       | $S_1$    | $S_2$    | $S_3$ | $S_4$ |
| ----- | -------- | -------- | ----- | ----- |
| $T_1$ | $x_{11}$ | $x_{12}$ | ...   |       |
| $T_2$ | $x_{21}$ | ...      |       |       |
| $T_3$ | ...      |          |       |       |

$x_{ij}=$ numero di giornali spediti $T_i \to S_j$ con $i=1,2,3$ e $j=1,2,3,4$
min z$=0,02\sum\limits_{i=1}^{3}\sum\limits_{j=1}^{4} d_{ij}x_{ij}=0,02[20x_{11}+25x_{12}+...+12x_{34}]$ 

- $T_1=x_{11}+x_{12}+x_{13}+x_{14}\leq125'000$
- $T_2=x_{21}+x_{22}+x_{23}+x_{24}\leq180'000$
- $T_3=x_{31}+x_{32}+x_{33}+x_{34}\leq70'000$

- $s_1=x_{11}+x_{21}+x_{31}\geq100'000$
- $s_2=x_{12}+x_{22}+x_{32}\geq150'000$
- $s_3=x_{13}+x_{23}+x_{33}\geq50'000$
- $s_4=x_{14}+x_{24}+x_{34}\geq75'000$
$x_{ij}\in Z_+ \space \forall i,j \in N$

### Modelli multi-periodo

### Problemi di massimo/minimo

### Problemi con vincoli logici
M = "grande m" è una costante molto grande che serve nei vincoli per evitare che una variabile tenda a valori molti grandi.
vedi esempio su "Vincoli logici" nei lucidi della prima parte.

### Trasformazione Logica $\to$ Programmazione lineare
![[Pasted image 20240305112201.png|700]]
Mai moltiplicare due variabili.

<u>Pianificazione di coltivazioni</u>
VARIABILI
$x_{ij}=$ ha coltivati per tipo di coltivazione $i\in \{M,S,G\}$

max z = $5000(x_{MA}+x_{MB}+x_{MC})+7000(x_{SA}+x_{SB}+x_{SC})+6000(x_{GA}+x_{GB}+x_{GC})$

1. $x_{MA}+x_{SA}+x_{GA} \leq 600-200y_A$
2. $x_{MB}+x_{SB}+x_{GB}\leq 700-200y_A$
3. $x_{MC}+x_{SC}+x_{GC}\leq 450-200y_A$

1. $20000x_{MA}+10000x_{SA}+10000x_{GA} \leq 8*10^6$
2. $20000x_{MB}+10000x_{SB}+10000x_{GB} \leq 5*10^6$
3. $20000x_{MC}+10000x_{SC}+10000x_{GC} \leq 6*10^6$

> [vedi slide]

### Minimizzazione della total tardiness
VARIABILI
$t_i=$ istante di inizio del job $i$.   $t_i \in Z$
$y_i=$ tardiness del job $i$.
$x_{ij}=\begin{cases} 1 \space \space i \space precede \space j \\ 0 \space  altrimenti \end{cases}$   $i \neq j$ 

min $z=\sum\limits_{i=1}^{n} y_i$
$M=\sum\limits_{i=1}^{n} p_i$
$y_i\geq t_i+p_i-d_i$   $\forall i \in [1,n]$
$t_i+p_i\leq t_j+(1-x_{ij})M$     $\forall i\neq j$


VARIABILI
$x_{ij}=\begin{cases} 1 \text{   se job i è lavorato per j-esimo} \\ 0 \text{   altrimenti} \end{cases}$ 
$y_j=$ tardiness del j-esimo job della sequenza

min z = $\sum\limits_{j=1}^{n} y_j$ 
$\sum\limits_{j=1}^{n} x_{ij}=1$   $\forall i=1,2,...,n$
$\sum\limits_{j=1}^{n} x_{ij}=1$   $\forall j=1,2,...,n$

$y_i \geq \text{tempo di completamento} - \text{due date del j-esimo job}$
$y_i \geq (\sum\limits_{k=1}^{j} \sum\limits_{i=1}^{n} p_i*x_{ik})-\sum\limits_{i=1}^{n} d_i*x_{ij}$    $\forall j=1,2,...,n$ 