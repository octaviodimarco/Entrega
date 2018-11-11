#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include <list>

#include "../../U03_Pilas/Pila/nodo.h"

using namespace std;

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(unsigned int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(unsigned int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void print();

    void fnInvierte();


};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = nullptr;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() { return inicio == nullptr; }


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    int cant = 0;
    nodo<T> *aux = inicio;

    while (aux != nullptr) {
        cant++;
        aux = aux->getNext();
    }
    return cant;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(unsigned int pos, T dato) {
    auto *nuevo = new nodo<T>();
    nodo<T> *aux = inicio;
    int pos_actual = 0;

    nuevo->setDato(dato);

    if (pos == 0) {
        nuevo->setNext(inicio);
        inicio = nuevo;
        return;
    }

    while (pos_actual < pos - 1 && aux != nullptr) {
        pos_actual++;
        aux = aux->getNext();
    }

    if (aux == nullptr)
        throw 1;

    nuevo->setNext(aux->getNext());
    aux->setNext(nuevo);
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    auto *nuevo = new nodo<T>();
    nuevo->setDato(dato);

    nuevo->setNext(inicio);
    inicio = nuevo;
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    auto *nuevo = new nodo<T>();
    auto *aux = inicio;

    nuevo->setDato(dato);
    nuevo->setNext(nullptr);

    if (aux == nullptr) {
        inicio = nuevo;
        return;
    }

    while (aux->getNext() != nullptr) {
        aux = aux->getNext();
    }

    aux->setNext(nuevo);
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(unsigned int pos) {
    auto *aux = inicio;

    while (pos > 1 && aux != nullptr) {
        pos--;
        aux = aux->getNext();
    }

    // Error no extiste el nodo (me pase)
    if (aux == nullptr)
        throw 1;

    if (pos == 0) { // si elimino el primer nodo.
        inicio = inicio->getNext();
        delete aux;
    } else { // todos los otros casos.
        auto *siguiente = aux->getNext();
        if (siguiente == nullptr) // Caso particular un solo elemento con borrar pos=1
            throw 2;

        aux->setNext(siguiente->getNext());
        delete siguiente;
    }
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    auto *aux = inicio;

    while (pos > 0 && aux != nullptr) {
        pos--;
        aux = aux->getNext();
    }

    if (aux == nullptr)
        throw 1;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    auto *aux = inicio;

    while (pos > 0 && aux != nullptr) {
        pos--;
        aux = aux->getNext();
    }

    if (aux == nullptr)
        throw 1;

    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {}


template<class T>
void Lista<T>::print() {
    auto *aux = inicio;

    while (aux != nullptr) {
        cout << aux->getDato()<<" _ ";
        aux = aux->getNext();
    }
}









#endif //LISTA_H