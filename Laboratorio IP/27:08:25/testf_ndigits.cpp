//
// Created by Christian Enrico on 27/10/25.
//

#include <iostream>

using namespace std;

int getLength(int n) {
    int counter = 0;
    while (n>0) {
        n/=10;
        counter++;
    }
    return counter;
}

int main() {
    int test;

    cin >> test;

    cout << "Il numero ha " << getLength(test) << " cifre";
}
