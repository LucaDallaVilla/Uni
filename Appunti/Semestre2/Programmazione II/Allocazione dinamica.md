```C
int main() {
	int aautomatico[N];
	int *adinamico=(int *)malloc(sizeof(int)*N);

	init(aautomatico);
	stampta(aautomatico); // in entrambi i casi sto passando i parametri per riferimento

	init(adinamico);
	stampa(adinamico);
}
```

heap -> malloc/free