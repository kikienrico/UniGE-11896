#include <iostream>
using namespace std;

int main() {
    cout << "Le ore devono essere comprese tra 0 e 23, i minuti tra 0 e 59 \n";
    cout<<"Inserisci un numero di ore, separando ore e minuti con uno spazio(es. 22 15): ";
    int hours, minutes;
    cin>>hours>>minutes;
    cout<< "L'orario: " << hours << ":" << minutes << " corrisponde a " << hours*60+minutes << " minuti";

    return 0;
}