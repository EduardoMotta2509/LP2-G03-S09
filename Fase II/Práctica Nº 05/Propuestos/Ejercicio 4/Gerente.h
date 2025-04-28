#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>
using namespace std;

class Gerente{
private:
    string nombre;
    float salario;
public:
    Gerente(string n, float s): nombre(n), salario(s){
        cout<<"Constructor invocado para: " << nombre << endl;
    }

    ~Gerente(){
        cout<<"Destructor invocado para: " << nombre << endl;
    }

};
#endif