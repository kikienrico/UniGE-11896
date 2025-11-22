#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;

struct Point{
    double x, y;
};

int main() {
    int N=5; //valore preimpostato ma modificabile
    vector<Point> polygon(N);

    cout << "Inserici " << N << " coordinate per costruire un poligono" << endl;

    for(size_t i = 0; i < N; i++) {
        cout << "Inserisci la " << i+1 << "a coordinata (x, y): ";
        cin >> polygon[i].x >> polygon[i].y; //vector[(x,y), (x,y)]
        // do {
        //     cout << "Inserisci la " << i << "a coordinata (x, y): ";
        //     cin >> polygon[i].x >> polygon[i].y; //vector[(x,y), (x,y)]
        // }while ((polygon[i].x == polygon[i].y) && (polygon[i].x == polygon[i].y));
    }

    //controllo doppioni
    exception e;

    try {
        for(size_t i = 0; i < N-1; i++) {
        // if ((polygon[i].x == polygon[i+1].x) && (polygon[i].y == polygon[i+1].y)) {
        //     throw e;
        // }
            for(size_t j = i+1; j < N-1; j++) {
                if ((polygon[i].x == polygon[j].x) && (polygon[i].y == polygon[j].y)) {
                    throw e;
                }
            }
        }
    }
    catch(exception& e) {
        cout << "Le coordinate sono uguali";
    }
    

    //calcolo lunghezza totale
    double totalLength=0;
    bool sameLength=false;
    bool closed=false;

    for(size_t i = 0; i < N-1; i++) {
        totalLength+=sqrt(pow((polygon[i+1].x-polygon[i].x), 2)+pow((polygon[i+1].y-polygon[i].y), 2));
    }

    //controllo lati uguali
    if ((totalLength/4)==sqrt(pow((polygon[1].x-polygon[0].x), 2)+pow((polygon[1].y-polygon[0].y), 2))) sameLength=true;
    
    //controllo linea chiusa
    if ((polygon[0].x == polygon[N-1].x) && (polygon[0].y == polygon[N-1].y)) closed=true;

    cout << totalLength << endl;
    if (sameLength) cout << "Tutti i lati hanno la stessa lunghezza." << endl;
    if (sameLength && closed) cout << "La linea è chiusa e quindi definisce un poligono regolare." << endl;
    else if (closed) cout << "La linea è chiusa e quindi definisce un poligono." << endl;

    return 0;
}