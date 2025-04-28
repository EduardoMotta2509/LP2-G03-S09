#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>
#include "Contrato.h" // Incluye la clase Contrato

using namespace std;

// Clase Empleado
class Empleado {
private:
    string nombre;
    Contrato contrato; 
public:
    Empleado(const string& nom, const Contrato& cont)
        : nombre(nom), contrato(cont) {}
    void mostrarEmpleado() const {
        cout << "Nombre del Empleado: " << nombre << endl;
        cout << "Información del Contrato: ";
        contrato.mostrarContrato();
        cout << endl;
    }
};

#endif