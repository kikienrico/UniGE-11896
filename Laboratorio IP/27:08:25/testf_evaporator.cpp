//
// Created by Christian Enrico on 27/10/25.
//
/*
    Un evaporatore è una macchina in cui viene inserita una certa quantità iniziale di acqua e che ogni giorno ne disperde una
    percentuale prefissata nell’ambiente. Quando l’acqua contenuta scende sotto la soglia minima di funzionamento la macchina
    si spegne per evitare danni.
    Scrivere una funzione che presi come argomenti un float che rappresenta i litri di acqua inizialmente introdotti nella mac-
    china, un int che rappresenta la percentuale di evaporazione giornaliera e un float che indica la soglia minima al di sotto
    della quale la macchina si spegne, restituisce il numero di giorni in cui la macchina può continuare ad operare senza essere
    riempita. Si assuma che tutti gli argomenti siano sempre non negativi.
*/

#include <iostream>

using namespace std;

int untilOff(float liters, int evaporationRate, float deadLine) {

    int days=0;

    while (liters>=deadLine) {
        liters-=liters*evaporationRate/100;
        days++;
    }


    return days;
}

int main() {

    float liters, deadLine;
    int evaporationRate;

    cout << "Inserisci i litri, percentuale di evaporazione e dealine di spegnimento: ";
    cin >> liters >> evaporationRate >> deadLine;

    cout << "La macchina si spegnerebbe in " << untilOff(liters, evaporationRate, deadLine) << " giorni";

}
