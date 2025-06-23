#ifndef ARCHIVO_TEXTO_H
#define ARCHIVO_TEXTO_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool mostrarContenidoArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
    return true;
}

#endif
