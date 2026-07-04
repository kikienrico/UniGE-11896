---
titolo: "Appunti ASD — Esame Scritto (UniGE) — VERSIONE ESTESA"
corso: "Algoritmi e Strutture Dati"
esame: "14 luglio"
tipo: "Appunti approfonditi — versione ampliata di Appunti_ASD_Scritto"
tags: [asd, unige, esame, appunti, algoritmi, esteso]
---

# 📘 Appunti ASD — Scritto (versione ESTESA)

> [!info] Come funziona lo scritto (dai testi d'esame reali)
> L'esame è formato da **3 domande** (chi non ha agevolazioni le fa tutte e 3; con DSA/Patto se ne scelgono 2). Alcune parti sono **"Sbarramento"**: se sbagli quelle, il compito **non viene corretto**. Gli argomenti pescati sono **sempre** questi 6:
> **QuickSort · MergeSort · Heap binari · Binary Search Tree · Tabelle di Hash · Grafi (BFS/DFS)**.

> [!warning] Cosa valuta davvero il prof (ripetuto in ogni testo)
> 1. **Descrivere l'algoritmo** in modo chiaro e corretto (testo + disegni).
> 2. **Complessità**: quanto vale nel caso migliore / medio / peggiore, **QUANDO** si ricade in quel caso, e **COME** si calcola. ⚠️ *"Le risposte sulla complessità saranno valutate solo se la descrizione dell'algoritmo è corretta."*
> 3. **Simulare** un'esecuzione (disegnare i passaggi).
>
> Quindi per ogni argomento questa versione estesa ti dà: **(a)** la descrizione "da tema", **(b)** la complessità con QUANDO+COME e il **calcolo per esteso**, **(c)** simulazioni complete passo-passo, **(d)** gli **errori tipici** che costano punti.

## 📑 Indice
- [[#🧮 SEZIONE 0 — Complessità (Θ, O, Ω): capirla e calcolarla]]
- [[#1 · QUICKSORT]]
- [[#2 · MERGESORT]]
- [[#3 · HEAP BINARI]]
- [[#4 · BINARY SEARCH TREE (BST)]]
- [[#5 · TABELLE DI HASH]]
- [[#6 · GRAFI — visite BFS e DFS]]
- [[#📊 Riepilogo complessità (da sapere a memoria)]]
- [[#🧯 Errori tipici trasversali]]
- [[#🗓️ Piano di ripasso fino al 14 luglio]]

---

# 🧮 SEZIONE 0 — Complessità (Θ, O, Ω): capirla e calcolarla

## 0.1 Cosa stiamo misurando davvero

> [!note] 💬 In parole povere
> La **complessità** non misura i secondi (dipenderebbero dal computer), ma **quante operazioni elementari** fa l'algoritmo in funzione della dimensione dell'input $n$. Ci interessa **come cresce** questo numero quando $n$ diventa grande: se raddoppio i dati, il tempo raddoppia? quadruplica? resta uguale?

### Il modello di Knuth (come lo introduce la prof. Mascardi)
Il tempo di esecuzione esatto sarebbe la **somma di (costo × frequenza)** di ogni operazione:
$$T(n) = c_1\cdot\#op_1 + c_2\cdot\#op_2 + \dots$$
dove ogni operazione elementare ("$=$", "$<$", "$++$", `cout`, `cin`…) ha un suo costo $c_i$ e viene eseguita un certo numero di volte. Questo calcolo è **troppo complicato e inutile**: le costanti $c_i$ dipendono dalla macchina. Perciò si passa alla **notazione asintotica**, che tiene **solo il termine dominante** e butta via costanti e termini minori.

**Esempio**: $T(n) = 3n^2 + 5n + 12$. Per $n$ grande, $3n^2$ domina tutto ($n=1000$: $3n^2 = 3.000.000$, mentre $5n+12 = 5012$). Quindi $T(n) = \Theta(n^2)$: butto via il 3, il $5n$ e il 12.

## 0.2 I tre simboli: O, Ω, Θ

| Simbolo | Si legge | Significato intuitivo | Uso tipico |
|---|---|---|---|
| $O(f(n))$ | "O grande di f" | **limite superiore**: "al massimo cresce come $f$" | caso peggiore |
| $\Omega(f(n))$ | "Omega di f" | **limite inferiore**: "almeno cresce come $f$" | caso migliore |
| $\Theta(f(n))$ | "Theta di f" | **crescita esatta**: cresce *proprio* come $f$ (vale sia $O$ che $\Omega$) | quando lo sappiamo esattamente |

> [!tip] Come usarli senza sbagliare all'esame
> - Se un algoritmo fa **sempre** lo stesso lavoro (es. MergeSort), puoi scrivere $\Theta(n\log n)$ senza specificare il caso.
> - Se il lavoro **dipende dai dati** (es. QuickSort), specifica il caso: "migliore $\Theta(n\log n)$, peggiore $\Theta(n^2)$".
> - Dire "QuickSort è $O(n^2)$" è **corretto** (limite superiore), ma dire "QuickSort è $\Theta(n^2)$" senza specificare "nel caso peggiore" è **sbagliato**.

## 0.3 La scala delle crescite (dalla migliore alla peggiore)

$$\Theta(1) < \Theta(\log n) < \Theta(n) < \Theta(n\log n) < \Theta(n^2) < \Theta(n^3)$$

| Classe | Nome | Intuizione | Se $n$ raddoppia… |
|---|---|---|---|
| $\Theta(1)$ | costante | lavoro fisso, non guarda i dati | tempo invariato |
| $\Theta(\log n)$ | logaritmica | **dimezzo** il problema a ogni passo | tempo +1 passo |
| $\Theta(n)$ | lineare | tocco ogni elemento **una volta** | tempo ×2 |
| $\Theta(n\log n)$ | linearitmica | $\log n$ "giri" da $n$ lavoro ciascuno | poco più di ×2 |
| $\Theta(n^2)$ | quadratica | per ogni elemento riguardo **tutti** gli altri | tempo ×4 |
| $\Theta(n^3)$ | cubica | tre cicli annidati (es. prodotto di matrici) | tempo ×8 |

**Per sentire la differenza** con $n = 1.000.000$:
- $\log_2 n \approx 20$ operazioni → istantaneo
- $n = 10^6$ → istantaneo
- $n\log n \approx 2\cdot 10^7$ → veloce
- $n^2 = 10^{12}$ → **minuti/ore**. Ecco perché $n\log n$ vs $n^2$ non è un dettaglio.

## 0.4 Il logaritmo, senza paura

$\log_2 n$ risponde alla domanda: **"quante volte devo dimezzare $n$ per arrivare a 1?"**
- $\log_2 8 = 3$ perché $8 \to 4 \to 2 \to 1$ (3 dimezzamenti).
- $\log_2 1024 = 10$; $\log_2 1.000.000 \approx 20$.

Compare in due situazioni ricorrenti all'esame:
1. **Ricerca binaria**: a ogni confronto scarto metà array → dopo $\log_2 n$ passi resta 1 elemento.
2. **Altezza di un albero binario completo/quasi completo**: a ogni livello i nodi **raddoppiano** ($1, 2, 4, 8, \dots$), quindi con $n$ nodi bastano $\approx\log_2 n$ livelli. Per questo heap (sempre quasi completo) e BST **bilanciato** hanno operazioni $\Theta(\log n)$: il lavoro segue un cammino radice→foglia, lungo quanto l'altezza.

> [!note] 💬 Ricerca lineare vs binaria (il classico esempio $O(n)$ vs $O(\log n)$)
> - **Lineare**: scorri da sinistra finché trovi → al massimo $n$ passi → $O(n)$. Funziona su array **qualsiasi**.
> - **Binaria** (solo su array **ordinato**): guardi l'elemento **centrale** `(inizio+fine)/2`; se è quello cercato hai finito; se il cercato è più piccolo prosegui a sinistra, se più grande a destra. **Dimezzi** ogni volta → $O(\log n)$. *(Su 40.000 elementi: ~16 confronti invece di 40.000.)*

## 0.5 La "ricetta" per calcolare la complessità di un codice

1. **Operazioni semplici** (assegnamenti, confronti, aritmetica) → $\Theta(1)$.
2. **Sequenza** di blocchi → si **somma**, e vince il termine dominante: $\Theta(n) + \Theta(n^2) = \Theta(n^2)$.
3. **Ciclo** → (numero di iterazioni) × (costo del corpo): ciclo da $n$ iterazioni con corpo $\Theta(1)$ → $\Theta(n)$.
4. **Cicli annidati** → si **moltiplica**: due cicli da $n$ → $\Theta(n^2)$.
5. **Ciclo che dimezza** (`i = i/2` oppure `i = i*2`) → $\Theta(\log n)$ iterazioni.
6. **Ricorsione** → conta i livelli dell'albero delle chiamate × lavoro per livello (vedi MergeSort/QuickSort).

## 0.6 Tabella degli esempi tipici (quella del prof — a memoria)

| Complessità | Esempio tipico |
|---|---|
| $O(1)$ | verificare se un numero è pari/dispari |
| $O(\log n)$ | **ricerca binaria** in un array **ordinato** |
| $O(n)$ | **ricerca lineare** in un array (non ordinato) |
| $O(n\log n)$ | **MergeSort**, QuickSort (caso medio/migliore) |
| $O(n^2)$ | **Insertion Sort, Bubble Sort, Selection Sort**; QuickSort caso peggiore |
| $O(n^3)$ | moltiplicazione di matrici $n\times n$ |

> [!tip] Gli ordinamenti $O(n^2)$ (il prof li cita come confronto — basta conoscerne idea e complessità)
> - **Selection Sort**: a ogni passo cerca il **minimo** della parte non ordinata e lo mette in coda alla parte ordinata. Confronti: $(n-1)+(n-2)+\dots+1 = \frac{n(n-1)}{2} = \Theta(n^2)$ **sempre** (non adattivo).
> - **Bubble Sort**: scorre scambiando coppie adiacenti fuori ordine, ripetendo finché non ci sono più scambi → $O(n^2)$; adattivo nella versione con flag (già ordinato → $O(n)$).
> - **Insertion Sort**: prende ogni elemento e lo **inserisce** al posto giusto tra quelli già ordinati a sinistra → $O(n^2)$ nel peggiore (array al contrario), ma è **adattivo**: su array già/quasi ordinato fa solo $n-1$ confronti → $O(n)$.

## 0.7 Le tre parole chiave che ricorrono nei temi d'esame

> [!important] Definizioni da sapere alla lettera
> - **Adattivo**: l'algoritmo "si accorge" se i dati sono già (parzialmente) ordinati e fa **meno lavoro**. *Insertion Sort sì; MergeSort NO (fa sempre tutto); QuickSort dipende dal pivot, e attenzione: con pivot = primo elemento, l'array già ordinato è il suo caso PEGGIORE.*
> - **In place**: usa solo $O(1)$ memoria extra (ordina "dentro" l'array). *QuickSort sì; MergeSort NO (il merge richiede un array d'appoggio $\Theta(n)$).*
> - **Stabile**: elementi **uguali** mantengono l'ordine relativo che avevano. *MergeSort sì (nel merge, a parità prendo da sinistra); QuickSort in generale no.*

## 0.8 Caso migliore / medio / peggiore — perché esistono

Lo **stesso** algoritmo può fare più o meno lavoro a seconda di **come sono fatti i dati** (non di quanto sono grandi!).
- **Caso migliore**: l'input più fortunato possibile (es. per Insertion Sort: array già ordinato).
- **Caso peggiore**: l'input più sfortunato (es. per QuickSort con pivot=primo: array già ordinato!).
- **Caso medio**: comportamento "in media" su input casuali.

All'esame la domanda è sempre tripla: **quanto vale** + **quando succede** + **come si calcola**. Rispondi sempre a tutte e tre le parti.

---

# 1 · QUICKSORT

## 1.1 L'idea

> [!note] 💬 In parole povere
> QuickSort è un algoritmo **"divide et impera"**: invece di ordinare tutta la sequenza in un colpo, la spezza in problemi più piccoli. Il trucco è la **partition**: scegli un elemento, detto **pivot**, e riorganizzi la sequenza mettendo **tutti i minori del pivot a sinistra** e **tutti i maggiori o uguali a destra**. A quel punto **il pivot è già al suo posto definitivo** (ha tutti i più piccoli prima e tutti i più grandi dopo). Poi ripeti **ricorsivamente** la stessa cosa sulle due parti, finché ogni pezzo ha 0 o 1 elementi — e a quel punto tutto è ordinato.

**Perché funziona**: dopo ogni partition il pivot non si muoverà mai più; ogni chiamata ricorsiva sistema definitivamente almeno un elemento.

## 1.2 Algoritmo (descrizione "da tema d'esame")

1. **Caso base**: se la sequenza ha 0 o 1 elementi è già ordinata → non fare nulla.
2. Scegli un **pivot** (convenzione del corso: **il primo elemento**).
3. **Partition**: scorri gli altri elementi e dividili in due gruppi: quelli **$<$ pivot** e quelli **$\ge$ pivot**.
4. Richiama ricorsivamente QuickSort sul gruppo di sinistra e su quello di destra.
5. Risultato: `[sinistra ordinata] + [pivot] + [destra ordinata]`.

```
quicksort(S):
    if |S| ≤ 1: return S                     // caso base
    pivot ← primo elemento di S
    Sx ← { x ∈ S \ {pivot} : x < pivot }     // partition
    Sd ← { x ∈ S \ {pivot} : x ≥ pivot }
    return quicksort(Sx) + [pivot] + quicksort(Sd)
```

## 1.3 Complessità: QUANDO e COME (la parte che vale i punti)

Ogni chiamata su una sequenza di lunghezza $k$ fa la partition in $\Theta(k)$ (confronta ogni elemento col pivot **una volta**). Il costo totale dipende quindi da **quanto sono bilanciate le partizioni**, cioè dalla fortuna nella scelta del pivot.

| Caso | Complessità | QUANDO si verifica | COME si calcola |
|---|---|---|---|
| **Migliore** | $\Theta(n\log n)$ | pivot = **mediano** a ogni passo (divide in due metà uguali) | ricorrenza $T(n)=2T(n/2)+\Theta(n)$: albero di altezza $\log n$, ogni livello costa $\Theta(n)$ |
| **Medio** | $\Theta(n\log n)$ | pivot scelto **a caso** (randomizzato) | in media le partizioni sono "abbastanza" bilanciate: stesso ragionamento del caso migliore, a meno di costanti |
| **Peggiore** | $\Theta(n^2)$ | pivot = **massimo o minimo** a ogni passo (es. sequenza **già ordinata** con pivot = primo) | $T(n)=T(n-1)+\Theta(n)$: la somma è $n+(n-1)+\dots+1=\frac{n(n+1)}{2}=\Theta(n^2)$ |

### Il calcolo del caso migliore, per esteso
Se il pivot è il mediano, ogni chiamata su $n$ elementi genera due chiamate su $\approx n/2$ elementi. L'albero delle chiamate:
- livello 0: 1 problema da $n$ → lavoro $n$
- livello 1: 2 problemi da $n/2$ → lavoro $2\cdot n/2 = n$
- livello 2: 4 problemi da $n/4$ → lavoro $n$
- … ogni livello costa $\Theta(n)$, e i livelli sono $\log_2 n$ (dimezzo fino a 1).

Totale: $\log n$ livelli × $\Theta(n)$ = $\Theta(n\log n)$.

### Il calcolo del caso peggiore, per esteso
Se il pivot è sempre il minimo (o il massimo), la partition produce una parte **vuota** e una con $n-1$ elementi: la ricorsione non dimezza niente, **scala di 1**. I costi delle chiamate sono:
$$n + (n-1) + (n-2) + \dots + 2 + 1 = \frac{n(n+1)}{2} = \Theta(n^2)$$
L'albero delle chiamate degenera in una **"catena"** alta $n$ invece che $\log n$.

> [!warning] Dettaglio che fa guadagnare punti
> Il caso migliore (pivot = mediano esatto) è **solo teorico**: per conoscere il mediano dovresti aver già "quasi ordinato" la sequenza. In pratica si usa il **pivot randomizzato**: rende *estremamente improbabile* il caso peggiore e garantisce il caso medio $\Theta(n\log n)$. Nota anche il paradosso: con pivot = primo elemento, **l'input già ordinato è il caso PEGGIORE** — l'esatto contrario di un algoritmo adattivo.

## 1.4 Simulazione completa — caso "normale" su `29 17 82 33 23 41 59 16`

Pivot = primo elemento di ogni sottosequenza:

```
quicksort([29,17,82,33,23,41,59,16])
  pivot=29 → Sx=[17,23,16]   Sd=[82,33,41,59]

  quicksort([17,23,16])
    pivot=17 → Sx=[16]  Sd=[23]     → [16] + 17 + [23] = [16,17,23]

  quicksort([82,33,41,59])
    pivot=82 → Sx=[33,41,59]  Sd=[]
      quicksort([33,41,59])
        pivot=33 → Sx=[]  Sd=[41,59]
          quicksort([41,59]): pivot=41 → Sd=[59] → [41,59]
        → 33 + [41,59] = [33,41,59]
    → [33,41,59] + 82 = [33,41,59,82]

risultato: [16,17,23] + 29 + [33,41,59,82] = [16,17,23,29,33,41,59,82]  ✓
```

## 1.5 Simulazione del CASO PEGGIORE su `82 17 33 29 23 41 59 16` (pivot = primo)

Qui il primo pivot (82) è il **massimo**: la partition produce subito una parte vuota.

```
pivot=82 → Sx=[17,33,29,23,41,59,16]   Sd=[]        ← parte vuota!
  pivot=17 → Sx=[16]                    Sd=[33,29,23,41,59]
    pivot=33 → Sx=[29,23]  Sd=[41,59]
      pivot=29 → Sx=[23]   Sd=[]                     ← di nuovo vuota
      pivot=41 → Sx=[]     Sd=[59]                   ← di nuovo vuota
```
Quando le partizioni continuano a produrre parti vuote, i confronti si sommano come $n+(n-1)+\dots+1 = \Theta(n^2)$. Risultato finale: `16 17 23 29 33 41 59 82`.

> Nota: in questo esempio *non tutti* i passi sono degeneri (33 divide decentemente) — il caso peggiore "puro" è la sequenza **già ordinata** (o ordinata al contrario) con pivot = primo: lì **ogni** partition ha una parte vuota.

## 1.6 Proprietà da citare se richieste

- **In place**: sì (nella versione con scambi dentro l'array); non serve memoria proporzionale a $n$ oltre allo stack di ricorsione.
- **Stabile**: in generale **no** (la partition può invertire elementi uguali).
- **Adattivo**: no nel senso classico; con pivot fisso l'input ordinato è addirittura il peggiore.

## 1.7 🧯 Errori tipici all'esame

> [!danger] Da evitare
> 1. Dire "il caso peggiore è quando l'array è disordinato" — **falso**: con pivot = primo, il peggiore è l'array **già ordinato** (o al contrario).
> 2. Dimenticare di dire **come** si calcola il $\Theta(n^2)$ (la somma $n+(n-1)+\dots+1$): la domanda chiede sempre QUANDO **e** COME.
> 3. Scrivere che la partition costa $\Theta(n\log n)$: no, **una** partition costa $\Theta(k)$ sulla sottosequenza di lunghezza $k$; è il **totale** che diventa $n\log n$ o $n^2$.
> 4. Nel simulare, spostare il pivot dentro Sx o Sd: il pivot sta **fuori**, tra le due parti.
> 5. Mettere gli **uguali al pivot** in Sx: la convenzione qui è $<$ a sinistra, $\ge$ a destra. Sii coerente per tutta la simulazione.

## 1.8 🎤 Domande tipiche + risposte modello

**"Complessità di quicksort nel caso peggiore: quanto vale, quando si verifica e come si calcola?"**
> Vale $\Theta(n^2)$. Si verifica quando il pivot scelto è sempre il massimo o il minimo della sottosequenza (ad esempio sequenza già ordinata con pivot = primo elemento): la partition produce una sottosequenza vuota e una con $n-1$ elementi. Il costo si calcola sommando le partition di ogni chiamata: $n+(n-1)+\dots+1 = \frac{n(n+1)}{2} = \Theta(n^2)$.

**"Perché il caso migliore è $\Theta(n\log n)$ e quando si verifica?"**
> Si verifica quando il pivot è sempre il mediano: le due parti hanno la stessa dimensione e l'albero delle chiamate ha altezza $\log_2 n$. Ad ogni livello dell'albero il lavoro complessivo delle partition è $\Theta(n)$, quindi il totale è $\Theta(n)\cdot\log n = \Theta(n\log n)$. È un caso teorico: in pratica si usa il pivot randomizzato, che dà lo stesso ordine di grandezza in media.

**"QuickSort è stabile? È in place?"**
> È in place (riordina dentro l'array con memoria extra costante, a parte lo stack di ricorsione), ma non è stabile: la partition può scambiare l'ordine relativo di elementi uguali.

---

# 2 · MERGESORT

## 2.1 L'idea

> [!note] 💬 In parole povere
> Anche MergeSort è **"divide et impera"**, ma è più "meccanico" di QuickSort: non sceglie niente, **divide sempre a metà** (a prescindere dai valori), finché restano pezzi da 1 elemento (che sono banalmente ordinati). Poi li **riunisce (merge / fondi)** a due a due producendo pezzi sempre più grandi e **già ordinati**. Tutta l'intelligenza sta nel merge: fondere due sequenze *ordinate* in una sequenza *ordinata* è facile e costa solo tempo lineare.

**Differenza filosofica con QuickSort**: QuickSort fa il lavoro *prima* delle ricorsioni (partition) e il merge è gratis (concatenazione); MergeSort divide gratis (taglio a metà) e fa il lavoro *dopo* le ricorsioni (merge).

## 2.2 Algoritmo (descrizione "da tema d'esame")

1. **Caso base**: se la sequenza ha 0 o 1 elementi è già ordinata.
2. **Dividi** la sequenza in due metà (indice centrale).
3. Richiama MergeSort su ciascuna metà.
4. **Merge (fondi)**: fondi le due metà ordinate confrontando i **primi elementi** di ciascuna e copiando ogni volta **il più piccolo** nel risultato; quando una metà si esaurisce, copia in blocco ciò che resta dell'altra.

> [!tip] 🧾 Codice del prof (C++) — utile per vedere la struttura ricorsiva
> ```cpp
> void MS(vector<int>& v, unsigned int inizio, unsigned int fine) {
>     if (inizio < fine) {
>         unsigned int centro = (inizio + fine) / 2;
>         MS(v, inizio, centro);        // ordina metà sinistra
>         MS(v, centro + 1, fine);      // ordina metà destra
>         fondi(v, inizio, centro, fine); // fonde le due metà ordinate
>     }
> }
> void mergesort(vector<int>& v) {
>     if (v.size() != 0) MS(v, 0, v.size() - 1);
> }
> ```
> Nota il caso base **implicito**: se `inizio ≥ fine` (0 o 1 elementi) la funzione non fa nulla.

### Come funziona `fondi` nel dettaglio (spesso chiesto!)
Due "dita" (indici), una per metà, partono dall'inizio di ciascuna:
1. Confronta i due elementi puntati; **copia il minore** nell'array di appoggio e avanza quel dito.
2. Ripeti finché una delle due metà finisce.
3. **Copia in coda** tutti gli elementi rimasti dell'altra metà (sono già ordinati e tutti ≥ dell'ultimo copiato).
4. Ricopia l'array d'appoggio nella porzione originale.

Costo: ogni elemento viene copiato **una volta sola** → $\Theta(k)$ per fondere $k$ elementi totali. Serve però un **array d'appoggio** → MergeSort **non è in place** (memoria extra $\Theta(n)$).

## 2.3 Complessità — $\Theta(n\log n)$ SEMPRE

| Caso | Complessità | Note |
|---|---|---|
| **Migliore** (già ordinato) | $\Theta(n\log n)$ | fa comunque tutte le divisioni e i merge |
| **Medio** (ordine casuale) | $\Theta(n\log n)$ | |
| **Peggiore** (ordine inverso) | $\Theta(n\log n)$ | |

### Il calcolo, per esteso (da scrivere all'esame)
MergeSort **non è adattivo**: non controlla mai se i dati sono già ordinati, quindi esegue *sempre* tutte le divisioni e tutti i merge. La ricorrenza è
$$T(n) = 2\,T(n/2) + \Theta(n)$$
($\Theta(n)$ è il costo del merge). L'albero delle chiamate:
- livello 0: 1 merge da $n$ elementi → lavoro $\Theta(n)$
- livello 1: 2 merge da $n/2$ → lavoro $2\cdot\Theta(n/2)=\Theta(n)$
- livello $J$: $2^J$ merge da $n/2^J$ → lavoro $2^J\cdot\Theta(n/2^J)=\Theta(n)$
- i livelli sono $\log_2 n$ (dimezzo fino a 1).

**Ogni livello costa $\Theta(n)$, i livelli sono $\log n$ → totale $\Theta(n\log n)$.** E siccome la struttura dell'albero non dipende dai *valori* ma solo dalla *lunghezza*, il costo è identico in ogni caso.

## 2.4 Simulazione completa su `12 7 1 2 3 4 9 6 8 10`

**Fase di divisione** (indici come nel codice: `centro=(inizio+fine)/2`):
```
[12,7,1,2,3,4,9,6,8,10]
├── [12,7,1,2,3]                ├── [4,9,6,8,10]
│   ├── [12,7,1]                │   ├── [4,9,6]
│   │   ├── [12,7] → [12],[7]   │   │   ├── [4,9] → [4],[9]
│   │   └── [1]                 │   │   └── [6]
│   └── [2,3] → [2],[3]         │   └── [8,10] → [8],[10]
```

**Fase di merge** (risalgo fondendo):
```
merge [12]+[7]           = [7,12]
merge [7,12]+[1]         = [1,7,12]
merge [2]+[3]            = [2,3]
merge [1,7,12]+[2,3]     = [1,2,3,7,12]      ← metà sinistra ordinata
merge [4]+[9]            = [4,9]
merge [4,9]+[6]          = [4,6,9]
merge [8]+[10]           = [8,10]
merge [4,6,9]+[8,10]     = [4,6,8,9,10]      ← metà destra ordinata
merge [1,2,3,7,12]+[4,6,8,9,10] = [1,2,3,4,6,7,8,9,10,12]  ✓
```

**Il merge finale passo-passo** (per far vedere che sai come funziona `fondi`):
```
A=[1,2,3,7,12]  B=[4,6,8,9,10]  → confronto le teste, prendo la minore
1<4  → 1     | 2<4 → 2     | 3<4 → 3     | 7>4 → 4     | 7>6 → 6
7<8  → 7     | 12>8 → 8    | 12>9 → 9    | 12>10 → 10  | A rimasta: → 12
risultato: [1,2,3,4,6,7,8,9,10,12]
```

> Se l'esame chiede "questo input è caso migliore, peggiore o medio?": **è irrilevante** — MergeSort fa lo stesso identico numero di divisioni e merge in ogni caso: $\Theta(n\log n)$.

## 2.5 Proprietà da citare se richieste

- **Stabile**: sì — nel merge, a **parità** di valore si prende prima l'elemento della metà **sinistra**, preservando l'ordine originale.
- **In place**: no — il merge usa un array d'appoggio di dimensione $\Theta(n)$.
- **Adattivo**: no — non guarda mai i dati, lavoro identico su input ordinato e disordinato.

## 2.6 Confronto QuickSort vs MergeSort (domanda frequente)

| | QuickSort | MergeSort |
|---|---|---|
| Strategia | lavoro **prima** (partition), divisione per **valore** | lavoro **dopo** (merge), divisione per **posizione** (metà) |
| Peggiore | $\Theta(n^2)$ (pivot sfortunato) | $\Theta(n\log n)$ sempre |
| Medio | $\Theta(n\log n)$ | $\Theta(n\log n)$ |
| In place | ✅ sì | ❌ no ($\Theta(n)$ extra) |
| Stabile | ❌ in generale no | ✅ sì |
| Quando preferirlo | in pratica: veloce, senza memoria extra | garanzie sul caso peggiore, stabilità |

## 2.7 🧯 Errori tipici all'esame

> [!danger] Da evitare
> 1. Dividere le metà "per valore" come in QuickSort: MergeSort divide **per posizione** (indice centrale), i valori non contano nella fase di divisione.
> 2. Nel merge, fondere pezzi che **non sono fratelli** nell'albero di ricorsione (segui sempre la struttura della divisione: si fondono le due metà della stessa chiamata).
> 3. Dire che il caso migliore è $\Theta(n)$ "perché è già ordinato": **falso**, MergeSort non è adattivo.
> 4. Dimenticare la giustificazione dei $\log n$ livelli × $\Theta(n)$ per livello quando la domanda chiede COME si calcola.
> 5. Dire che è in place: il merge **richiede memoria d'appoggio** $\Theta(n)$.

## 2.8 🎤 Domande tipiche + risposte modello

**"Qual è la complessità di mergesort e perché è la stessa in ogni caso?"**
> $\Theta(n\log n)$ in ogni caso, perché l'algoritmo non è adattivo: divide sempre a metà fino ai singoli elementi ($\log_2 n$ livelli di ricorsione) e a ogni livello il lavoro complessivo di merge è $\Theta(n)$ ($2^J$ merge su sequenze di $n/2^J$ elementi). Il numero di operazioni dipende solo dalla lunghezza $n$, non dall'ordine iniziale dei dati: quindi $\log n \cdot \Theta(n) = \Theta(n\log n)$ sempre.

**"Descrivi la fase di fusione (merge) e la sua complessità."**
> Ho due sequenze già ordinate: confronto i primi elementi delle due e copio il minore nella sequenza risultato, avanzando nella sequenza da cui ho prelevato; quando una si esaurisce, accodo ciò che resta dell'altra. Ogni elemento viene esaminato e copiato una sola volta, quindi fondere $k$ elementi complessivi costa $\Theta(k)$.

---

# 3 · HEAP BINARI

## 3.1 L'idea

> [!note] 💬 In parole povere
> Un **heap binario** serve quando ti interessa avere sempre, a portata di mano immediata, **il minimo** (min-heap) o **il massimo** (max-heap) di un insieme che cambia nel tempo — è la struttura ideale per una **coda con priorità**. È un **albero binario quasi completo** memorizzato in un **array**, in cui vale la **proprietà di heap**:
> - **Min-heap**: ogni nodo è **≤** dei suoi figli → il **minimo è la radice**.
> - **Max-heap**: ogni nodo è **≥** dei suoi figli → il **massimo è la radice**.
>
> ⚠️ La proprietà è solo **verticale** (padre-figli). Tra fratelli, o tra sottoalberi diversi, **non c'è nessun ordine**: non confonderlo con un BST!

### "Quasi completo" significa
Tutti i livelli sono pieni, **tranne al più l'ultimo**, riempito **da sinistra** senza buchi. Conseguenze fondamentali:
1. L'**altezza è sempre** $\Theta(\log n)$ — l'albero non può mai degenerare (a differenza del BST).
2. Si può memorizzare in un **array senza puntatori**: la posizione codifica la struttura.

## 3.2 L'heap nell'array: le formule (alberi indicizzati)

> [!tip] Formule del prof — posizioni contate **da 1**
> Formula generale per un albero di arità $d$: il **$j$-esimo figlio** del nodo in posizione $i$ sta in $d\cdot(i-1)+j+1$.
> Per un albero **binario** ($d=2$):
> - **figlio sinistro** del nodo $i$ → posizione $2i$
> - **figlio destro** del nodo $i$ → posizione $2i+1$
> - **padre** del nodo $i$ → posizione $\lfloor(i-2)/2\rfloor+1$ (equivalente a $\lfloor i/2 \rfloor$), definito per $i\neq 1$
>
> *(Se l'array parte da 0: figli in $2i+1$ e $2i+2$, padre in $\lfloor(i-1)/2\rfloor$. All'esame usa la convenzione **da 1**, quella vista a lezione, e dichiarala.)*

**Esempio**: array `[1, 3, 4, 9, 8, 5, 7]` (min-heap):
```
pos:   1  2  3  4  5  6  7
val:   1  3  4  9  8  5  7

            1           ← pos 1
          /   \
        3       4       ← pos 2, 3
       / \     / \
      9   8   5   7     ← pos 4, 5, 6, 7
```
Figli di pos 2 (val 3): pos 4 e 5 (9 e 8). Padre di pos 6 (val 5): pos 3 (val 4). ✓

## 3.3 Inserimento (insert) — "in fondo e risali"

1. Metti il nuovo elemento **in fondo all'array** (= prima posizione libera dell'ultimo livello, così l'albero resta quasi completo).
2. **Risali (sift-up)**: confrontalo col **padre**. Se viola la proprietà (in min-heap: è **più piccolo** del padre), **scambiali**. Ripeti dalla nuova posizione, finché il padre è ≤ (min-heap) oppure sei arrivato in radice.

Perché è corretto: l'unico punto in cui la proprietà può essere violata è lungo il cammino nuovo-nodo→radice, e lo scambio la ripara localmente spostando la violazione verso l'alto finché sparisce.

## 3.4 Cancellazione (deleteMin / deleteMax) — "ultimo in cima e scendi"

1. **Salva** l'elemento in radice (è il min/max da restituire).
2. Sposta **l'ultimo elemento dell'array** in radice e accorcia l'array di 1 (la forma resta quasi completa).
3. **Scendi (sift-down)**: confronta il nodo coi **figli**. In min-heap: se almeno un figlio è più piccolo, **scambia col più piccolo dei due** (⚠️ non con uno qualsiasi!). Ripeti finché entrambi i figli sono ≥ o arrivi a una foglia.
4. **Restituisci** l'elemento salvato al passo 1.

> [!warning] Perché "il più piccolo dei due figli"?
> Se scambiassi col figlio più grande, quello diventerebbe padre dell'altro figlio pur essendo maggiore → proprietà ancora violata. Scambiando col minore, il nuovo padre è ≤ di entrambi. **Questo è l'errore più frequente nelle simulazioni.**

## 3.5 Complessità

| Operazione | Migliore | Peggiore | Perché |
|---|---|---|---|
| **findMin/Max** (leggere la radice) | $\Theta(1)$ | $\Theta(1)$ | è in posizione 1 |
| **insert** | $\Theta(1)$ | $\Theta(\log n)$ | migliore: il nuovo elemento è già ≥ del padre, nessuna risalita; peggiore: risale **tutta l'altezza** fino alla radice |
| **deleteMin/Max** | $\Theta(1)$ | $\Theta(\log n)$ | migliore: l'elemento portato in radice è già a posto; peggiore: scende fino a una foglia |

**COME si calcola il $\log n$**: sift-up e sift-down percorrono al massimo un cammino radice↔foglia, lungo quanto l'**altezza**. L'heap è quasi completo, quindi l'altezza è $\lfloor\log_2 n\rfloor = \Theta(\log n)$ — **sempre**, perché la forma quasi completa è garantita dal modo in cui inseriamo (in fondo) e cancelliamo (ultimo in cima).

## 3.6 Simulazione completa — costruzione di un MIN-heap inserendo `5 9 3 8 1 4 7`

```
insert 5 → [5]                          (radice)
insert 9 → [5,9]                        9 ≥ 5: resta
insert 3 → [5,9,3] → 3 < 5? sì, swap →  [3,9,5]
insert 8 → [3,9,5,8]  padre di pos4 = pos2 (9): 8<9 swap → [3,8,5,9]
insert 1 → [3,8,5,9,1] padre di pos5 = pos2 (8): 1<8 swap → [3,1,5,9,8]
                       padre di pos2 = pos1 (3): 1<3 swap → [1,3,5,9,8]
insert 4 → [1,3,5,9,8,4] padre di pos6 = pos3 (5): 4<5 swap → [1,3,4,9,8,5]
insert 7 → [1,3,4,9,8,5,7] padre di pos7 = pos3 (4): 7≥4, resta
```
Heap finale: `[1, 3, 4, 9, 8, 5, 7]`
```
            1
          /   \
        3       4
       / \     / \
      9   8   5   7
```

**deleteMin sullo stesso heap:**
```
1. salvo 1 (la radice)
2. ultimo elemento (7) in radice → [7,3,4,9,8,5]
3. sift-down di 7: figli = 3 (pos2) e 4 (pos3); il minore è 3 < 7 → swap
   → [3,7,4,9,8,5]
   ora 7 in pos2: figli = 9 (pos4) e 8 (pos5); entrambi ≥ 7 → stop
4. restituisco 1
```
Heap finale: `[3, 7, 4, 9, 8, 5]`
```
            3
          /   \
        7       4
       / \     /
      9   8   5
```

## 3.7 Heap vs BST (confronto lampo, chiesto a voce e nei distrattori)

| | Heap | BST |
|---|---|---|
| Proprietà | verticale: padre ≤/≥ figli | sinistra < nodo < destra |
| Forma | **sempre** quasi completo | qualsiasi (può degenerare) |
| Trova min | $\Theta(1)$ (radice) | $\Theta(h)$ (tutto a sinistra) |
| Ricerca di una chiave qualsiasi | $\Theta(n)$ (nessun ordine orizzontale!) | $\Theta(h)$ |
| Visita in-order ordinata? | ❌ no | ✅ sì |

## 3.8 🧯 Errori tipici all'esame

> [!danger] Da evitare
> 1. Nel sift-down, scambiare con un figlio qualsiasi invece che col **più piccolo** (min-heap) / **più grande** (max-heap).
> 2. Inserire il nuovo elemento in radice o "al posto giusto": si inserisce **sempre in fondo** e poi si risale.
> 3. Nel deleteMin, "promuovere" il figlio minore a catena invece di spostare **l'ultimo elemento** in radice: romperesti la forma quasi completa.
> 4. Sbagliare le formule dell'array (ricontrolla: da 1 → figli $2i$, $2i+1$).
> 5. Dire che la ricerca di una chiave generica in heap costa $\Theta(\log n)$: **falso**, costa $\Theta(n)$ — l'heap ordina solo padre-figli.
> 6. Dimenticare di **restituire** il minimo salvato (nelle risposte descrittive va detto).

## 3.9 🎤 Domande tipiche + risposte modello

**"Descrivi deleteMin su un min-heap e la sua complessità nel caso peggiore."**
> Salvo la radice (il minimo). Sposto l'ultimo elemento dell'array in radice, accorciando l'array: così l'albero resta quasi completo. Poi faccio scendere il nuovo elemento in radice (sift-down): a ogni passo lo confronto coi figli e, se almeno uno è minore, lo scambio con il **più piccolo** dei due; mi fermo quando entrambi i figli sono maggiori o uguali o raggiungo una foglia. Restituisco il minimo salvato. Nel caso peggiore l'elemento scende dalla radice fino a una foglia, percorrendo l'intera altezza dell'albero, che in un albero quasi completo è $\Theta(\log n)$.

**"Perché un heap si può memorizzare in un array senza puntatori?"**
> Perché è quasi completo: i nodi si susseguono livello per livello, da sinistra, senza buchi. Numerando le posizioni da 1, i figli del nodo $i$ stanno in $2i$ e $2i+1$ e il padre in $\lfloor i/2\rfloor$: la posizione nell'array codifica completamente la struttura dell'albero.

**"Quando insert costa $\Theta(1)$ e quando $\Theta(\log n)$?"**
> $\Theta(1)$ nel caso migliore: l'elemento inserito in fondo è già maggiore o uguale al padre (min-heap) e non risale. $\Theta(\log n)$ nel caso peggiore: l'elemento è più piccolo di tutti (nuovo minimo) e risale l'intera altezza fino alla radice, con un confronto e uno scambio per livello.

---

# 4 · BINARY SEARCH TREE (BST)

## 4.1 L'idea

> [!note] 💬 In parole povere
> Un **albero binario di ricerca** organizza le chiavi in modo da poter cercare "alla ricerca binaria" ma su una struttura **dinamica** (che cresce e si restringe con insert/delete). La proprietà, valida **per ogni nodo**:
> **tutto il sottoalbero sinistro contiene chiavi minori del nodo; tutto il destro chiavi maggiori.**
>
> ⚠️ "Tutto il sottoalbero", non solo il figlio: un nodo nel sottoalbero sinistro di 50 deve essere < 50 anche se è figlio destro di qualcun altro.

> [!tip] Proprietà magica (chiesta spesso)
> La visita **in-order** (simmetrica: sinistra → nodo → destra) di un BST produce le chiavi **in ordine crescente**. È anche un test rapido: se la in-order non è ordinata, l'albero NON è un BST.

### Le tre visite (ripasso lampo)
- **pre-order**: nodo → sinistra → destra (utile per copiare l'albero)
- **in-order**: sinistra → nodo → destra (**ordinata** su BST)
- **post-order**: sinistra → destra → nodo (utile per cancellare l'albero)

## 4.2 Ricerca (search)

1. Parti dalla radice; confronta la chiave cercata $k$ col nodo corrente.
2. Se $k$ = nodo → trovato. Se $k$ < nodo → scendi a **sinistra**; se $k$ > nodo → scendi a **destra**.
3. Se arrivi a un puntatore nullo → la chiave **non c'è**.

A ogni confronto **scarti un intero sottoalbero**: è la versione ad albero della ricerca binaria.

## 4.3 Inserimento (insertElem)

1. Cerca la chiave come sopra, scendendo sinistra/destra.
2. Quando trovi il posto vuoto (figlio mancante), **aggancia lì il nuovo nodo come foglia**.
3. (Se la chiave esiste già: nessun duplicato — la convenzione del corso è chiavi distinte.)

**Il nuovo nodo diventa sempre una foglia**: l'inserimento non ristruttura mai l'albero. Per questo l'ordine di inserimento determina la forma (e può sbilanciarlo!).

## 4.4 Cancellazione (deleteElem) — i 3 casi (LA domanda più frequente)

Prima **cerca** il nodo. Poi, a seconda di quanti figli ha:

**Caso 1 — foglia (0 figli)**: staccalo e basta (il padre punta a nullo).

**Caso 2 — un solo figlio**: "bypass": il padre del nodo cancellato punta **direttamente al figlio**. Il sottoalbero del figlio sale in blocco di un livello.

**Caso 3 — due figli**: non puoi staccarlo (lasceresti due sottoalberi orfani). Allora:
1. Trova il **successore** = **minimo del sottoalbero destro** (scendi nel figlio destro e poi sempre a sinistra) — *oppure* il **predecessore** = massimo del sottoalbero sinistro (figlio sinistro, poi sempre a destra).
2. **Copia** la sua chiave nel nodo da cancellare.
3. **Elimina** il successore/predecessore dalla sua posizione originaria con la funzione ausiliaria `deleteMin`/`deleteMax` del sottoalbero: è facile, perché **il minimo di un sottoalbero non ha mai figlio sinistro** (al più uno destro → caso 1 o 2).

> [!tip] Perché proprio il successore?
> Serve un valore che possa stare al posto del cancellato rispettando "sinistra < nodo < destra". Il **minimo del sottoalbero destro** è: maggiore di tutto il sottoalbero sinistro (sta a destra) e minore di tutto il resto del sottoalbero destro (è il minimo). È l'unico candidato "naturale" insieme al predecessore, simmetrico.

## 4.5 Complessità — tutto dipende dall'altezza $h$

Ogni operazione (search/insert/delete) percorre **un cammino radice→nodo**, quindi costa $\Theta(h)$.

| Forma dell'albero | Altezza $h$ | search/insert/delete |
|---|---|---|
| **Bilanciato** (caso migliore/medio) | $\Theta(\log n)$ | $\Theta(\log n)$ |
| **Degenerato a lista** (caso peggiore) | $\Theta(n)$ | $\Theta(n)$ |

> [!warning] QUANDO si ricade nel caso peggiore $\Theta(n)$ (dillo sempre!)
> Quando l'albero è **completamente sbilanciato**: ogni nodo ha un solo figlio e la struttura **degenera in una lista**. Succede tipicamente inserendo le chiavi **già ordinate**: $10, 20, 30, 40, \dots$ → ognuna finisce come figlio destro della precedente → catena lunga $n$. COME si calcola: il cammino radice→foglia tocca tutti gli $n$ nodi → $\Theta(n)$.
>
> A differenza dell'heap (che è quasi completo **per costruzione**), il BST **non ha nessuna garanzia di forma**.

## 4.6 Simulazione completa — inserisco `50 30 70 20 40 60 80 65`

```
50                    → radice
30 < 50               → figlio sinistro di 50
70 > 50               → figlio destro di 50
20 < 50, < 30         → figlio sinistro di 30
40 < 50, > 30         → figlio destro di 30
60 > 50, < 70         → figlio sinistro di 70
80 > 50, > 70         → figlio destro di 70
65 > 50, < 70, > 60   → figlio destro di 60
```
```
            50
          /    \
        30      70
       /  \    /  \
     20   40  60   80
               \
               65
```
**Verifica**: in-order = `20 30 40 50 60 65 70 80` → crescente ✓

## 4.7 Simulazione dei 3 casi di delete (sull'albero qui sopra, ciascuno partendo dall'originale)

**Caso 1 — delete 20 (foglia)**: stacco 20; il figlio sinistro di 30 diventa nullo. Fine.

**Caso 2 — delete 60 (un figlio: 65)**: il padre di 60 è 70 → 70 aggancia direttamente 65 come figlio sinistro.
```
        70                 70
       /  \      →        /  \
      60   80            65   80
       \
       65
```

**Caso 3 — delete 70 (due figli)**: successore = minimo del sottoalbero destro di 70 = **80** (80 non ha figlio sinistro). Copio 80 al posto di 70, poi elimino il vecchio nodo 80 (era foglia → caso 1).
```
            50
          /    \
        30      80
       /  \    /
     20   40  60
               \
               65
```
*(Alternativa col predecessore: massimo del sottoalbero sinistro di 70 = **65** → copio 65 al posto di 70 ed elimino il vecchio 65.)*

**Caso 3 sulla radice — delete 50**: successore = minimo del sottoalbero destro = parto da 70, scendo a sinistra: 60, che non ha figlio sinistro → successore = **60**. Copio 60 in radice; elimino il vecchio 60, che ha un figlio (65) → caso 2: 70 aggancia 65 a sinistra.
```
            60
          /    \
        30      70
       /  \    /  \
     20   40  65   80
```
In-order: `20 30 40 60 65 70 80` → ancora ordinata ✓

## 4.8 🧯 Errori tipici all'esame

> [!danger] Da evitare
> 1. Verificare la proprietà solo sui **figli diretti** invece che su **tutto il sottoalbero** (classico albero-trabocchetto nei compiti).
> 2. Nel caso 3, prendere il "minimo di tutto l'albero" o il "figlio destro" invece del **minimo del sottoalbero destro**.
> 3. Dimenticare che dopo aver copiato il successore va **eliminato dalla posizione originaria** (altrimenti hai la chiave duplicata).
> 4. Dire che il delete nel caso peggiore è $\Theta(\log n)$ "perché l'albero è binario": la garanzia $\log n$ vale **solo se bilanciato**; il peggiore è $\Theta(n)$.
> 5. Nella simulazione di insert, ristrutturare l'albero: l'insert **aggiunge sempre una foglia**, non sposta nulla.
> 6. Confondere BST e heap (ordine orizzontale vs verticale).

## 4.9 🎤 Domande tipiche + risposte modello

**"Descrivi deleteElem su BST e la complessità nel caso peggiore."**
> Cerco il nodo scendendo a sinistra o destra secondo il confronto con la chiave. Tre casi: se è una foglia lo stacco; se ha un solo figlio, collego il padre direttamente al figlio; se ha due figli, lo sostituisco con il successore — il minimo del sottoalbero destro, trovato scendendo a destra e poi sempre a sinistra — copiandone la chiave nel nodo e rimuovendo il successore dalla sua posizione con deleteMin (il minimo non ha figlio sinistro, quindi la sua rimozione ricade nei casi 1 o 2). In alternativa, simmetricamente, il predecessore = massimo del sottoalbero sinistro. Ogni fase percorre un cammino radice→foglia, quindi il costo è $\Theta(h)$: nel caso peggiore l'albero è degenerato a lista (es. chiavi inserite in ordine) e $h = n$, quindi $\Theta(n)$.

**"Perché la ricerca in un BST bilanciato costa $\Theta(\log n)$?"**
> A ogni confronto scarto un intero sottoalbero e scendo di un livello: i passi sono al più l'altezza. In un albero bilanciato i nodi raddoppiano a ogni livello, quindi con $n$ nodi l'altezza è $\Theta(\log n)$.

---

# 5 · TABELLE DI HASH

## 5.1 L'idea

> [!note] 💬 In parole povere
> Una tabella di hash implementa un **dizionario** (coppie chiave→valore) puntando al tempo **costante**: invece di *cercare* la chiave confrontandola con altre, la **trasformi in un indice** con una **funzione di hash** $h(\text{chiave}) \in \{0,\dots,m-1\}$ e vai **direttamente** alla cella (**bucket**) di un array di $m$ posizioni. Niente scansioni, niente confronti: un calcolo aritmetico e un salto.
>
> Il prezzo: due chiavi diverse possono finire nella stessa cella → **collisione**. Soluzione del corso (**concatenamento/chaining**): ogni cella contiene una **lista di collisione** con tutte le coppie finite lì.

## 5.2 Le operazioni

- **insert(k, v)**: calcola $h(k)$ → vai al bucket. Se vuoto, crea la lista con la coppia; altrimenti **scorri la lista** per verificare che $k$ non sia duplicata e aggiungi in coda.
- **search(k)**: calcola $h(k)$ → scorri la lista di quel bucket confrontando le chiavi.
- **delete(k)**: come search, poi rimuovi il nodo dalla lista.

Costo = **calcolo di $h$** (che vogliamo $\Theta(1)$) **+ scansione della lista** del bucket → tutto dipende da **quanto sono lunghe le liste**, cioè da quanto è "brava" la funzione di hash.

## 5.3 Le 2 "buone proprietà" di una funzione di hash (le chiedono SEMPRE)

1. **Calcolabile in tempo costante** $\Theta(1)$: solo operazioni aritmetiche semplici (somma, prodotto, modulo), indipendenti da $n$.
2. **Uniforme**: distribuisce le chiavi **equamente** tra gli $m$ bucket (100 chiavi su 10 celle → ~10 per cella), così nessuna lista diventa lunga.

> [!important] Funzione di hash **perfetta**
> È perfetta quando **non genera collisioni**: dev'essere **iniettiva** (chiavi diverse → celle diverse) e calcolabile in tempo costante. Con hash perfetta ogni bucket ha al più 1 elemento → tutte le operazioni sono $\Theta(1)$. In pratica è possibile solo se conosci in anticipo l'insieme delle chiavi.

## 5.4 Complessità di insert/search/delete (con il QUANDO)

Sia $n$ = numero di elementi, $m$ = numero di bucket. Il rapporto $n/m$ si chiama **fattore di carico**.

| Situazione | Complessità | Perché |
|---|---|---|
| Hash **iniettiva** / nessuna collisione | $\Theta(1)$ | calcolo $h$ in $\Theta(1)$, bucket con ≤1 elemento |
| Hash **uniforme** | $\Theta(n/m)$ | ogni lista ha in media $n/m$ elementi da scorrere |
| Hash **pessima** (tutte le chiavi in un bucket) | $\Theta(n)$ | un'unica lista con tutti gli elementi: degenera in una **lista concatenata** |

**Come si calcola**: costo = $\Theta(1)$ (hash) + lunghezza della lista scandita. La lunghezza è ~0/1 nel primo caso, ~$n/m$ nel secondo, $n$ nel terzo.

> Nota: se $m$ è proporzionale a $n$ (es. $m \approx n$), allora $n/m = \Theta(1)$: ecco perché si dice che con una buona hash il dizionario lavora "in tempo costante in media".

## 5.5 Simulazione completa — esame 2026: $h = (a\cdot b + c\cdot d)\bmod 7$

Chiavi a 4 cifre `a b c d`, tabella con 7 bucket (0–6):

| chiave | valore | $a\cdot b + c\cdot d$ | $\bmod\ 7$ |
|---|---|---|---|
| 3 7 5 1 | "ma" | $21+5=26$ | **5** |
| 3 4 4 7 | "co" | $12+28=40$ | **5** |
| 2 2 7 1 | "gra" | $4+7=11$ | **4** |
| 1 9 7 2 | "pe" | $9+14=23$ | **2** |
| 6 8 6 2 | "le" | $48+12=60$ | **4** |
| 7 2 0 1 | "re" | $14+0=14$ | **0** |
| 3 7 1 3 | "ca" | $21+3=24$ | **3** |
| 9 7 8 7 | "giu" | $63+56=119$ | **0** |

Tabella risultante (inserimenti in ordine, aggiunta in coda alla lista):
```
[0] → re → giu
[1] → (vuoto)
[2] → pe
[3] → ca
[4] → gra → le
[5] → ma → co
[6] → (vuoto)
```
Collisioni: (ma, co) sul bucket 5, (gra, le) sul 4, (re, giu) sullo 0 → la funzione **non è perfetta** (non iniettiva su queste chiavi).

**search("le")**: $h=60\bmod 7=4$ → bucket 4 → scorro: gra (no) → le ✓ (2 confronti).
**delete("ma")**: $h=26\bmod 7=5$ → bucket 5 → primo della lista → lo rimuovo, la lista diventa `co`.

> [!danger] ⚠️ Errore da NON fare col modulo
> $\bmod\ 7$ dà **sempre** un risultato tra **0 e 6**: se ti esce "7" hai sbagliato ($119 = 17\cdot 7 + 0$ → bucket **0**, non 7!). Consiglio pratico: dividi, prendi il resto, e **verifica** che sia $< m$.

## 5.6 Seconda simulazione (per allenarsi) — $h(k)=k \bmod 11$

Inserisco le chiavi `15, 23, 7, 42, 30, 19, 36` in una tabella con 11 bucket:

| $k$ | calcolo | $h(k)$ |
|---|---|---|
| 15 | $15 = 1\cdot 11 + 4$ | 4 |
| 23 | $23 = 2\cdot 11 + 1$ | 1 |
| 7 | $7 = 0\cdot 11 + 7$ | 7 |
| 42 | $42 = 3\cdot 11 + 9$ | 9 |
| 30 | $30 = 2\cdot 11 + 8$ | 8 |
| 19 | $19 = 1\cdot 11 + 8$ | **8** ← collisione con 30 |
| 36 | $36 = 3\cdot 11 + 3$ | 3 |

```
[0] ∅   [1] 23   [2] ∅   [3] 36   [4] 15   [5] ∅
[6] ∅   [7] 7    [8] 30 → 19     [9] 42   [10] ∅
```

## 5.7 🧯 Errori tipici all'esame

> [!danger] Da evitare
> 1. Sbagliare i conti del **modulo** (risultato sempre in $\{0,\dots,m-1\}$).
> 2. Dire che le collisioni "non devono succedere": con più chiavi che bucket sono **inevitabili** (principio dei cassetti); l'importante è gestirle (liste) e che siano distribuite (uniformità).
> 3. Confondere **uniforme** e **iniettiva/perfetta**: uniforme = liste corte e simili tra loro ($\Theta(n/m)$); perfetta = **nessuna** collisione ($\Theta(1)$).
> 4. Dimenticare una delle due buone proprietà (costante + uniforme) — le chiedono in coppia.
> 5. Rispondere solo "$\Theta(1)$" alla domanda sulla complessità: va **sempre** distinta per i tre scenari con il loro QUANDO.
> 6. Nel disegno della tabella, dimenticare i bucket **vuoti**: vanno mostrati anche loro.

## 5.8 🎤 Domande tipiche + risposte modello

**"Sotto quali condizioni insert/delete ha complessità $\Theta(1)$, $\Theta(n/m)$, $\Theta(n)$?"**
> Il costo è: calcolo della funzione di hash ($\Theta(1)$ se ben fatta) più la scansione della lista del bucket. È $\Theta(1)$ quando la funzione è iniettiva (nessuna collisione, ogni bucket ha al più un elemento). È $\Theta(n/m)$ quando la funzione è uniforme: gli $n$ elementi si distribuiscono equamente sugli $m$ bucket e ogni lista è lunga circa $n/m$. È $\Theta(n)$ quando la funzione concentra tutte le chiavi in un unico bucket: la tabella degenera in un'unica lista con tutti gli $n$ elementi.

**"Quali sono le buone proprietà di una funzione di hash? Quando è perfetta?"**
> Deve essere calcolabile in tempo costante (solo operazioni aritmetiche semplici) e uniforme (distribuisce le chiavi equamente tra i bucket). È perfetta quando non genera collisioni, cioè è iniettiva sull'insieme delle chiavi, oltre che calcolabile in tempo costante: in tal caso tutte le operazioni costano $\Theta(1)$.

---

# 6 · GRAFI — visite BFS e DFS

## 6.1 Le definizioni base (servono per capire le domande)

> [!note] 💬 In parole povere
> Un **grafo** $G=(V,E)$ è un insieme di **vertici (nodi)** $V$ collegati da **archi** $E$. Modella qualsiasi rete: strade, amicizie, link tra pagine.
> - **Non diretto**: gli archi non hanno verso (A–B = B–A). **Diretto**: hanno verso (A→B ≠ B→A).
> - **Adiacenti**: due vertici collegati da un arco. I vicini di un nodo.
> - **Grado** di un vertice: quanti archi lo toccano.
> - **Cammino**: sequenza di vertici collegati da archi. **Ciclo**: cammino che torna al punto di partenza.
> - **Connesso**: esiste un cammino tra ogni coppia di vertici.
>
> "**Visitare** il grafo" = raggiungere sistematicamente **tutti i vertici raggiungibili** da un vertice di partenza, senza passare due volte dallo stesso (→ si **marcano** i vertici visitati: nei grafi ci sono i **cicli**, senza marcatura girerei all'infinito!).

## 6.2 Come si rappresenta un grafo

> [!note] 🗂️ Liste di adiacenza (il modo standard del corso)
> Per ogni vertice si tiene la **lista dei suoi vicini**.
> - **Pro**: memoria $\Theta(V+E)$; scorrere i vicini di un nodo è immediato.
> - **Contro**: con etichette "grandi" gli indici diventano grandi; ambiguità sui vertici di grado 0; verificare se esiste l'arco (u,v) richiede di scorrere la lista.
>
> *(Alternativa: **matrice di adiacenza** $V\times V$ con 1 in $(i,j)$ se c'è l'arco: test di adiacenza $\Theta(1)$ ma memoria $\Theta(V^2)$ — sprecata se il grafo ha pochi archi.)*

## 6.3 Le due visite: stessa logica, struttura dati diversa

Entrambe partono da un vertice sorgente, lo **marcano**, e usano una struttura per ricordare "chi devo ancora esplorare". **L'unica vera differenza è la struttura dati**, e da lì discende tutto il comportamento:

| Visita | Struttura dati | Come procede | Memo |
|---|---|---|---|
| **BFS** (Breadth-First Search, in ampiezza) | **CODA** (FIFO: primo entrato, primo uscito) | a **livelli**: prima tutti i vicini della sorgente, poi i vicini dei vicini… | "a cerchi concentrici" |
| **DFS** (Depth-First Search, in profondità) | **STACK** (LIFO) o **ricorsione** | va **fino in fondo** lungo un ramo, poi torna indietro (backtracking) e prova gli altri | "sprofonda e torna" |

> [!tip] Albero di ricoprimento (spanning tree)
> Durante la visita, ogni volta che da un vertice $v$ **scopro un vertice nuovo** $w$ (non marcato), l'arco $(v,w)$ entra nell'**albero di ricoprimento**. Gli archi verso vertici **già marcati** vengono ignorati (non entrano nell'albero → per questo l'albero **non ha cicli**). Alla fine: albero con tutti i vertici raggiungibili e (numero vertici − 1) archi.
> Cambiando **vertice di partenza** o **ordine dei vicini** si ottengono alberi di ricoprimento **diversi** — l'esame lo chiede spesso ("trova un albero diverso dal precedente").

## 6.4 Pseudocodice (da saper riscrivere)

> [!tip] 🧾 DFS ricorsiva (versione del prof)
> ```
> visitaDFS(vertice s) → Albero:
>     T ← albero vuoto
>     visitaDFSricorsiva(s, T)
>     return T
>
> visitaDFSricorsiva(vertice v, Albero T):
>     marca e visita il vertice v
>     for each (arco(v,w)) do
>         if (w non è marcato) then
>             aggiungi l'arco(v,w) all'albero T
>             visitaDFSricorsiva(w, T)
> ```

> [!tip] 🧾 BFS con coda
> ```
> visitaBFS(vertice s) → Albero:
>     T ← albero vuoto;  Q ← coda vuota
>     marca s;  enqueue(Q, s)
>     while (Q non vuota) do
>         v ← dequeue(Q)
>         visita v
>         for each (arco(v,w)) do
>             if (w non è marcato) then
>                 marca w
>                 aggiungi arco(v,w) a T
>                 enqueue(Q, w)
>     return T
> ```
> Differenza chiave: nella BFS marchi $w$ **quando lo scopri** (entra in coda), non quando lo visiti — così non entra in coda due volte.

## 6.5 Complessità: $O(V+E)$ per entrambe

**COME si calcola**: ogni **vertice** viene marcato e visitato **una sola volta** ($\Theta(V)$); per ogni vertice si scorre **una sola volta** la sua lista di adiacenza, e la somma delle lunghezze di tutte le liste è (2)$E$ ($\Theta(E)$). Totale $O(V+E)$. *(Con matrice di adiacenza diventerebbe $O(V^2)$: per ogni vertice scorri un'intera riga.)*

## 6.6 Simulazione completa

Grafo (non diretto) — archi: **A–B, A–C, B–D, C–D, C–E, D–F, E–F**. Vicini esaminati in **ordine alfabetico**.
```
      A
     / \
    B   C
    |  / \
    D–+   E
    |     |
    F ––– +
```
Liste di adiacenza: A: [B,C] · B: [A,D] · C: [A,D,E] · D: [B,C,F] · E: [C,F] · F: [D,E]

### BFS da A (con la coda in evidenza)

| Passo | Visito | Scopro (marco+accodo) | Coda dopo | Archi albero aggiunti |
|---|---|---|---|---|
| 1 | A | B, C | [B, C] | A–B, A–C |
| 2 | B | D | [C, D] | B–D |
| 3 | C | E (D già marcato) | [D, E] | C–E |
| 4 | D | F (B, C già marcati) | [E, F] | D–F |
| 5 | E | — (C, F già marcati) | [F] | — |
| 6 | F | — | [] | — |

**Ordine di visita**: `A → B → C → D → E → F` (per livelli: A | B,C | D,E | F)
**Albero di ricoprimento**: A–B, A–C, B–D, C–E, D–F

### DFS da A (ricorsione, sempre in ordine alfabetico)

```
visito A → primo vicino non marcato: B
  visito B → vicini: A (marcato), D
    visito D → vicini: B (marcato), C
      visito C → vicini: A, D (marcati), E
        visito E → vicini: C (marcato), F
          visito F → vicini: D, E (marcati) → vicolo cieco, torno indietro
        (E: finiti i vicini) ← backtracking
      (C: finiti) ← (D: resta F, ma è marcato) ← (B: finiti) ← (A: resta C, marcato)
```
**Ordine di visita**: `A → B → D → C → E → F`
**Albero di ricoprimento**: A–B, B–D, D–C, C–E, E–F

> [!warning] Differenza che fa la differenza
> Stesso grafo, stessa partenza, **alberi diversi**: la BFS produce un albero "largo e basso" (cammini minimi in numero di archi dalla sorgente!), la DFS uno "stretto e profondo". Se il compito chiede *"un albero di ricoprimento diverso"*: cambia il vertice di partenza **oppure** l'ordine dei vicini **oppure** il tipo di visita — e **motiva** la differenza.

## 6.7 🧯 Errori tipici all'esame

> [!danger] Da evitare
> 1. Dimenticare la **marcatura**: nei grafi ci sono cicli, senza marcatura la visita non termina. (Negli alberi non serviva, nei grafi è **essenziale** — dillo esplicitamente.)
> 2. Mettere nell'albero di ricoprimento archi verso nodi **già marcati** → creeresti un ciclo: un albero con ciclo non è un albero!
> 3. Confondere le strutture: BFS = **coda**, DFS = **stack/ricorsione**. (Trucco memo: **B**FS = **B**readth = per livelli = coda.)
> 4. Nella BFS, visitare i nodi in ordine di scoperta sbagliato: la coda è FIFO, si estrae **il primo entrato**.
> 5. Non rispettare l'ordine dei vicini dichiarato (se dici "alfabetico", seguilo per tutta la simulazione).
> 6. Scrivere $O(V\cdot E)$ come complessità: è $O(V+E)$ — ogni vertice e ogni arco una volta.

## 6.8 🎤 Domande tipiche + risposte modello

**"Illustra una visita DFS dal nodo X con creazione dell'albero di ricoprimento."**
> Parto da X e lo marco. Scelgo il primo vicino non marcato, aggiungo all'albero l'arco che lo raggiunge e proseguo ricorsivamente da lui, andando sempre più in profondità. Quando un vertice non ha più vicini non marcati, torno indietro (backtracking) al vertice precedente e provo i suoi altri vicini. Termino quando tutti i vertici raggiungibili sono marcati. Gli archi usati per scoprire vertici nuovi formano l'albero di ricoprimento; gli archi verso vertici già marcati si ignorano, quindi l'albero non contiene cicli. Complessità $O(V+E)$: ogni vertice è visitato una volta e ogni lista di adiacenza scorsa una volta.

**"Che differenza c'è tra BFS e DFS?"**
> Cambia la struttura dati che decide il prossimo vertice da esplorare: la BFS usa una coda FIFO e procede per livelli (prima tutti i vicini della sorgente, poi i vicini dei vicini), la DFS usa uno stack o la ricorsione e scende lungo un ramo fino in fondo prima di tornare indietro. Entrambe marcano i vertici per non rivisitarli, entrambe producono un albero di ricoprimento e costano $O(V+E)$; in generale producono alberi e ordini di visita diversi.

---

# 📊 Riepilogo complessità (da sapere a memoria)

| Struttura / Algoritmo | Migliore | Medio | Peggiore | QUANDO il peggiore |
|---|---|---|---|---|
| **MergeSort** | $\Theta(n\log n)$ | $\Theta(n\log n)$ | $\Theta(n\log n)$ | mai diverso (non adattivo) |
| **QuickSort** | $\Theta(n\log n)$ | $\Theta(n\log n)$ | $\Theta(n^2)$ | pivot sempre min/max (es. input già ordinato, pivot=primo) |
| **Heap** insert | $\Theta(1)$ | — | $\Theta(\log n)$ | risale fino alla radice (nuovo min/max) |
| **Heap** deleteMin/Max | $\Theta(1)$ | — | $\Theta(\log n)$ | scende fino a una foglia |
| **BST** insert/search/delete | $\Theta(\log n)$ | $\Theta(\log n)$ | $\Theta(n)$ | albero degenerato a lista (chiavi inserite in ordine) |
| **Hash** insert/search/delete | $\Theta(1)$ | $\Theta(n/m)$ | $\Theta(n)$ | tutte le chiavi in un bucket |
| **BFS / DFS** | — | — | $O(V+E)$ | ogni vertice e ogni arco una volta |

E i "come si calcola" in una riga ciascuno:
- **MergeSort**: $\log n$ livelli × $\Theta(n)$ di merge per livello.
- **QuickSort peggiore**: $n+(n-1)+\dots+1=\frac{n(n+1)}{2}$; migliore/medio: $\log n$ livelli × $\Theta(n)$ di partition.
- **Heap**: cammino lungo l'altezza = $\log n$ (albero quasi completo).
- **BST**: cammino radice→nodo = altezza $h$ ($\log n$ bilanciato, $n$ degenerato).
- **Hash**: $\Theta(1)$ di calcolo + lunghezza lista (0/1, $n/m$, oppure $n$).
- **BFS/DFS**: ogni vertice marcato una volta + ogni lista di adiacenza scorsa una volta.

> [!success] ✅ Checklist "so rispondere?"
> - [ ] So **descrivere a parole** ognuno dei 6 algoritmi (insert/delete/visita), nell'ordine giusto e senza saltare passi.
> - [ ] Per ogni complessità so dire **quanto + quando + come si calcola**.
> - [ ] So **simulare e disegnare** un'esecuzione (sort, heap, BST, hash, grafo) su dati mai visti.
> - [ ] So spiegare perché MergeSort è sempre $n\log n$ e QuickSort no.
> - [ ] So le 2 buone proprietà di una funzione di hash + definizione di perfetta.
> - [ ] So la differenza coda (BFS) / stack (DFS) e come nasce l'albero di ricoprimento.
> - [ ] So i 3 casi del delete su BST e perché si usa il successore.
> - [ ] So le definizioni di adattivo / in place / stabile con gli esempi giusti.

---

# 🧯 Errori tipici trasversali

> [!danger] Quelli che costano punti in QUALSIASI domanda
> 1. **Rispondere solo "quanto"**: la domanda sulla complessità è sempre tripla (quanto + quando + come). Una risposta "QuickSort è $O(n^2)$" da sola vale poco.
> 2. **Descrizione sbagliata → complessità non valutata**: è scritto nei testi d'esame. Prima cura la descrizione dell'algoritmo, poi la complessità.
> 3. **Simulazioni senza disegni**: heap, BST e grafi vanno **disegnati** passo per passo, non raccontati.
> 4. **Non dichiarare le convenzioni**: pivot = primo elemento, indici heap da 1, vicini in ordine alfabetico… dichiarale e rispettale fino in fondo.
> 5. **Fretta sui conti piccoli** (modulo, indici, confronti): sono la fonte n°1 di errori nelle simulazioni. Rifai i conti una volta.
> 6. Confondere $O$, $\Omega$, $\Theta$: usa $\Theta$ quando conosci esattamente il caso, $O$ per un limite superiore.

---

# 🗓️ Piano di ripasso (3 luglio → 14 luglio)

> [!tip] 11 giorni: un argomento al giorno + tanti esami vecchi
> - **3–4 lug**: QuickSort + MergeSort (studiali in coppia: stessa famiglia, comportamento opposto sul caso peggiore).
> - **5–6 lug**: Heap (formule dell'array + simulazioni insert/deleteMin su carta, tante).
> - **7 lug**: BST (i 3 casi di delete sono la parte più chiesta: simulane almeno 5).
> - **8 lug**: Tabelle di hash (calcolo funzione + disegno tabella + le complessità con i QUANDO).
> - **9 lug**: Grafi (BFS e DFS dallo stesso grafo, alberi di ricoprimento diversi).
> - **10–12 lug**: **esami vecchi** della cartella `teoria/esami vecchi`, a tempo, scrivendo le risposte per esteso come se fossi in aula.
> - **13 lug**: ripasso del riepilogo complessità + checklist + errori tipici; simulazioni lampo (una per argomento).
> - **14 lug**: 💪 esame — riguarda solo la tabella riassuntiva, non imparare cose nuove.

*Buono studio! Se vuoi, posso prepararti una versione "quiz" con domande a risposta aperta per autovalutarti, oppure correggere le tue risposte agli esami vecchi.*



