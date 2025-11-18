#include <iostream>

using namespace std;

/*
    Scrivere un programma che chiede all’utente un numero intero positivo (>0) e verifica se è palindromo, ovvero se le sue cifre
    (in base 10) lette da destra a sinistra corrispondono alle cifre lette da sinistra a destra (ad esempio 165373561 è palindromo).
    Dopo la verifica stampa il risultato all’utente. Per risolvere questo esercizio si può partire dalla soluzione dell’esercizio 3.8.
    [ File ispalindrome.cpp ]
*/

int main() {
    int n;
    cout << "Inserisci un numero intero positivo (>0): ";
    cin >> n;

    int numb = n;
    int invertedNumb = 0;

    if (n>0) {
        while (n > 0) {
            int cifra = n % 10;
            invertedNumb = invertedNumb * 10 + cifra;
            n = n / 10;
        }

        if (numb == invertedNumb) {
            cout << numb << " è palindromo" << endl;
        } else {
            cout << numb << " non è palindromo" << endl;
        }
    } else {
        cout << "Il numero inserito è minore di 0";
    }

    return 0;
}