#include <iostream>
#include <vector>
using namespace std;

void selectionSortByValue(vector<int> v) {
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
}

void selectionSortByReference(vector<int>& v) {
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
}


int main() {

    vector<int> v={5,12, 65, 76, 1, 9};

    // by value
    selectionSortByValue(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;
    
    //by reference
    selectionSortByReference(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}