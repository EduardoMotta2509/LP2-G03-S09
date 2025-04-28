#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;

#include "Direccion.h"
#include "FechaRegistro.h"

class Cliente{
private:
    string nombre;
    Direccion direccion;
    FechaRegistro fechaRegistro;
public:
    //Constructor con un parámetro
    Cliente(string n, string _d, string c, string _n, int d, int m, int a) : nombre(n), direccion(_d,c,_n), fechaRegistro(d,m,a){}
    
    void mostrarCliente(){
        cout<<"Datos del cliente: "<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        direccion.mostrarDireccion();
        fechaRegistro.mostrarFechaRegistro();
        
    }
};
#endif
