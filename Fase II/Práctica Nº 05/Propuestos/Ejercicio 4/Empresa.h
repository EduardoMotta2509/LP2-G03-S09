#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
using namespace std;

#include "Gerente.h"
#include "Direccion.h"

class Empresa{
private:
    Gerente gerente;
    Direccion direccion;
public:
    Empresa(string nombreG, float salarioG, string d, string c, string n): gerente(nombreG, salarioG), direccion(d,c,n) {
        cout<<"Constructor invocado para la EMPRESA. " <<endl;
    }

    ~Empresa(){
        cout<<"Destructor invocado para la EMPRESA. " <<endl;
    }

};
#endif
