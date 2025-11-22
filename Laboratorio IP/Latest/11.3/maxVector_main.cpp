#include <iostream>
#include "maxVector.h"
using namespace std;

int main() {

    vector<int> v={4, 8, 9, 23, 0, 1, 9, 24};

    try {
        cout << maxVector(v);
    }
    catch(string& e) {
        cout << e;
    }
    
    return 0;
}