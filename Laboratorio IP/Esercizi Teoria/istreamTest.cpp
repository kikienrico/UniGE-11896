#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    ifstream test; vector<double> v;
    test.open("dati.dat");
    int n;
    test >> n;
    v.resize(n);

    for (int i=0; i<n; i++) {
        test >> v[i];
    }

    return 0;
}