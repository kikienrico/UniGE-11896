#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void stampaVector(const vector<int>& v) {
    cout<<"{ ";
    for(int i=0; i<v.size(); i++) {
        cout<<v[i];
        if(i<v.size()-1) cout<<", ";
    }
    cout<<" }";
}

void selectionSort(vector<int>& v) {
    for(int i=0; i<v.size()-1; i++) {
        int minIndex=i;
        for(int j=i+1; j<v.size(); j++) {
            if(v[j]<v[minIndex]) {
                minIndex=j;
            }
        }
        if(minIndex!=i) {
            int temp=v[i];
            v[i]=v[minIndex];
            v[minIndex]=temp;
        }
    }
}

void mergeVectors(const vector<int>& s1, const vector<int>& s2, vector<int>& d) {
    int i=0, j=0, k=0;
    
    while(i<s1.size() && j<s2.size()) {
        if(s1[i]<=s2[j]) {
            d[k]=s1[i];
            i++;
        } else {
            d[k]=s2[j];
            j++;
        }
        k++;
    }
    
    while(i<s1.size()) {
        d[k]=s1[i];
        i++;
        k++;
    }
    
    while(j<s2.size()) {
        d[k]=s2[j];
        j++;
        k++;
    }
}

int main() {
    srand(time(NULL));
    
    const int N=9;
    const int M=10;
    vector<int> s1(N);
    vector<int> s2(M);
    vector<int> d(N+M);
    
    for(int i=0; i<N; i++) {
        s1[i]=rand()%256;
    }
    
    for(int i=0; i<M; i++) {
        s2[i]=rand()%256;
    }
    
    cout<<"Vector s1 (generato) = ";
    stampaVector(s1);
    cout<<endl;
    
    cout<<"Vector s2 (generato) = ";
    stampaVector(s2);
    cout<<endl;
    
    selectionSort(s1);
    selectionSort(s2);
    
    cout<<"Vector s1 (ordinato) = ";
    stampaVector(s1);
    cout<<endl;
    
    cout<<"Vector s2 (ordinato) = ";
    stampaVector(s2);
    cout<<endl;
    
    mergeVectors(s1,s2,d);
    
    cout<<"Vector d = ";
    stampaVector(d);
    cout<<endl;
    
    return 0;
}