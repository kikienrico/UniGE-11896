//
// Created by Christian Enrico on 27/10/25.
//

#include <iostream>

using namespace std;

double onlineAverage() {
    double n=0, sum=0;
    int counter=0;
    char choice='y';

    while (choice=='y' || choice=='Y') {
        cout << "Inserisci un numero reale: ";
        cin >> n;

        sum+=n;

        cout << "Vuoi continuare l'inserimento di numeri? [Y] [N]: ";
        cin >> choice;

        counter++;
    }
    return sum/counter;
}

int main() {

    double test=onlineAverage();

    cout << test;

}
