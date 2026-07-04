#include <iostream>

using namespace std;

int main() {
    int n;
    int k=13;

    cout << "Inserisci un numero: ";
    cin >> n;

    if (n%k==0) {
        cout << "Numero divisibile per " << k;
    } else cout << "Numero non divisibile per " << k;
}
