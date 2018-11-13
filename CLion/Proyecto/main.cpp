#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

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

int main() {
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

    cout<<"La clave de presente es "<<hm.get("casa")<<endl;

    fe.close();


    ifstream despacito("../../Datos.txt");
    ofstream entrega("../../Pepito.txt");

    int b,k;
    string linea;
    string palabras[100];

        while (!despacito.eof()){

//       despacito>>palabra;
            getline(despacito,linea);
           // palabras = new string[linea.length()/2];

            b=0;
            k=0;
            int j=0;
            //linea[linea.length()]='\0';




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

//                    entrega<<hm.get(palabra);
//                    entrega<<" ";
        }

//            for (int i = 0; i < palabra.length() ; ++i) {
//                if (palabra[i] == a[0])
//
//            }
//
    return 0;


}