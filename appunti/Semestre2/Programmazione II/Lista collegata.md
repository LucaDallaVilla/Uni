Una lista di tipo T contiene il valore dell'elemento e la lista collegata sempre di tipo T.
- `h`: il valore
- `tI`: la lista collegata
È quindi considerato una struttura ricorsiva (o autoreferenziale).

```C
typedef struct listNode ∗List; // Il tipo delle liste
struct listNode {
	T data;
	List nextPtr;
};
```
