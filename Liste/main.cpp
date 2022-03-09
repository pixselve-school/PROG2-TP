#include <iostream>
#include "Liste.h"

int main() {
    Liste<int> liste = Liste<int>();
    liste.push_back(1);
    liste.push_back(2);


    std::cout << liste << "\n";
    for (Liste<int>::iterator i = liste.begin(); i != liste.end(); ++i) {
        std::cout << *i << "\n";

    }





//
//    std::cout << liste << "\n";
//
//    liste.pop_back();
//
//    std::cout << liste << "\n";
//    liste.pop_back();

//    liste.pop_back();



    return 0;
}
