#include <iostream>
using namespace std;

bool containsSubstring(const string& str, const string& substring) {
    for(int i = 0; i < str.length()-1; i++) {
        if (str.substr(i, substring.length())==substring) return true;
    }
    return false;
}

int main() {

    string str, substr;

    cout << "Inserisci una string: ";
    cin >> str;

    cout << endl << "Inserisci un altra string: ";
    cin >> substr;

    if (containsSubstring(str, substr)) {
        cout << substr;
    }

    return 0;
}