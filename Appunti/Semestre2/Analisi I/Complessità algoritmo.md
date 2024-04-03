$a_n$ rappresenta il numero di operazioni di un algoritmo con n uguale al numero di componenti in input.

> Algoritmo di ricerca di un numero dato, 40, in un'array ordinata di lunghezza $n$.
> 1. Ricerca esaustiva: scorriamo il vettore da sinistra a destra alla ricerca del numero 40. Nel caso peggiore in cui 40 non sia nell'array e tutti gli elementi siano minori di 40, l'algoritmo fa $n$ operazioni. $a_n=9 \Rightarrow O(n)$
> 2. Ricerca binaria: Divido a metà l'array e inizio a vedere la prima cella nella metà di destra. Se non è =40, posso essere sicuro di non trovare il numero nella metà di sinistra. Continuo il procedimento finché non esaurisco le celle oppure trovo il numero. $a_n=3 \Rightarrow O(\log_2 n)$. In generale $a_n=\dfrac{n}{2^m}=1$ in cui $m=\log_2 n$.

La gerarchia degli infiniti ci aiuta a capire quale algoritmo sia più efficiente in termini di numero di operazioni (e presumibilmente di tempo). 