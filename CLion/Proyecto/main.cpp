#include <iostream>
#include <fstream>

#include "../Colisiones/OpenHashMap.h"
//#include "../HashMap/HashMapLista.h"

using namespace std;

unsigned int sad(string clave) {
    unsigned int i=clave.length();

    unsigned int res=0;

    for (int j = 0; j < i; ++j) {
        res += clave[j]*clave[j]+(j+1);
    }

    return res;
}

int main(argc,argv) {
//ofstream = salida
//ifstream = entrada

    string palabra;
    string convertida;



    ifstream fe("../../Diccionario.txt");

    OpenHashMap <string, string> hm(2);

    fe >> palabra;
    fe >> convertida;

    while (!fe.eof()) {

        cout<<palabra<<"    "<<convertida<<endl;

        hm.put(palabra, convertida);
        fe >> palabra;
        fe >> convertida;
    }

    cout<<"La clave de presente es "<<hm.get("la")<<endl;

    fe.close();
    return 0;


}