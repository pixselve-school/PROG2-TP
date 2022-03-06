#include <iostream>
#include "Liste.h"

int main() {
    Liste<int> liste = Liste<int>();
    liste.push_back(1);
    liste.push_back(2);
//    liste.push_back(3);

    std::cout << liste << "\n";
    for (Liste<int>::iterator i = liste.begin(); i != liste.end(); ++i) {
        *i = 9;
        std::cout << *i << "\n";

    }





//
//    std::cout << liste << "\n";
//
//    liste.pop_back();
//
//    std::cout << liste << "\n";
//    liste.pop_back();
//
    std::cout << liste << "\n";
//    liste.pop_back();



    return 0;
}
