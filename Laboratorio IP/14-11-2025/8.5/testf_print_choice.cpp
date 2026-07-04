#include <iostream>
#include <ostream>

void print_choice(int n, std::string choice1, std::string choice2, std::string choice3, std::string choice4) {
    
    while (n<1 || n>4) {
        std::cout << "Il valore inserito è fuori dal range (1-4): ";
        std::cin >> n;
    }

    std::cout << "Scelta effettuata: ";

    switch (n) {
        case 1: std::cout << choice1 << std::endl; break;
        case 2: std::cout << choice2 << std::endl; break;
        case 3: std::cout << choice3 << std::endl; break;
        case 4: std::cout << choice4 << std::endl; break;
    } 
}

int main() {
    const std::string s1="Prima Scelta", s2="Seconda Scelta", s3="Terza Scelta", s4="Quarta Scelta";
    int n=0;

    print_choice(n, s1, s2, s3, s4);
}