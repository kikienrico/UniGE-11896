#include <cstdlib>
#include <ctime>
#include <iostream>

/*
    Partendo dall’esercizio già svolto (vedi precedenti sezioni) scrivere un programma che gioca più mani di morra cinese però
    contro il computer. Come primo passo consigliamo di modificare l’esercizio 2.9 in modo da inserire per il turno del computer
    (che sostituisce Giocatore 2) la generazione di una mossa random (suggerimento: generare un numero intero tra 0 e 2 e
    associarlo alle mosse 0=>’f’, 1=>’c’, 2=>’s’). Esempio minimale di generazione di un numero random compreso tra 0 e 9
    (per l’esercizio servirà tra 0 e 2):
    Poi, alla fine di ogni mano il programma deve dire chi ha vinto (cioè il giocatore umano o il computer) ha vinto e chie-
    dere all’utente se vuole continuare; se l’utente risponde ’S’ o ’s’ prosegue con un’altra mano, altrimenti termina. [ File
    partitamorra.cpp ]
*/

using namespace std;
int main() {
    srand(time(NULL)); // questa linea va eseguita una volta sola nel programma

    char mossa1, mossa2 = 0;

    cout << "Mosse valide: 'f' = forbice, 'c' = carta, 's' = sasso \n";

    bool stop = true;
    char cont;
    while (stop==true) {
        switch (int randomNumber = (rand()%3)) {
            case 0: mossa2 = 'c'; break;
            case 1: mossa2 = 'f'; break;
            case 2: mossa2 = 's'; break;
            default: cout << "Error: switch";
        }

        cout << mossa2 << endl;

        cout << "Inserisci la tua mossa: ";
        cin >> mossa1;

        if (mossa1 != 'f' && mossa1 != 'c' && mossa1 != 's') {
            cout << "Error1: mossa non valida";
            return 1; //flag
        }

        if (mossa1 == mossa2) {
            cout << "Pareggio!" << endl;
        } else if ((mossa1 == 'f' && mossa2 == 'c') || (mossa1 == 'c' && mossa2 == 's') || (mossa1 == 's' && mossa2 == 'f')) {
            cout << "Hai vinto!" << endl;
        } else {
            cout << "Giocatore 2 hai vinto!" << endl;
        }

        cout << "Vuoi continuare la partita? (Digita S per continuare): ";
        cin >> cont;
        if (cont == 's' || cont == 'S') {
            stop=true;
        } else {
            stop=false;
        }
    }

    return 0;
}
