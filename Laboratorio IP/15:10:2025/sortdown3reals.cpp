#include <iostream>

using namespace std;

int main() {
    int n1, n2, n3;
    cout << "Inserisci 3 numeri interi: ";
    cin >> n1 >> n2 >> n3;

    cout << "I numeri in ordine decrescente: ";

    if (n1 >= n2 && n1 >= n3) {
        cout << n1;
        if (n2 >= n3) {
            cout << " " << n2 << " " << n3;
        } else cout << " " << n3 << " " << n2;
    } else if (n2 >= n1 && n2 >= n3) {
        cout << n2;
        if (n1 >= n3) {
            cout << " " << n1 << " " << n3;
        } else cout << n3 << n1;
    } else if (n3 >= n1 && n3 >= n2) {
        cout << n3;
        if (n1 >= n2) {
            cout << " " << n1 << " " << n2;
        } else cout << " " << n2 << " " << n1;
    }

    return 0;
}