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

void rotateN(vector<int>& v, int N) {
    int size=v.size();
    if(size==0) return;
    
    int absN=abs(N)%size;
    if(absN==0) return;
    
    vector<int> temp=v;
    
    if(N>0) {
        for(int i=0; i<size; i++) {
            v[i]=temp[(i-absN+size)%size];
        }
    } else {
        for(int i=0; i<size; i++) {
            v[i]=temp[(i+absN)%size];
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
    
    rotateN(v,N);
    
    cout<<"Vector dopo rotazione di "<<N<<" posizioni: ";
    stampaVector(v);
    
    return 0;
}