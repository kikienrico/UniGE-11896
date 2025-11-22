#include <iostream>
#include "triangle.h"
#include <cmath>
using namespace std;

int main() {

    Triangle triangolo;
    
    do {
        cout << "Inserisci le coordinate di un triangolo (x, y)\nDevono essere coordinate diverse tra di loro";
        cout << "Vertice 1 (x, y): ";
        cin >> triangolo.a.x >> triangolo.a.y;
        cout << "Vertice 2 (x, y): ";
        cin >> triangolo.b.x >> triangolo.b.y;
        cout << "Vertice 3 (x, y): ";
        cin >> triangolo.c.x >> triangolo.c.y;

    }while ((triangolo.a.x == triangolo.b.x && triangolo.a.y == triangolo.b.y) ||
            (triangolo.a.x == triangolo.c.x && triangolo.a.y == triangolo.c.y) ||
            (triangolo.b.x == triangolo.c.x && triangolo.b.y == triangolo.c.y));


    double AB, BC, CA, p;

    //Lato AB, opposto a C
    AB=sqrt(pow((triangolo.b.x-triangolo.a.x), 2)+pow((triangolo.b.y-triangolo.a.y), 2));

    //Lato BC, opposto ad A
    BC=sqrt(pow((triangolo.c.x-triangolo.b.x), 2)+pow((triangolo.c.y-triangolo.b.y), 2));

    //Lato CA, opposto a B
    CA=sqrt(pow((triangolo.a.x-triangolo.c.x), 2)+pow((triangolo.a.y-triangolo.c.y), 2));
    
    triangolo.perimetro=(AB+BC+CA);

    //per calcolare l'area mi serve il semiperimetro (p)
    p=triangolo.perimetro/2;

    //Area
    triangolo.area=sqrt(p*(p-AB)*(p-BC)*(p-CA));

    cout << "L'area del triangolo è: " << triangolo.area << endl << "Il perimetro del triangolo è: " << triangolo.perimetro;

    return 0;
}