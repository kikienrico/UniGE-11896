#include <iostream>

using namespace std;

int main() {
    char mossa1, mossa2;

    cout << "Mosse valide: 'f' = forbice, 'c' = carta, 's' = sasso \n";

    cout << "Giocatore 1, inserisci la tua mossa: ";
    cin >> mossa1;

    if (mossa1 != 'f' && mossa1 != 'c' && mossa1 != 's') {
        cout << "Error1: mossa non valida";
        return 1; //flag
    }

    cout << "Giocatore 2, inserisci la tua mossa: ";
    cin >> mossa2;

    if (mossa2 != 'f' && mossa2 != 'c' && mossa2 != 's') {
        cout << "Error2: mossa non valida";
        return 1; //flag
    }

    if (mossa1 == mossa2) {
        cout << "Pareggio!";
    } else if ((mossa1 == 'f' && mossa2 == 'c') || (mossa1 == 'c' && mossa2 == 's') || (mossa1 == 's' && mossa2 == 'f')) {
        cout << "Giocatore 1 hai vinto!";
    } else {
        cout << "Giocatore 2 hai vinto!";
    }

    return 0;
}