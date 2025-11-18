#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Inserisci un numero intero: ";
    cin >> n;

    bool stop = false;
    float guess;
    float sq = sqrt(n);

    int radice_intera = (int)sq;
    if (radice_intera * radice_intera != n) {
        sq = (int)sq;
        cout << "Per facilitare il gioco, a tutti i valori senza quadrato perfetto vengono troncati i valori decimali (2.234532 -> 2)" << endl;
    }

    while (stop == false) {
        cout << "Indovina la sqrt di " << n << ": ";
        cin >> guess;

        if (guess == sq) {
            cout << "Bravo!" << endl;
            stop = true;
        } else {
            cout << "Niente da fare, riprova!" << endl;
        }
    }

    return 0;
}