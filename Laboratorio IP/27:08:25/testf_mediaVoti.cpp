#include <iostream>

using namespace std;

int leggiVoto(int numeroStudente) {
    int voto;
    do {
        cout << "Inserisci il voto dello studente " << numeroStudente << " (0-100): ";
        cin >> voto;

        if (voto > 100 || voto < 0) {
            cout << "Voto non valido. Riprova." << endl;
        }
    } while (voto > 100 || voto < 0);

    return voto;
}

bool isPromosso(int voto) {
    if (voto >= 60) return true;
    return false;
}

int aggiornaSomma(int sommaAttuale, int voto) {
    return sommaAttuale + voto;
}

int aggiornaPromossi(int promossiAttuali, int voto) {
    if (isPromosso(voto)) return promossiAttuali+1;
    return promossiAttuali;
}

int aggiornaBocciati(int bocciatiAttuali, int voto) {
    if (!isPromosso(voto)) return bocciatiAttuali+1;
    return bocciatiAttuali;
}

int calcolaMassimo(int votoMassimo, int voto) {
    if (voto > votoMassimo) return voto;
    return votoMassimo;
}

int calcolaMinimo(int votoMinimo, int voto) {
    if (voto < votoMinimo) return voto;
    return votoMinimo;
}

int main() {

    int numeroStudenti;
    int sommaVoti = 0;
    int promossi = 0;
    int bocciati = 0;
    int votoMassimo = 0;
    int votoMinimo = 100;

    cout << "Inserisci il numero di studenti: ";
    cin >> numeroStudenti;

    for (int i = 1; i <= numeroStudenti; i++) {
        int voto = leggiVoto(i);

        sommaVoti = aggiornaSomma(sommaVoti, voto);
        promossi = aggiornaPromossi(promossi, voto);
        bocciati = aggiornaBocciati(bocciati, voto);
        votoMassimo = calcolaMassimo(votoMassimo, voto);
        votoMinimo = calcolaMinimo(votoMinimo, voto);
    }

    double media = static_cast<double>(sommaVoti) / numeroStudenti;

    cout << "Media della classe: " << media << endl;
    cout << "Voto più alto: " << votoMassimo << endl;
    cout << "Voto più basso: " << votoMinimo << endl;
    cout << "Numero di studenti promossi: " << promossi << endl;
    cout << "Numero di studenti bocciati: " << bocciati;

    return 0;
}