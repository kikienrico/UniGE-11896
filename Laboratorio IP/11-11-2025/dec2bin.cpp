#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int N=10;
    vector<int> binary(N, 0);
    int n;

    cout << "Inserisci un numero intero positivo (<1024): ";
    cin >> n;

    if (n<1024 && n>=0) {
        int resto;

        for(int i=0; n>0; i++) {
            resto = n%2;
            binary[i]=resto;
            n/=2;
        }
        
        for (int i = N - 1; i >= 0; i--) {
            cout << binary[i];
        }
    } else cout << "Numero NON valido";



    return 0;
}