#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Persona {
private:
    char nombre[50];
    int edad;
    char direccion[100];

public:
    Persona() {
        strcpy(nombre, "");
        edad = 0;
        strcpy(direccion, "");
    }

    Persona(string n, int e, string d) {
        strncpy(nombre, n.c_str(), sizeof(nombre) - 1);
        nombre[sizeof(nombre) - 1] = '\0';

        edad = e;

        strncpy(direccion, d.c_str(), sizeof(direccion) - 1);
        direccion[sizeof(direccion) - 1] = '\0';
    }

    void guardar(const char* archivoNombre) {
        ofstream archivo(archivoNombre, ios::out | ios::binary);
        if (archivo) {
            archivo.write(reinterpret_cast<char*>(this), sizeof(Persona));
            archivo.close();
        }
    }

    void cargar(const char* archivoNombre) {
        ifstream archivo(archivoNombre, ios::in | ios::binary);
        if (archivo) {
            archivo.read(reinterpret_cast<char*>(this), sizeof(Persona));
            archivo.close();
        }
    }

    void mostrar() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Dirección: " << direccion << endl;
    }
};

#endif
