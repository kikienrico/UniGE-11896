#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int n=10;
    vector<float> source(n);
    float temp;

    for (int i=0; i<n; i++) cin >> source[i];

    for (int i=0; i<n/2; i++) {
        temp = source[i];
        source[i] = source[n-1-i];
        source[n-1-i] = temp;
    }

    for (int i=0; i<n; i++) cout << source[i] << " ";

    return 0;
}