#include <iostream>
#include <fstream>
#include "../HashMap/HashMap.h"

using namespace std;

unsigned int sad(string clave) {
    int i=clave.length();

    unsigned int res=0;

    for (int j = 0; j < i; ++j) {
        res += clave[j]*clave[j]+(j+1);
    }

    return res;
}

int main() {
//ofstream = salida
//ifstream = entrada

    string palabra;
    string convertida;



    ifstream fe("../../Diccionario.txt");

    HashMap <string, string> hm(90, sad);

    while (!fe.eof()) {
        fe >> palabra;
        fe >> convertida;

        hm.put(palabra, convertida);
    }



    fe.close();
    return 0;


}