#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <locale.h>



#include "../Colisiones/OpenHashMap.h"

using namespace std;


unsigned int sad(string clave) {
    unsigned int i = clave.length();

    unsigned int res = 0;

    for (int j = 0; j < i; ++j) {
        res += clave[j] * clave[j] + (j + 1);
    }

    return res;
}

int main(int argc, char *argv[]) {

    int l = 0;
    int c = 0;
    int o = 0;
    int d = 0;
    int ii = 0;
    if (argc != 8){
        cout<<"Se requieren mas elementos para seguir"<<endl;}
    else{
        for (int i = 0; i < argc; i ++) {
            if (argv[i][0] == '-'){
                if (argv[i][1] == 'c'){
                    cout<<"El archivo siguiente va a ser codificado"<<endl;
                    ifstream fe (argv[i + 1]);
                }
                else if (argv[i][1] == 'l'){
                    cout<<"El siguiente archivo será seleccionado como diccionario"<<endl;
                }
                else if (argv[i][1] == 'o'){
                    cout<<"El siguiente archivo será elegido como destino de texto"<<endl;
                }
                else if (argv[i][1] == 'd'){
                    cout<<"Se codificará el archivo de entrada"<<endl;
                }
                else if (argv[i][1] == 'i'){
                    cout<<"Archivo de texto a ser codificado o decodificado"<<endl;
                }}
            else
                cout << "mala" << endl;
        }

    setlocale(LC_ALL, "");


    string palabra;
    string convertida;


    ifstream fe("../../Diccionario3.txt");

    OpenHashMap<string, string> hm(5000);

    fe >> palabra;
    fe >> convertida;

    while (!fe.eof()) {


        hm.put(palabra, convertida);
        fe >> palabra;
        fe >> convertida;
    }

    fe.close();


    ifstream datos("../../Datos2.txt");
    ofstream entrega("../../Pepito.txt");

    int b, k;
    string linea;
    string palabras[1000];

    while (!datos.eof()) {

        getline(datos, linea);


        b = 0;
        k = 0;


        for (long i = 0; i < linea.length() + 1; ++i) {
            if (linea[i] == ' ' || linea[i] == '\n' || linea[i] == ',' || linea[i] == ')' || linea[i] == '('
                || linea[i] == '\0' || linea[i] == '"' || linea[i] == '.' || linea[i] == ';' || linea[i] == ':') {
                palabras[b] = linea.substr(k, i - k);

                b++;
                k = i + 1;
            }
        }

        for (int j = 0; j < b; ++j) {
            if (palabras[j].length()>0) {
                size_t inicio = linea.find(palabras[j]);

                linea.replace(inicio, palabras[j].length(), hm.get(palabras[j]));
            }
        }

        entrega << linea << endl;

    }

    return 0;


}}