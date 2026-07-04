#include <iostream>

using namespace std;

int main() {

    const int N=10;
    vector<vector<int>> tavolaPitagorica(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tavolaPitagorica[i][j] = (i+1)*(j+1);
        }
    }

    int n1, n2;
    do {
        cout << "Inserisci una coppia di numeri tra 1 e 10 (Ex. 10 2): ";
        cin >> n1 >> n2;
    } while (!(n1>=1 && n1<=10 && n2>=1 && n2<=10));

    cout << tavolaPitagorica[n1-1][n2-1] << endl;

    return 0;
}