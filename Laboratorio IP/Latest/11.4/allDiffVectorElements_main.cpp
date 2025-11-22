#include <iostream>
#include "allDiffVectorElements_funct.h"
using namespace std;

int main() {
    
    vector<int> v{20, 50, 12, 53, 12, 1, 7, 9};
    if (allDiffVectorElements(v)) {
        cout << "Tutti gli elementi del vector sono diversi";
    } else {
        cout << "Ci sono elementi uguali all'interno del vector";
    }

    return 0;
}