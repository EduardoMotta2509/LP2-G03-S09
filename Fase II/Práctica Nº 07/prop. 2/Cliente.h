#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;
#include "Persona.h"

class Cliente: public Persona{
private:
    string DNI;
public:
    Cliente(string n, int e, float s, string mail, string dni): Persona(n, e, s, mail), DNI(dni) {}

    void mostrarCliente(){
        cout<<"Atributos Cliente: "<<endl;
        cout<<"        DNI: "<<DNI<<endl;
        mostrarPersona();
    }
    void setEmail(string nuevo){
        email=nuevo;
        cout<<"     --> Nuevo email para CLIENTE: "<<email<<" <--     "<<endl;
    }
};
#endif