#include <cassert>
#include <iostream>
#include "pile.hh"

Pile::Pile(size_t max_size) : m_max_size(max_size), m_elements(new std::string[max_size]), m_top(m_elements) {}

Pile::~Pile() {
    delete[] m_elements;
}

bool Pile::empty() const {
    return m_top == m_elements;
}

bool Pile::full() const {
    return m_top == m_elements + m_max_size;
}

void Pile::push(std::string valeur) {
    assert(!full());
    *m_top = valeur;
    m_top++;
}

void Pile::pop() {
    assert(!empty());
    m_top--;

}

std::string Pile::top() const {
    assert(!empty());
    return *(m_top - 1);
}

void Pile::afficher() const {
    for (size_t i = m_max_size; i >= 0; i--) {
        std::cout << m_elements[i] << std::endl;
    }
}
