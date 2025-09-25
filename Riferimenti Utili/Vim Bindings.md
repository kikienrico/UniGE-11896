# Comandi Vim - Cheat Sheet

## 1. Navigazione base
| Comando | Azione |
|---|---|
| h | Muovi a sinistra |
| j | Muovi in basso |
| k | Muovi in alto |
| l | Muovi a destra |

## 2. Inizio / fine documento
| Comando | Azione |
|---|---|
| gg | Vai alla prima riga |
| G | Vai all’ultima riga |

## 3. Linea specifica
| Comando | Azione |
|---|---|
| :numero | Vai alla linea "numero" |

## 4. Inizio / fine riga
| Comando | Azione |
|---|---|
| 0 | Inizio riga |
| $ | Fine riga |

## 5. Movimenti tra parole e paragrafi
| Comando | Azione |
|---|---|
| w | Inizio parola successiva |
| b | Inizio parola precedente |
| ( | Inizio frase precedente |
| ) | Inizio frase successiva |
| { | Inizio paragrafo precedente |
| } | Inizio paragrafo successivo |

## 6. Scorrimento
| Comando | Azione |
|---|---|
| Ctrl + u | Mezza schermata su |
| Ctrl + d | Mezza schermata giù |
| Ctrl + b | Pagina intera su |
| Ctrl + f | Pagina intera giù |

## 7. Editing in Normal Mode
| Comando | Azione |
|---|---|
| x | Cancella carattere sotto cursore |
| dd | Cancella linea |
| yy | Copia (yank) linea |
| p | Incolla dopo cursore |
| u | Undo |
| Ctrl + r | Redo |

## 8. Ricerca e sostituzione
| Comando | Azione |
|---|---|
| / | Cerca avanti |
| ? | Cerca indietro |
| :s/old/new/g | Sostituisci tutte occorrenze "old" con "new" |

## 9. Modalità Insert
| Comando | Azione |
|---|---|
| i | Inserisci prima del cursore |
| a | Inserisci dopo il cursore |
| o | Nuova riga sotto e inserisci |
| Esc | Torna in Normal Mode |

## 10. Modalità Visual
| Comando | Azione |
|---|---|
| v | Selezione carattere |
| V | Selezione riga |
| Ctrl + v | Selezione blocco |
| d | Cancella selezione |
| y | Copia selezione |
| p | Incolla selezione |

## 11. Navigazione tra funzioni e codice
| Comando    | Azione                                        |
| ---------- | --------------------------------------------- |
| ]]         | Inizio funzione successiva                    |
| [[         | Inizio funzione precedente                    |
| >>         | Indenta riga a destra                         |
| <<         | Indenta riga a sinistra                       |
| zf{motion} | Crea fold                                     |
| zo         | Apri fold                                     |
| zc         | Chiudi fold                                   |
| zr         | Riduci livello fold                           |
| zm         | Aumenta livello fold                          |
| %          | Vai parentesi/parentesi graffa corrispondente |
| gcc        | Commenta / decommenta riga                    |
| gc{motion} | Commenta / decommenta blocco                  |
