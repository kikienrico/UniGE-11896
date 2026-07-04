#include <iostream>
#include <string>

using namespace std;

int readMonth() {
    int n;
    cout << "Inserisci il numero di un mese: ";
    cin >> n;
    return n;
}

string getMonthName(int n) {
    string monthName;

    switch (n) {
        case 1: monthName = "Gennaio"; break;
        case 2: monthName = "Febbraio"; break;
        case 3: monthName = "Marzo"; break;
        case 4: monthName = "Aprile"; break;
        case 5: monthName = "Maggio"; break;
        case 6: monthName = "Giugno"; break;
        case 7: monthName = "Luglio"; break;
        case 8: monthName = "Agosto"; break;
        case 9: monthName = "Settembre"; break;
        case 10: monthName = "Ottobre"; break;
        case 11: monthName = "Novembre"; break;
        case 12: monthName = "Dicembre"; break;
        default: monthName = "NON valido";
    }

    return monthName;
}

void print(string nomeMese) {
    if (nomeMese == "NON valido") {
        cout << "Mese NON valido!";
    } else {
        cout << nomeMese;
    }
}

int main() {
    int numeroMese = readMonth();

    string nomeMese = getMonthName(numeroMese);

    print(nomeMese);

    return 0;
}