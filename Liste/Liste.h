//
// Created by Mael Kerichard on 04/03/2022.
//

#ifndef LISTE_LISTE_H
#define LISTE_LISTE_H

#include <cstdio>
#include <cassert>
#include <ostream>
#include <iostream>
#include "cyclicNode.h"

template<typename T>
class Liste {
protected:
    typedef DataStructure::cyclicNode<T> Chainon;

public:
    explicit Liste() : m_size(0) {}

    /**
     * Check if the list is empty
     * @return true if the list is empty
     */
    bool empty() const {
        return m_size == 0;
    }

    /**
     * Get the size of the list
     * @return the size of the list
     */
    size_t size() const {
        return m_size;
    }

    /**
     * Get the first element of the list
     * @return the first element of the list
     * @pre the list is not empty
     */
    T &front() const {
        assert(!empty());
        return m_list->data();
    }

    /**
     * Get the last element of the list
     * @return the last element of the list
     * @pre the list is not empty
     */
    T &back() const {
        assert(!empty());
        return m_list->previous()->data();
    }

    /**
 * Get the first element of the list
 * @return the first element of the list
 * @pre the list is not empty
 */
    T &front() {
        assert(!empty());
        return m_list->data();
    }

    /**
     * Get the last element of the list
     * @return the last element of the list
     * @pre the list is not empty
     */
    T &back() {
        assert(!empty());
        return m_list->previous()->data();
    }

    /**
     * Add an element at the beginning of the list
     * @param element the element to add
     */
    void push_front(const T &element) {
        auto newNode = new Chainon(element);
        if (empty()) {
            m_list = newNode;
        } else {
            newNode->insertAfter(m_list);
            m_list = newNode;
        }
        m_size++;
    }

    /**
     * Add an element at the end of the list
     * @param element the element to add
     */
    void push_back(const T &element) {
        auto newNode = new Chainon(element);
        if (empty()) {
            m_list = newNode;
        } else {
            m_list->previous()->insertAfter(newNode);
        }
        m_size++;
    }

    /**
     * Remove the first element of the list
     * @pre the list is not empty
     */
    void pop_front() {
        assert(!empty());
        auto temp = m_list->next();
        m_list->detach();
        m_list = temp;
        m_size--;
    }

    /**
     * Remove the last element of the list
     * @pre the list is not empty
     */
    void pop_back() {
        assert(!empty());
        m_list->previous()->detach();
        m_size--;
    }

    friend std::ostream &operator<<(std::ostream &os, const Liste &liste) {
        os << "[";
        auto current_list = liste.m_list;
        for (int i = 0; i < liste.size(); ++i) {
            os << current_list->data();
            if (i < liste.size() - 1) {
                os << ", ";
            }
            current_list = current_list->next();
        }
        os << "]";
        return os;
    }

    /**
     * Destructor of the list
     */
    virtual ~Liste() {
        for (int i = 0; i < m_size; ++i) {
            auto temp = m_list;
            pop_front();
            delete temp;
        }
        delete m_list;
    }


    class const_iterator {
    private:
        friend class Liste<T>;

        Chainon *liste;
        size_t index;
        size_t size;

        explicit const_iterator(Chainon *liste, size_t size, size_t index) : liste(liste), index(index), size(size) {}

    public:

        /**
         * opérateur ++ préfixé
        * positionne l ' itérateur sur l 'élément suivant
        * @pre l ' itérateur désigne une position valide dans la liste (!= end()) * @return nouvelle valeur de l ' itérateur
        */
        const_iterator &operator++() {
            assert(index != size);
            liste = liste->next();
            index++;
            return *this;
        }

        /** opérateur −− préfixé
        * positionne l ' itérateur sur l 'élément précédent
        * @pre l ' itérateur ne désigne pas l 'élément de tête (!= begin()) * @return nouvelle valeur de l ' itérateur
        */
        const_iterator &operator--() {
            assert(index != 0);
            liste = liste->previous();
            index--;
            return *this;
        }

        /** opérateur d'indirection * (accès NON modifiable)
        * @pre l ' itérateur désigne une position valide dans la liste (!= end())
        * @return valeur de l 'élément désigné par l ' itérateur
        */
        const T &operator*() const {
            assert(index != size);
            return liste->data();

        }

        /** opérateur d'indirection −> (accès NON modifiable)
        * @pre l ' itérateur désigne une position valide (!= end())
        * @return adresse de l 'élément désigné par l ' itérateur
        */
        const T *operator->() const {
            assert(index != size);
            return liste->data();
        }

        bool operator==(const const_iterator &other) {
            return this->liste == other.liste && this->index == other.index;
        }


        bool operator!=(const const_iterator &other) {
            return this->liste != other.liste || this->index != other.index;
        }

    };

    class iterator {
    private:
        friend class Liste<T>;

        Chainon *liste;
        size_t index;
        size_t size;

        explicit iterator(Chainon *liste, size_t size, size_t index) : liste(liste), index(index), size(size) {}

    public:

        /**
         * opérateur ++ préfixé
        * positionne l ' itérateur sur l 'élément suivant
        * @pre l ' itérateur désigne une position valide dans la liste (!= end()) * @return nouvelle valeur de l ' itérateur
        */
        iterator &operator++() {
            assert(index != size);
            liste = liste->next();
            index++;
            return *this;
        }

        /** opérateur −− préfixé
        * positionne l ' itérateur sur l 'élément précédent
        * @pre l ' itérateur ne désigne pas l 'élément de tête (!= begin()) * @return nouvelle valeur de l ' itérateur
        */
        iterator &operator--() {
            assert(index != 0);
            liste = liste->previous();
            index--;
            return *this;
        }

        /** opérateur d'indirection *
        * @pre l ' itérateur désigne une position valide dans la liste (!= end())
        * @return valeur de l 'élément désigné par l ' itérateur
        */
        T &operator*() {
            assert(index != size);
            return liste->data();

        }

        /** opérateur d'indirection −>
        * @pre l ' itérateur désigne une position valide (!= end())
        * @return adresse de l 'élément désigné par l ' itérateur
        */
        T *operator->() {
            assert(index != size);
            return liste->data();
        }

        bool operator==(const iterator &other) {
            return this->liste == other.liste && this->index == other.index;
        }


        bool operator!=(const iterator &other) {
            return this->liste != other.liste || this->index != other.index;
        }
    };


    /**
     * @return un itérateur sur le début de liste cet itérateur désigne le premier élément de la liste si elle n'est pas vide ; sinon , il désigne la même position que l 'itérateur renvoyé par end()
     */
    const_iterator begin() const {
        return const_iterator(m_list, m_size, 0);
    }

    /**
     * @return renvoie un itérateur qui désigne une position située après le dernier élément
     */
    const_iterator end() const {
        return const_iterator(m_list, m_size, m_size);
    }

    /**
 * @return un itérateur sur le début de liste cet itérateur désigne le premier élément de la liste si elle n'est pas vide ; sinon , il désigne la même position que l 'itérateur renvoyé par end()
 */
    iterator begin()  {
        return iterator(m_list, m_size, 0);
    }

    /**
     * @return renvoie un itérateur qui désigne une position située après le dernier élément
     */
    iterator end() {
        return iterator(m_list, m_size, m_size);
    }


private:
    Chainon *m_list;
    int m_size;
};

#endif //LISTE_LISTE_H
