#ifndef CONTRATO_H
#define CONTRATO_H

#include <iostream>
#include <string>
#include "Fecha.h" // Incluye la clase Fecha

using namespace std;

// Clase Contrato
class Contrato {
private:
    int codigo;
    string descripcion;
    Fecha fechaInicio; 
public:
    Contrato(int cod, const string& desc, const Fecha& fecha)
        : codigo(cod), descripcion(desc), fechaInicio(fecha) {}
    void mostrarContrato() const {
        cout << "Código: " << codigo << ", Descripción: " << descripcion << ", Fecha de Inicio: ";
        fechaInicio.mostrar();
    }
};

#endif 