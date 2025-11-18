#include <iostream>
using namespace std;

void reverseString(string& str) {
    for(int i = 0; i < str.length()/2; i++) {
        char temp=str[str.length()-1-i];
        str[str.length()-1-i]=str[i];
        str[i]=temp;
    }
    cout << str;
}

int main() {

    string test;
    cout << "Inserisci del testo: ";
    cin >> test;

    reverseString(test);
    
    return 0;
}