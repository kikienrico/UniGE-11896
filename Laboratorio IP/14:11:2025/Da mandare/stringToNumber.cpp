#include <iostream>
#include <string>
using namespace std;

bool isValid(const string& str) {
    if (str.empty()) {
        return false;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    
    return true;
}

int stringToNumber(const string& str) {
    int numero = 0;
    
    for (int i = 0; i < str.length(); i++) {
        int cifra = str[i] - '0';
        
        numero = numero * 10 + cifra;
    }
    
    return numero;
}

int main() {
    string input;
    
    do {
        cout << "Inserisci un numero positivo: ";
        cin >> input;
        
        if (!isValid(input)) {
            cout << "Errore: inserire solo cifre numeriche!" << endl;
        }
    } while (!isValid(input));
    
    int numero = stringToNumber(input);
    cout << "Il numero è: " << numero << endl;
    
    return 0;
}