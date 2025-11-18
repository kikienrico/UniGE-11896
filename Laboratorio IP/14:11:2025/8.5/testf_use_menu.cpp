#include <iostream>

void print_menu(std::string choice1, std::string choice2, std::string choice3, std::string choice4) {
    std::cout << "1  " << choice1 << std::endl;
    std::cout << "2  " << choice2 << std::endl;
    std::cout << "3  " << choice3 << std::endl;
    std::cout << "4  " << choice4 << std::endl;
}

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

int get_choice(int max) {
    int choice;

    do {
        std::cout << "Inserisci una scelta fra 1 e " << max << ": ";
        std::cin >> choice;
    }while (choice<1 || choice>max);

    return choice;
}

int use_menu (std::string choice1, std::string choice2, std::string choice3, std::string choice4) {

    print_menu(choice1, choice2, choice3, choice4);
    int n=get_choice(4);
    print_choice(n, choice1, choice2, choice3, choice4);

    return n;
}

int main() {
    const std::string s1="Prima Scelta", s2="Seconda Scelta", s3="Terza Scelta", s4="Quarta Scelta";

    use_menu(s1, s2, s3, s4);
}