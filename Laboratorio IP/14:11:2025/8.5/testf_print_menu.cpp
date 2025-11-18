#include <iostream>

void print_menu(std::string choice1, std::string choice2, std::string choice3, std::string choice4) {
    std::cout << "1  " << choice1 << std::endl;
    std::cout << "2  " << choice2 << std::endl;
    std::cout << "3  " << choice3 << std::endl;
    std::cout << "4  " << choice4 << std::endl;
}


int main() {
    const std::string s1="Prima Scelta", s2="Seconda Scelta", s3="Terza Scelta", s4="Quarta Scelta";

    print_menu(s1, s2, s3, s4);
}