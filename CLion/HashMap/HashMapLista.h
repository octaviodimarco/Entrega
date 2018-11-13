#ifndef HASHMAPLISTA_H
#define HASHMAPLISTA_H
#include "../Lista/Lista.h"
template<class K, class T>
class HashMap {
private:
    unsigned int hashFunc(K clave);

    static unsigned int hashFuncDefault(K clave) { return 0; };

    unsigned int (*hashFuncP)(K clave);

    unsigned int tam;

    Lista<HashEntry<K,T>> *tabla;

public:
    HashMap(unsigned int k);

    HashMap(unsigned int k, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool esVacio();


};

//template<class K, class T>
//HashMap<K, T>::HashMap(unsigned int k) {
//    datos = new T *[k];
//    tam = k;
//
//    hashFuncP = this->hashFuncDefault;
//
//    for (int i = 0; i < k; ++i)
//        datos[i] = nullptr;
//
//}
//
//
//template<class K, class T>
//HashMap<K, T>::HashMap(unsigned int k, unsigned int (*fp)(K)) {
//    datos = new T *[k];
//    tam = k;
//    hashFuncP = fp;  //Puntero de funcion, basicamente le da otro nombre a una funcion
//    for (int i = 0; i < k; ++i)
//        datos[i] = nullptr;
//
//}

template<class K, class T>
HashMap

template<class K, class T>
HashMap<K, T>::~HashMap() {
    for (int i = 0; i < tam; ++i)
        if (datos[i] != nullptr)
            delete datos[i];
}

template<class K, class T>
T HashMap<K, T>::get(K clave) {

    unsigned int idx = hashFunc(clave);

    if (datos[idx] == nullptr)
        throw 404;

    return *datos[idx]; //Devuelvo el contenido
}

template<class K, class T>
void HashMap<K, T>::put(K clave, T valor) {

    unsigned int idx = hashFunc(clave);

    if (datos[idx] != nullptr) //Este es el caso en que haya colision
        throw 1;

    datos[idx] = new T;
    *datos[idx] = valor; // El contenido del array es lo que tengo que guardar

}

template<class K, class T>
void HashMap<K, T>::remove(K clave) {//
// Created by octaviodimarco on 11/11/18.
//

#ifndef CLION_OPENHASHMAP_H
#define CLION_OPENHASHMAP_H

#include "../HashMap/HashEntry.h"
#include "../Lista/Lista.h"

template<class K, class T>
class OpenHashMap {
private:
    Lista<HashEntry<K, T>> *tabla;

    unsigned int size;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    OpenHashMap(unsigned int);

    OpenHashMap(unsigned int, unsigned int (*)(K));

    ~OpenHashMap();

    void put(K, T);

    T get(K);

    void remove(K);

    bool esVacio();
};

template<class K, class T>
OpenHashMap<K, T>::OpenHashMap(unsigned int m) : size(m), hashFuncP(hashFunc) {
    tabla = new Lista<HashEntry<K, T>>[m];  //inicializar listas con constructor por defecto?
}

template<class K, class T>
OpenHashMap<K, T>::OpenHashMap(unsigned int tam, unsigned int (*fp)(K)) : size(tam), hashFuncP(fp) {
    tabla = new Lista<HashEntry<K, T>>[tam];
}

template<class K, class T>
OpenHashMap<K, T>::~OpenHashMap() {
    for (int i = 0; i < size; ++i)
        tabla[i].vaciar();
    delete tabla;
}

template<class K, class T>
void OpenHashMap<K, T>::put(K clave, T elemento) {
    tabla[hashFunc(clave) % size].insertarUltimo({clave, elemento});
}

template<class K, class T>
T OpenHashMap<K, T>::get(K clave) {
    Lista<HashEntry<K, T>> *aux = &tabla[hashFunc(clave)];
    for (int i = 0; i < aux->getTamanio(); ++i)   //ya recorrio una vez la lista :(
        if (aux->getDato(i).getKey() == clave)
            return aux->getDato(i);
    throw -1;
}

template<class K, class T>
void OpenHashMap<K, T>::remove(K clave) {
    Lista<HashEntry<K, T>> *aux = &tabla[hashFunc(clave)];
    for (int i = 0; i < aux->getTamanio(); ++i)
        if (aux->getDato(i).getKey() == clave)
            aux->remover(i);
    throw -1;
}

template<class K, class T>
bool OpenHashMap<K, T>::esVacio() {
    return size == 0;
}

template<class K, class T>
unsigned int OpenHashMap<K, T>::hashFunc(K clave) {
    return (unsigned int) clave;
}


#endif //CLION_OPENHASHMAP_H


    unsigned int idx = hashFunc(clave);

    if (datos[idx] == nullptr)
        throw 404;

    delete datos[idx];

}

template<class K, class T>
bool HashMap<K, T>::esVacio() {
    return false;
}

template<class K, class T>
unsigned int HashMap<K, T>::hashFunc(K clave) {
    return hashFuncP(clave) % tam; //Esta funcion asegura que no mme pase del tamaño
}


#endif //HASHMAP_H