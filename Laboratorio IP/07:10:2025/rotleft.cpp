#include <iostream>

using namespace std;

int main() {
    float x, y ,z;
    cout<<"Inserisci 3 valori numerici: ";
    cin >> x >> y >> z;

    float temp=0;
    temp=x;
    x=y;
    y=z;
    z=temp;

    cout<<"I valori sono: " << x << " " << y << " " << z;

    return 0;
}