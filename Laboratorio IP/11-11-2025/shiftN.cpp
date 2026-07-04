#include <iostream>
#include <vector>

using namespace std;

void stampaVector(const vector<int>& v) {
    cout<<"[ ";
    for(int i=0; i<v.size(); i++) {
        cout<<v[i];
        if(i<v.size()-1) cout<<" ";
    }
    cout<<" ]"<<endl;
}

void shiftN(vector<int>& v, int N) {
    int size=v.size();
    int absN=abs(N);
    
    if(absN>=size) {
        for(int i=0; i<size; i++) {
            v[i]=0;
        }
        return;
    }
    
    if(N>0) {
        for(int i=0; i<size-absN; i++) {
            v[i]=v[i+absN];
        }
        for(int i=size-absN; i<size; i++) {
            v[i]=0;
        }
    } else if(N<0) {
        for(int i=size-1; i>=absN; i--) {
            v[i]=v[i-absN];
        }
        for(int i=0; i<absN; i++) {
            v[i]=0;
        }
    }
}

int main() {
    const int D=10;
    vector<int> v(D);
    int N;
    
    cout<<"Inserisci "<<D<<" elementi: ";
    for(int i=0; i<D; i++) {
        cin>>v[i];
    }
    
    cout<<"Vector originale: ";
    stampaVector(v);
    
    cout<<"Inserisci N (positivo=destra, negativo=sinistra): ";
    cin>>N;
    
    shiftN(v,N);
    
    cout<<"Vector dopo shift di "<<N<<" posizioni: ";
    stampaVector(v);
    
    return 0;
}