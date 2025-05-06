#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;
#include "Persona.h"

class Empleado: public Persona{
private:
    string codigo;
public:
    Empleado(string n, int e, float s, string mail, string c): Persona(n, e, s, mail), codigo(c) {}

    void mostrarEmpleado(){
        cout<<"Atributos Empleado: "<<endl;
        cout<<"     Código: "<<codigo<<endl;
        mostrarPersona();
    }
    void setEmail(string nuevo){
        email=nuevo;
        cout<<"     --> Nuevo email para EMPLEADO: "<<email<<" <--     "<<endl;
    }
};
#endif