#include <iostream>
#include <ostream>
#include <cmath>

using namespace std;

struct Point{
    double x, y;
};

int main() {
    int N=4; //valore preimpostato ma modificabile
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
        cout << "Le coordinate sono uguali" << endl;
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
    else if (closed) {
        switch (N-1) {
            case 3: cout << "La linea è chiusa e quindi definisce un triangolo." << endl; break;
            case 4: cout << "La linea è chiusa e quindi definisce un quadrilatero." << endl; break;
            case 5: cout << "La linea è chiusa e quindi definisce un pentagono." << endl; break;
            case 6: cout << "La linea è chiusa e quindi definisce un esagono." << endl; break;
            case 7: cout << "La linea è chiusa e quindi definisce un ettagono." << endl; break;
            case 8: cout << "La linea è chiusa e quindi definisce un ottagono." << endl; break;
            case 9: cout << "La linea è chiusa e quindi definisce un ennagono." << endl; break;
            case 10: cout << "La linea è chiusa e quindi definisce un decagono." << endl; break;
            case 11: cout << "La linea è chiusa e quindi definisce un endecagono." << endl; break;
            case 12: cout << "La linea è chiusa e quindi definisce un dodecagono." << endl; break;
            case 13: cout << "La linea è chiusa e quindi definisce un tridecagono." << endl; break;
            case 14: cout << "La linea è chiusa e quindi definisce un tetradecagono." << endl; break;
            case 15: cout << "La linea è chiusa e quindi definisce un pentadecagono." << endl; break;
            case 16: cout << "La linea è chiusa e quindi definisce un esadecagono." << endl; break;
            case 17: cout << "La linea è chiusa e quindi definisce un eptadecagono." << endl; break;
            case 18: cout << "La linea è chiusa e quindi definisce un ottadecagono." << endl; break;
            case 19: cout << "La linea è chiusa e quindi definisce un enneadecagono." << endl; break;
            case 20: cout << "La linea è chiusa e quindi definisce un icosagono." << endl; break;
            //!oltre i 20 lati si usa la forma generica "poligono di N lati"
            default: cout << "La linea è chiusa e quindi definisce un poligono." << endl; break;
        }
    }
    return 0;
}