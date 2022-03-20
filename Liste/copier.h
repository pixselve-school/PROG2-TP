/**
   3.2.1 chercher une valeur dans une liste triée
   @param l : liste où se fait la recherche
   @param x : valeur à chercher
   @return position du premier élément de valeur >= x
   ou end() si un tel élément n'existe pas
 */
template<class T>
typename Liste<T>::iterator chercherTri(typename Liste<T>::iterator begin, typename Liste<T>::iterator end, const T &x) {
    while (begin != end && *begin < x) {
        ++begin;
    }
    return begin;
}


/**
   3.2.2 créer une copie triée par valeurs croissantes d'une liste
   @param l : liste à copier
   @return liste triée
*/
template<class T>
Liste<T> * copierTri(const Liste<T> &l) {
    auto * copie = new Liste<T>();
    for (auto iterator = l.begin(); iterator != l.end(); ++iterator) {
        auto element = *iterator;
        copie->insert(chercherTri(copie->begin(), copie->end(), element), element);
    }
    return copie;
}