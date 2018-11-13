#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

#include "../Colisiones/OpenHashMap.h"
//#include "../HashMap/HashMapLista.h"

using namespace std;



int main() {
//ofstream = salida
//ifstream = entrada

    string palabra;
    string convertida;



    ifstream fe("../../diccionario2.txt");

    OpenHashMap <string, string> hm(5000);

    fe >> palabra;
    fe >> convertida;

    while (!fe.eof()) {

        hm.put(palabra, convertida);
        fe >> palabra;
        fe >> convertida;
    }


    fe.close();


    ifstream despacito("../../Datos.txt");
    ofstream entrega("../../Pepito.txt");

    int b,k;
    string linea;
    string palabras[100];

    while (!despacito.eof()){


        getline(despacito,linea);


        b=0;
        k=0;


        for (int i = 0; i < linea.length()+1 ; ++i) {
            if (linea[i] == ' ' || linea[i] == '\n' || linea[i] == ','|| linea[i] == '\0' ){
                palabras[b] = linea.substr(k, i-k);
                b++;
                k=i+1;
            }
        }

        for (int j = 0; j < b; ++j) {
            if(palabras[j].length()){
                size_t inicio = linea.find(palabras[j]);
                linea.replace(inicio, palabras[j].length(), hm.get(palabras[j]));
            }
        }

        entrega<<linea<<endl;


    }


    return 0;


}