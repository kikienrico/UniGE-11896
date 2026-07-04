#include <iostream>
using namespace std;

void square(int n){
    if (n <= 0) throw string("Errore valore < 1");

    for(int i=0; i<n; i++) { //stampa la parte superiore del quadrato
        cout << "x ";
    }

    cout << endl;

	for(int i=0; i<n-2; i++) { //stampa la parte laterale del quadrato
        cout << "x ";
            for(int i=0; i<n-2; i++) {
                cout << "  ";
            }
            cout << "x" << endl;
    }

    if(n>1) {
        for(int i=0; i<n; i++) { //stampa la parte inferiore del quadrato
            cout << "x ";
        }
    }

    
}

int main(){
	int n;
	cin >> n;
	try{
		square(n);
	}
	catch(string& e)
	{
		cout << e << endl;
	}
}