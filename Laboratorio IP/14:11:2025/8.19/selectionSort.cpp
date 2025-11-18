#include <iostream>
using namespace std;



int main() {
    vector<int> v;
    for(int i = 0; i < v.size()-1; i++) {
        int minIndex=i;

        for(int j = i+1; j < v.size(); j++) {
            if (v[j]<v[minIndex]) minIndex=j;
        }

        if(minIndex != i) {
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
        }
    }

    cout << endl;
    
    return 0;
}