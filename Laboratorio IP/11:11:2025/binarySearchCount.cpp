#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N=30;
    vector<int> v={2,5,8,12,16,23,28,31,35,42,47,53,58,64,69,75,81,86,92,98,103,109,115,121,127,133,139,145,151,157};
    int item;
    int count=0;
    
    cout << "Inserisci il valore da cercare: ";
    cin >> item;
    
    int left=0;
    int right=N-1;
    int loc=-1;
    bool found=false;
    
    while(left<=right && !found) {
        int mid=(left+right)/2;
        count++;
        
        if(v[mid]==item) {
            found=true;
            loc=mid;
        } else if(v[mid]<item) {
            left=mid+1;
        } else {
            right=mid-1;
        }
    }
    
    if(found) {
        cout << item << " e' stato trovato in posizione " << loc << endl;
    } else {
        cout << item << " non e' stato trovato" << endl;
    }
    
    cout << "Numero di accessi al vector: " << count << endl;
    
    return 0;
}