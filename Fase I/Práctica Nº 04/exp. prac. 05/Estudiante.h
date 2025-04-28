#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    int id;
public:
    Estudiante(string n, int i) : nombre(n), id(i) {}

    int getId() const {
        return id;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    string getNombre() const {
        return nombre;
    }

    void mostrarInfo() const {
        cout << "Estudiante: " << nombre << " (ID: " << id << ")" << endl;
    }
};

#endif
