#include <iostream>
#include <string>

using namespace std;

int readTemp() {
    int temp;
    cout << "Inserisci la temperatura (Celsius): ";
    cin >> temp;
    return temp;
}

string defineTemp(int temperatura) {
    string message;

    if (temperatura < -20 || temperatura > 40) {
        message = "Non ci credo, il termometro deve essere rotto";
    }
    else if (temperatura >= -20 && temperatura <= 0) {
        message = "Freddo incredibile";
    }
    else if (temperatura >= 1 && temperatura <= 15) {
        message = "Freddo";
    }
    else if (temperatura >= 16 && temperatura <= 23) {
        message = "Normale";
    }
    else if (temperatura >= 24 && temperatura <= 30) {
        message = "Caldo";
    }
    else if (temperatura >= 31 && temperatura <= 40) {
        message = "Caldo da morire";
    }

    return message;
}

void stampaRisultato(string messaggio) {
    cout << messaggio;
}

int main() {
    int temperatura = readTemp();
    string messaggio = defineTemp(temperatura);
    stampaRisultato(messaggio);

    return 0;
}