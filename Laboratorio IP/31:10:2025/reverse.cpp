#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int n=10;
    vector<int> source(n), dest(source.size());
    int test=0;

    for (int i=0; i<n; i++) cin >> source[i];
    for (int i=n-1; i>0; i--) {
        dest[test]=source[i];
        test++;
    }

    for (int i=0; i<n; i++) cout << source[i];
    cout << "\n";
    for (int i=0; i<n; i++) cout << dest[i];

    return 0;
}