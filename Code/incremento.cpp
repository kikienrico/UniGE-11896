//
// Created by Christian Enrico on 23/10/25.
//
// Incremento di un elemento in posizione pos
// Input: sequenza v, elemento e, posizione pos
// Output: sequenza costituita da: gli elementi di v da 0 a pos-1, concatenati a e, concatenati a gli altri di v da pos alla fine

//1. Allungo di 1 il vector
//2. Spingo avanti di 1 tutti gli altri da pos in poi
//3. Inserisco e in posizione pos

#include <iostream>
using namespace std;

vector<int> inserisci(vector<int> v, int pos, int e) {
    v.resize(v.size()+1);

    for (int i=v.size()-1; i>pos; i--)
        v[i]=v[i-1];

    v[pos]=e;

    return v;
}

int main() {

    return 0;
}

