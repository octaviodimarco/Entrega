//
// Created by octaviodimarco on 29/08/18.
//

#ifndef PROGRAMACION3_NODO_H
#define PROGRAMACION3_NODO_H

template<class T>

class nodo {
private:
    T dato;
public:
    nodo *getNext() const {
        return next;
    }

    void setNext(nodo *next) {
        nodo::next = next;
    }

private:
    nodo *next; //El puntero apunta al siguiente nodo
public:
    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        nodo::dato = dato;
    }
};


#endif //PROGRAMACION3_NODO_H
