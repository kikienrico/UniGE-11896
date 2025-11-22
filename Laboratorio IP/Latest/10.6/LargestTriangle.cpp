#include <iostream>
#include "triangle.h"
#include <cmath>
#include <vector>
using namespace std;

int main() {
    vector<Triangle> Triangolo(3);
    int numeroTriangolo;
    double biggestArea;
    for (int i = 0; i < 3; i++) {
        do {
            cout << "Inserisci le coordinate di un triangolo (x, y)\nDevono essere coordinate diverse tra di loro\n";
            cout << "Vertice 1 (x, y): ";
            cin >> Triangolo[i].a.x >> Triangolo[i].a.y;
            cout << "Vertice 2 (x, y): ";
            cin >> Triangolo[i].b.x >> Triangolo[i].b.y;
            cout << "Vertice 3 (x, y): ";
            cin >> Triangolo[i].c.x >> Triangolo[i].c.y;
        }while ((Triangolo[i].a.x == Triangolo[i].b.x && Triangolo[i].a.y == Triangolo[i].b.y) ||
        (Triangolo[i].a.x == Triangolo[i].c.x && Triangolo[i].a.y == Triangolo[i].c.y) ||
        (Triangolo[i].b.x == Triangolo[i].c.x && Triangolo[i].b.y == Triangolo[i].c.y));

        double AB, BC, CA, p;

        //Lato AB, opposto a C
        AB=sqrt(pow((Triangolo[i].b.x-Triangolo[i].a.x), 2)+pow((Triangolo[i].b.y-Triangolo[i].a.y), 2));

        //Lato BC, opposto ad A
        BC=sqrt(pow((Triangolo[i].c.x-Triangolo[i].b.x), 2)+pow((Triangolo[i].c.y-Triangolo[i].b.y), 2));
        
        //Lato CA, opposto a B
        CA=sqrt(pow((Triangolo[i].a.x-Triangolo[i].c.x), 2)+pow((Triangolo[i].a.y-Triangolo[i].c.y), 2));

        Triangolo[i].perimetro=(AB+BC+CA);

        //per calcolare l'area mi serve il semiperimetro (p)
        p=Triangolo[i].perimetro/2;



        //Area
        Triangolo[i].area=sqrt(p*(p-AB)*(p-BC)*(p-CA));

        biggestArea=Triangolo[0].area;

        if(biggestArea<Triangolo[i].area) {
            biggestArea=Triangolo[i].area;
            numeroTriangolo=i+1;
        }
    }

    cout << "Il triangolo con l'area più grande è il triangolo " << numeroTriangolo << ", con area: " << biggestArea;

    return 0;
}