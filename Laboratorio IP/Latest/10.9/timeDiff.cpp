#include <iostream>
using namespace std;

struct Time {
    unsigned int hours, minutes, seconds;
};

int main() {
    Time orario1, orario2;
    string e = "L'orario inserito non è ammissibile.";


    //!T1 deve rappresentare un ora precedente o uguale a T2 (T<=T2)

    try {
        //prima lettura dati
        cout << "Tenere a mente che il primo orario DEVE essere <= al secondo" << endl;
        cout << "Inserisci il primo orario" << endl;
        cout << "Ore: ";
        cin >> orario1.hours;
        cout << "Minuti: ";
        cin >> orario1.minutes;
        cout << "Secondi: ";
        cin >> orario1.seconds;

        cout << "Inserisci il secondo orario" << endl;
        cout << "Ore: ";
        cin >> orario2.hours;
        cout << "Minuti: ";
        cin >> orario2.minutes;
        cout << "Secondi: ";
        cin >> orario2.seconds;  
        
        if (((orario1.hours > 23 || orario1.minutes > 59 || orario1. seconds > 59) ||
            (orario2.hours > 23 || orario2.minutes > 59 || orario2. seconds > 59)) ||
            (orario1.hours>orario2.hours) || (orario1.hours==orario2.hours && orario1.minutes>orario2.minutes) ||
            (orario1.hours==orario2.hours && orario1.minutes==orario2.minutes && orario1.seconds>orario2.seconds)) {
            throw e;
        }
    }
    catch(string& e) {
        cout << e;
    }

    int oreT = orario2.hours-orario1.hours;
    int minutiT = orario2.minutes-orario1.minutes;
    int secondiT = orario2.seconds-orario1.seconds;

    if (secondiT<0) {
        secondiT+=60;
        minutiT--;
    }

    if (minutiT<0) {
        minutiT+=60;
        oreT--;
    }

    cout << "Sono trascorse " << oreT << " ore, " << minutiT << " minuti e " << secondiT << " secondi.";

    return 0;
}