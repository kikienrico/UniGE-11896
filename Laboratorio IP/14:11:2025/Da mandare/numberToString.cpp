#include <iostream>
#include <string>
using namespace std;

string numberToString(int number) {
    string risultato = "";
    
    while (number > 0) {
        int ultimaCifra = number % 10;
        char digitChar = '0' + ultimaCifra;  
        risultato = digitChar + risultato;  
        number = number / 10;
    }
    
    return risultato;
}

int main() {
    int n=-1;

    while(n<0) {
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    }

    cout << numberToString(n);

    return 0;
}