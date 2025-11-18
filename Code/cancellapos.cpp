//
// Created by Christian Enrico on 23/10/25.
// Cancella un elemento di una sequenza
#include <iostream>

using namespace std;

vector<int> cancella(vector<int> v, int pos) {
    for (int i=pos+1; i<v.size(); i++) {
        v[i-1]=v[i];
        v.pop_back(); // v.resize(v.size()-1);
    }
    return v;
}

int main() {
    vector<int> v; int pos;
    //riempio v
    //acquisisco e

    for (int i=pos+1; i<v.size(); i++) {
        v[i-1]=v[i];
         v.pop_back(); // v.resize(v.size()-1);
    }


    return 0;
}
