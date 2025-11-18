#include <iostream>
using namespace std;

int main() {
    cout << "Inserisci due numeri per fare la media\n";
    cout << "Primo numero: ";
    float firstnumb;
    cin >> firstnumb;

    cout << "Secondo numero: ";
    float secondnumb;
    cin >> secondnumb;

    cout << "Average:" << (firstnumb+secondnumb)/2;;

    return 0;
}