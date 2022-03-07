//
// Created by accou on 07/03/2022.
//

#ifndef TD1_CHAINON_H
#define TD1_CHAINON_H

template<typename T>
class Chainon {
private:
    T value;
    const Chainon *previous;

public:
    const T &getValue() const {
        return value;
    }

    const Chainon *getPrevious() const {
        return previous;
    }

    explicit Chainon(const T & value, const Chainon *previous = nullptr);

};

template<typename T>
Chainon<T>::Chainon(const T & value, const Chainon *previous) : value(value), previous(previous) {}

#endif //TD1_CHAINON_H
