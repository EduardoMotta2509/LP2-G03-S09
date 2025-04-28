#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>
using namespace std;

class Direccion{
private:
    string distrito;
    string calle;
    string numero;
public:
    Direccion(string d, string c, string n):distrito(d),calle(c),numero(n){
        cout<<"Constructor invocado para direccion."<<endl;
    }

    void mostrarDireccion(){
        cout<<"Dirección: "<<distrito<<", "<<calle<<" - "<<numero<<endl;
    }

    ~Direccion(){
        cout<<"Destructor invocado para direccion." <<endl;
    }

};
#endif