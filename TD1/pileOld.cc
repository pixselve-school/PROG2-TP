#include <cassert>
#include <iostream>
#include "pile.hh"

Pile::Pile() : m_max_size(10), m_size(0) {
    m_elements = new std::string[m_max_size];
}

Pile::~Pile() {
    delete[] m_elements;
}

bool Pile::empty() const {
    return m_size == 0;
}

bool Pile::full() const {
    return m_size == m_max_size;
}

void Pile::push(std::string valeur) {
    assert(!full());
    m_elements[m_size] = valeur;
    m_size++;
}

void Pile::pop() {
    assert(!empty());
    m_size--;
}

std::string Pile::top() const {
    assert(!empty());
    return m_elements[m_size - 1];
}

void Pile::afficher() const {
    for (int i = m_size; i >= 0; i--) {
        std::cout << m_elements[i] << std::endl;
    }
}
