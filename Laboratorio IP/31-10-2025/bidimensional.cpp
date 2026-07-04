#include <iostream>

using namespace std;

int main() {

    const int M=5, N=8;
    vector<vector<int>> a(M, vector<int>(N));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}