#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class K, class T>
class HashEntry {
private:
    K clave;
    T valor;

public:
    HashEntry(K newclave, T newvalor);

    K getKey();

    T getValue();
};


template<class K, class T>
HashEntry<K, T>::HashEntry(K newclave, T newvalor) {
    clave = newclave;
    valor = newvalor;
}

template<class K, class T>
K HashEntry<K,T>::getKey() {
    return clave;
}

template<class K, class T>
T HashEntry<K,T>::getValue(){
    return valor;
}

#endif //HASHENTRY_H