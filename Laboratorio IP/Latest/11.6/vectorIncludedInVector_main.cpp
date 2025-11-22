#include <iostream>
#include "vectorIncludedInVector_funct.h"
using namespace std;

int main() {
    // tutti i valori di t1 sono inclusi in t2
    vector<int> t1 = {1, 2, 3, 4, 5};
    vector<int> t2 = {7, 1, 9, 2, 3, 11, 4, 5, 8};

    // nessun valore di t1 è compreso in t2
    // vector<int> t1 = {1, 2, 3, 4, 5};
    // vector<int> t2 = {10, 20, 30, 40, 50};

    // t1 vuoto
    // vector<int> t1 = {};
    // vector<int> t2 = {1, 2, 3, 4, 5};

    if (vectorIncludedInVector(t1, t2)) {
        cout << "Tutti i valori di t1 sono compresi in t2, oppure t1 è vuoto";
    } else {
        cout << "I valori di t1 non sono tutti compresi in t2";
    }
    
    return 0;
}