#ifndef DOCENTE_H
#define DOCENTE_H

#include <iostream>
#include <string>
using namespace std;

class Docente {
private:
    string nombre;
    string especialidad;
public:
    Docente(string n, string e) : nombre(n), especialidad(e) {}
    void mostrarInfo() {
        cout << "Docente: " << nombre << ", Especialidad: " << especialidad << endl;
    }
};

#endif