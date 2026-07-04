#include <iostream>

using namespace std;

/*
    Scrivere un programma che chiede all’utente un numero intero positivo n e stampa un rombo di asterischi che sulle due
    diagonali ha 2 ∗ n + 1 caratteri.
    [SUGGERIMENTO: È più facile stampare il rombo con due cicli, il primo per le righe in cui il numero di asterischi cresce e
    il secondo per le righe in cui il numero di asterischi diminuisce. In questo modo si può suddividere l’esercizio in due parti:
    (a) stampare il triangolo superiore (la parte superiore del rombo), dopodichè (b) adattare il codice per stampare il triangolo
    inferiore (la parte inferiore del rombo).]
*/

int main() {
    int n;
    cout << "Inserisci un numero positivo : ";
    cin >> n;

    // parte superiore (e riga centale)
    for (int i = 0; i <= n; i++) {
        // spazi
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        // asterischi
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // parte inferiore
    for (int i = n - 1; i >= 0; i--) {
        // spazi
        for (int j = 0; j < n - i; j++) {
            cout << " ";
        }
        // asterischi
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}