## Codice originale

```asm
# Contesto iniziale:
# x25 = salva[] (indirizzo base dell'array)
# x22 = i (indice corrente)
# x24 = k (valore da cercare)

SLLI x26, x22, 3      # x26 = i * 8 (offset in byte)
loop: 
    ADD x26, x25, x26  # x26 = indirizzo di salva[i]
    LD x26, 0(x26)     # x26 = valore di salva[i]
    BNE x26, x24, pippo # se salva[i] != k, esci
    ADDI x22, x22, 1   # i++
    BEQ x26, x26, loop # jump incondizionato a loop
pippo:
    # fine del ciclo
```

---

## Registri utilizzati

|Registro|Contenuto|Tipo|Descrizione|
|---|---|---|---|
|`x25`|`salva[]`|Puntatore|Indirizzo base dell'array (es. 0x10000000)|
|`x22`|`i`|Indice|Contatore del loop, incrementato ad ogni iterazione|
|`x24`|`k`|Valore|Costante di confronto, non viene modificata|
|`x26`|_variabile_|Lavoro|Usato per offset, indirizzo e valore temporaneo|

---

## Analisi dettagliata istruzione per istruzione

### 1️⃣ `SLLI x26, x22, 3` - Calcolo dell'offset

**Shift Left Logical Immediate**

**Cosa fa:**

- Sposta i bit di `x22` (indice `i`) di 3 posizioni a sinistra
- Salva il risultato in `x26`
- Equivale a: `x26 = i * 8`

**Perché shift di 3?**

- Spostare di `n` posizioni = moltiplicare per $2^n$
- Shift di 3 = moltiplicare per $2^3 = 8$
- Ogni elemento dell'array è un **doubleword** (8 byte)
- Per accedere a `salva[i]` serve un offset di `i * 8` byte

**Esempio visivo:**

```
i = 5 (binario: 00000101)
Shift << 3: 00101000 (= 40 decimale)
Risultato: x26 = 40 (offset in byte per salva[5])
```

**Layout memoria array:**

```
Indirizzo      Elemento     Offset
0x10000000  →  salva[0]     0 byte
0x10000008  →  salva[1]     8 byte
0x10000010  →  salva[2]     16 byte
0x10000018  →  salva[3]     24 byte
```

> [!tip] Alternativa senza shift
> 
> ```asm
> addi x27, x0, 8    # x27 = 8
> mul x26, x22, x27  # x26 = i * 8
> ```
> 
> Ma `SLLI` è più veloce (1 ciclo vs multipli cicli per `MUL`)

---

### 2️⃣ `ADD x26, x25, x26` - Calcolo indirizzo effettivo

**Addizione**

**Cosa fa:**

- Somma `x25` (indirizzo base) con `x26` (offset)
- Formula: `x26 = x25 + x26`
- `x26` ora contiene l'**indirizzo** di `salva[i]`

**Esempio numerico:**

```
x25 = 0x10000000  (base dell'array)
x26 = 24          (offset, calcolato da i=3)
-----------------------------------
Dopo ADD:
x26 = 0x10000018  (indirizzo di salva[3])
```

**Rappresentazione memoria:**

```
Memoria                    Registri
─────────────────         ──────────────────
0x10000000: [val0]        x25 → 0x10000000
0x10000008: [val1]        x26 → 0x10000018 ←┐
0x10000010: [val2]                          │
0x10000018: [val3] ←──────────────────────┘
0x10000020: [val4]        (punta qui)
```

---

### 3️⃣ `LD x26, 0(x26)` - Caricamento valore dalla memoria

**Load Doubleword**

**Sintassi:** `LD destinazione, offset(base)`

- `destinazione`: dove salvare (`x26`)
- `offset`: spostamento in byte (`0`)
- `base`: registro con l'indirizzo (`x26`)

**Cosa fa:**

1. Calcola indirizzo: `x26 + 0 = x26`
2. Legge **8 byte** dalla memoria a quell'indirizzo
3. Salva il valore letto in `x26` (sovrascrive l'indirizzo!)

**Trasformazione:**

```
PRIMA di LD:
x26 = 0x10000018  (indirizzo)

Memoria[0x10000018] = 42  (valore memorizzato)

DOPO LD:
x26 = 42  (valore caricato)
```

> [!warning] Attenzione `x26` viene **sovrascritto**: da indirizzo diventa valore!

**Equivalente in C:**

```c
// Prima: x26 è un puntatore
long* ptr = &salva[i];  // x26 = indirizzo

// Dopo: x26 è il valore puntato
long valore = *ptr;     // x26 = contenuto
```

---

### 4️⃣ `BNE x26, x24, pippo` - Confronto e uscita

**Branch if Not Equal**

**Cosa fa:**

- Confronta `x26` (valore di `salva[i]`) con `x24` (valore `k`)
- Se **diversi** (`≠`): salta a `pippo` → **esce dal loop**
- Se **uguali** (`=`): continua → **resta nel loop**

**Logica:**

```
if (salva[i] != k) {
    goto pippo;  // termina il loop
}
// altrimenti continua...
```

**Esempi:**

|`x26` (salva[i])|`x24` (k)|Risultato|Azione|
|---|---|---|---|
|42|42|Uguali|Continua (ADDI)|
|99|42|Diversi|Salta a `pippo`|
|0|0|Uguali|Continua (ADDI)|

**Questa è la condizione di uscita del loop!**

---

### 5️⃣ `ADDI x22, x22, 1` - Incremento indice

**Add Immediate**

**Cosa fa:**

- `x22 = x22 + 1`
- Incrementa l'indice `i` di 1
- Equivale a `i++` in C

**Quando viene eseguita:**

- **Solo se** il `BNE` precedente NON ha saltato
- Cioè **solo se** `salva[i] == k`

**Sequenza:**

```
┌─ BNE: salva[i] != k?
│
├─ NO (sono uguali) → esegue ADDI (i++)
│                      └─ passa al prossimo elemento
│
└─ SÌ (sono diversi) → salta a pippo
                       └─ termina il loop
```

**Esempio:**

```
Iterazione 1: i=0, salva[0]=5, k=5 → uguali → i++ → i=1
Iterazione 2: i=1, salva[1]=5, k=5 → uguali → i++ → i=2
Iterazione 3: i=2, salva[2]=7, k=5 → diversi → salta a pippo
```

---

### 6️⃣ `BEQ x26, x26, loop` - Ritorno all'inizio

**Branch if Equal (salto incondizionato)**

**Trucco intelligente:**

- Confronta `x26` con **se stesso**
- Un registro è **sempre uguale a se stesso**!
- Quindi questa istruzione **salta sempre**

**Perché questo trucco?**

- RISC-V non ha un'istruzione `JUMP` diretta
- Esistono solo branch condizionali (`BEQ`, `BNE`, ecc.)
- Per fare un salto incondizionato si usa questo pattern

**Alternative equivalenti:**

```asm
J loop          # pseudoistruzione (più leggibile)
JAL x0, loop    # istruzione reale (x0 ignora il return address)
BEQ x26, x26, loop  # il trucco usato nel codice
```

**Flusso del loop:**

```
    ┌──────────────────────┐
    │      loop:           │
    │  ADD (indirizzo)     │
    │  LD (carica valore)  │
    │  BNE (confronta)     ├─── diverso → pippo (esci)
    │  ADDI (i++)          │
    │  BEQ (torna inizio)  │
    └──────┬───────────────┘
           │
           └─── (loop infinito finché salva[i] == k)
```

---

### 7️⃣ `pippo:` - Etichetta di uscita

**Punto di terminazione del loop**

**Stato registri all'uscita:**

```
x22 = i         (indice del primo elemento diverso da k)
x26 = salva[i]  (il valore diverso che ha causato l'uscita)
x24 = k         (invariato)
x25 = salva[]   (invariato)
```

**Esempio completo:**

```
Array: salva[] = {5, 5, 5, 7, 5, 5}
k = 5
i iniziale = 0

Iterazione 1: i=0, salva[0]=5, 5==5 ✓ continua, i=1
Iterazione 2: i=1, salva[1]=5, 5==5 ✓ continua, i=2
Iterazione 3: i=2, salva[2]=5, 5==5 ✓ continua, i=3
Iterazione 4: i=3, salva[3]=7, 7≠5 ✗ ESCE

Risultato: x22 = 3 (primo indice con elemento diverso)
```

---

## Equivalente in linguaggi ad alto livello

### C

```c
while (salva[i] == k) {
    i++;
}
```

### Python

```python
while salva[i] == k:
    i += 1
```

### Pseudocodice dettagliato

```
RIPETI
    carica valore da salva[i]
    SE valore ≠ k ALLORA
        esci dal loop
    ALTRIMENTI
        incrementa i
    FINE SE
FINE RIPETI
```

---

## Diagramma di flusso

```mermaid
graph TD
    A[Inizio: calcola offset i*8] --> B[Calcola indirizzo: base + offset]
    B --> C[Carica valore da memoria]
    C --> D{salva[i] != k?}
    D -->|Sì| E[Fine: esci a pippo]
    D -->|No| F[Incrementa i++]
    F --> B
    
    style E fill:#f96
    style F fill:#9f6
```

---

## Riepilogo registri durante l'esecuzione

|Fase|x22|x24|x25|x26|
|---|---|---|---|---|
|**Inizio**|i|k|&salva[0]|-|
|**Dopo SLLI**|i|k|&salva[0]|i*8|
|**Dopo ADD**|i|k|&salva[0]|&salva[i]|
|**Dopo LD**|i|k|&salva[0]|salva[i]|
|**Dopo ADDI**|i+1|k|&salva[0]|salva[i]|
|**Loop ripete**|i+1|k|&salva[0]|(i+1)*8|

---

## Problemi e limitazioni

> [!danger] Bug critico: nessun controllo dei limiti! Se tutti gli elementi sono uguali a `k`, il loop continua oltre la fine dell'array causando:
> 
> - **Segmentation fault** (accesso a memoria non valida)
> - **Loop infinito**
> - **Comportamento indefinito**

### Soluzione proposta

```asm
# Aggiungere prima del loop:
addi x27, x0, N  # x27 = lunghezza array

# Nel loop, prima del BNE:
BGE x22, x27, pippo  # se i >= N, esci
```

---

## Ottimizzazioni possibili

### ❌ Codice attuale (inefficiente)

```asm
loop:
    SLLI x26, x22, 3    # ricalcola offset ogni volta
    ADD x26, x25, x26   # ricalcola indirizzo ogni volta
    LD x26, 0(x26)
    BNE x26, x24, pippo
    ADDI x22, x22, 1
    BEQ x26, x26, loop
```

### ✅ Codice ottimizzato

```asm
SLLI x26, x22, 3       # calcola offset iniziale una volta sola
ADD x26, x25, x26      # calcola indirizzo iniziale

loop:
    LD x27, 0(x26)     # carica valore (usa x27)
    BNE x27, x24, pippo
    ADDI x26, x26, 8   # avanza di 8 byte direttamente
    ADDI x22, x22, 1
    J loop             # salto più chiaro

pippo:
```

**Vantaggi:**

- ✅ Nessun ricalcolo di offset/indirizzo
- ✅ Incremento diretto del puntatore (+8)
- ✅ Codice più leggibile (`J` invece di `BEQ x26, x26`)
- ✅ Usa un registro separato (x27) per non sovrascrivere x26

---

## Utilizzi pratici

Questo pattern è comunemente usato per:

1. **Contare elementi consecutivi** con un certo valore
2. **Saltare padding** o dati invalidi in un array
3. **Trovare la fine** di una sequenza omogenea
4. **Pattern matching** semplice su array
5. **Parsing di stringhe** (cercare terminatore o carattere speciale)

### Esempio reale: cercare il primo spazio in una stringa

```asm
# x25 = indirizzo stringa
# x24 = ' ' (carattere spazio)
# Trova il primo spazio nella stringa
```

---

## Riepilogo finale

| Aspetto             | Descrizione                                         |
| ------------------- | --------------------------------------------------- |
| **Funzione**        | Scorre l'array finché `salva[i] == k`, poi si ferma |
| **Input**           | `i` (indice start), `k` (valore), `salva[]` (array) |
| **Output**          | `i` (indice primo elemento ≠ k)                     |
| **Complessità**     | O(n) tempo, O(1) spazio                             |
| **Bug**             | Nessun controllo limiti array                       |
| i**Ottimizzazioni** | Evitare ricalcolo offset, usare incremento diretto  |