#include <iostream>

int get_choice(int max) {
    int choice;

    do {
        std::cout << "Inserisci una scelta fra 1 e " << max << ": ";
        std::cin >> choice;
    }while (choice<1 || choice>max);

    return choice;
}

int main() {

    int max=7;

    get_choice(max);
}