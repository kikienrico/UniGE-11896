#include <iostream>
using namespace std;

void computeRectInfo(double l1, double l2, double& area, double& perimetro) {
    if (l1<0 && l2<0) throw string("Entrambi i valori di l1 e l2 sono negativi");
    if (l1<0) throw string("Il lato l1 è un valore negativo");
    if (l2<0) throw string("Il lato l2 è un valore negativo");
    perimetro=l1*2+l2*2;
    area=l1+l2;
}

int main() {
    try {
        double area, per, l1=10, l2=5;
        computeRectInfo(l1, l2, area, per);

        cout << area << " " << per;
        
    }
    catch(string& e) {
        cout << e << endl;
    }
    
    return 0;
}