//
// Created by Christian Enrico on 27/10/25.
//

#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n<=1) return false; //1, 0, minori di zero non primi
    if (n==2) return true; //2 unico numero primo pari
    if (n%2==0) return false; //se divisibile per 2 pari

    int j = sqrt(n);

    for (int i = 3; i < j; i+=2) {
        if (n%i==0) return false;
    }
    return true;
}

int main() {
    int test;

    cin >> test;

    cout << isPrime(test);

    return 0;
}
