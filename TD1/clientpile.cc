#include <iostream>
#include "pile.hh"

// signatures fonctions internes
void
test(std::string ch1, std::string ch2);

int main() {
    std::string ch1 = "Bonjour";
    std::string ch2 = "Au revoir";
    test(ch1, ch2);

    return 0;
}

//void test(std::string ch1, std::string ch2) {
//    // 1. Créer une pile de réels
//    Pile *pile = new Pile;
//    // 2.
//    pile->push(ch1);
//    // 3.
//    pile->push(ch2);
//    if (pile->top() == "") {
//        delete pile; // rajout de ligne
//        return;
//    }
//    std::cout << pile->top() << std::endl;
//    // 4.
//    (*pile).pop();
//    std::cout << pile->top() << std::endl;
//
//    delete pile; // rajout de ligne
//}

void test(std::string ch1, std::string ch2) {
    Pile pile;

    pile.push(ch1);
    // 3.
    pile.push(ch2);
    if (pile.top() == "") {
        std::cout << "Pile vide" << std::endl;
        return;
    }
    std::cout << pile.top() << std::endl;
    // 4.
    pile.pop();
    std::cout << pile.top() << std::endl;
}