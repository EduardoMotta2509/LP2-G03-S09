#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
using namespace std;

#include "Direccion.h"
#include "Gerente.h"

class Empresa{
private:
    Gerente gerente;
    Direccion direccion;
public:
    Empresa(string n, float s, string d, string c, string _n):gerente(n, s), direccion(d,c,_n){
        cout<<"Constructor invocado para empresa"<<endl;
    }

    ~Empresa(){
        cout<<"Destructor invocado para empresa" <<endl;
    }
};
#endif
