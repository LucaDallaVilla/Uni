### Prestazioni
Per calcolare la prestazione di un processore si può calcolare dal lasso di tempo tra l'input e l'output, ma anche dal numero di task eseguiti nell'unità di tempo.
Il clock indica il numero di task calcolati in un secondo e oggi è nell'ordine dei miliardi.
I core indicano il numero di processori in una CPU.

Quindi $\text{Tempo di CPU} = \dfrac{\text{Numero di istruzione} * \text{CPI}}{\text{Frequenza di clock}}$.

### Istruzioni di RISC-V
Contiene pochi tipi di istruzioni per semplicità del processore. Per questo motivo, risulta facile rendere il processore performante, seppur poco potente.
fetch $\to$ decode $\to$ execute

Registro = contenitore di bit (memoria)
Un registro è fatto da più circuiti a flip-flop capace di memorizzare 1 bit (totale 32 bit, da 0 a 31).
Word = registro da 32 bit.
Doubleword = registro da 64 bit.

|                          | Linguaggio C | RISC-V assember                   |                                                    |
| ------------------------ | ------------ | --------------------------------- | -------------------------------------------------- |
| <u>Addizione</u>:        | `a=b+c`      | add x5, x20, x21 / addi x5, x5, 5 | add con variabili, addi con costanti               |
| <u>Sottrazione</u>:      | ```a=b-c```  | sub x5, x20, x21                  |                                                    |
| <u>Load doubleword</u>:  | ```a```<br>  | ld x5, 24(x21)                    | registro di destinazione + offset + ind. base      |
| <u>Store doubleword</u>: | `a=1`        | sd x5, 16(x21)                    | registro del dato da scrivere + offset + ind. base |
```C
a = -a // sub x19, x0, x19
a = b // add x19, x0, x20 // sommo 0 a x20 (b) e lo salvo in x19 (a)
f = a + b + c // add x19, x20, x21 / sub x19, x19, x22
```

### Linguaggio macchina
Ogni istruzione del RISC-V è formata da una sequenza di 32 bit.

Vi sono vari formati, cioè modi di interpretare le sequenze di comando:
- <u>Formato di tipo R (registro)</u>: permette di codificare le istruzioni `add`, `sub`, `and`, `or`, `xor`...
	La sequenza viene suddivisa in campi, i quali sono responsabili di dare informazioni diverse sull'istruzione.
	`codop` rappresenta il codice operativo di istruzione (7 bit).
	`rd` è il registro destinazione (5 bit).
	`rs1` e `rs2` sono i registri dei 2 operandi (5 bit).
	`funz7` e `funz3` sono codici operativi aggiuntivi (7 e 3 bit).
	>`add x5, x9, x10` -> 0000000 01010 01001 000 00101 0110011
- <u>Formato di tipo I (immediato)</u>: permette di codificare le istruzioni `load`, `addi`, `andi`, `ori`...
	Tutte queste istruzioni hanno un immediato, cioè un numero costante non variabile.
	`codop` rappresenta il codice operativo di istruzione (7 bit).
	`immediato` la costante.
	`rd` registro destinazione.
	`rs1` registro sorgente.
	`funz3` codice operativo aggiuntivo (3 bit).
	> `addi x7, x5, -6` -> 111111111010 00101 000 00111 0010011
- <u>Formato di tipo S (store)</u>: permette di codificare le istruzioni di salvataggio in memoria `store`
	`codop` rappresenta il codice operativo di istruzione (7 bit).
	`rs1` e `rs2` registri sorgente.
	`immediato[11:5]` e `immediato[4:0]` la costante, suddivisa in 2 perché si vuole mantenere la stessa posizione del formato R.
	`funz3` codice operativo aggiuntivo (3 bit).
	> `sd x9, 24(x22)` -> 0000000 01001 10110 011 11000 0100011
- <u>Formato di tipo SB</u>: permette di eseguire i salti condizionati.
	`codop` rappresenta il codice operativo di istruzione (7 bit)
	`immediato` la costante
	`funz3` codice operativo aggiuntivo (3 bit)
	`rs1`, `rs2` registri sorgente

| Formato R |       |       |     |       |                |
| --------- | ----- | ----- | --- | ----- | -------------- |
| 0000000   | 01010 | 01001 | 000 | 00101 | 0110011        |
|           | x10   | x9    |     | x5    | istruzione add |

| Formato I    |       |     |       |         |
| ------------ | ----- | --- | ----- | ------- |
| 111111111010 | 00101 | 000 | 00111 | 0010011 |
| -6           | x5    |     | x7    | addi    |

| Formato S |       |       |         |            |         |
| --------- | ----- | ----- | ------- | ---------- | ------- |
| 0000000   | 01001 | 10110 | 011     | 11000      | 0100011 |
| imm. 1    | x9    | x22   | istruz. | imm.2 (24) | istruz. |

### Operazioni logiche
Nello shift vengono spostati tutti i bit di posizione.
<u>Shift logico dx</u>: divisione per 2.
<u>Shift logico sx</u>: moltiplicare per 2.
<u>Shift aritmetico dx</u>: mantiene il bit di segno.

<u>And</u>: operatore and bit a bit di due registri a 64 bit.
<u>Or</u>: operatore or bit a bit di due registri a 64 bit.
<u>Xor</u> operatore xor bit a bit di due registri a 64 bit.
<u>Not</u>: (pseudoistruzione del compilatore) // TODO

### Salti condizionali
Normalmente, ad ogni esecuzione di un comando, viene aumentato il Program Counter di 4 byte, in modo da passare a quella successiva.
Nei salti condizionali (`if`, `while`, `for`...) viene modificato il normale flusso del PC con un valore preciso.
> `beq rs1, rs1, L1`:  se il valore dei registri `rs1` e `rs2` è uguale, PC viene modificato con il valore dell'etichetta `L1`.

> `if-else`
> ![[Pasted image 20240315114529.png]]
> In questo esempio viene eseguito `sub` solo se è verificato il `bne`. Nel caso opposto, viene eseguito l'`add` e il salto incondizionato fuori dall'`if` (`beq x0, x0, ENDIF` viene sempre eseguito perché confronta 0 con 0. Salta quindi all'etichetta `ENDIF`).

> `for`
> ![[Pasted image 20240315121046.png]]
> Il controllo del ciclo viene effettuato testando la negazione di `i<100`, se è verificata si salta giù all'`ENDFOR`. 
> Al contrario, se la condizione del ciclo è ancora valida, il comando `beq` fa un salto condizionato ogni volta che viene conclusa l'esecuzione del corpo del ciclo.

