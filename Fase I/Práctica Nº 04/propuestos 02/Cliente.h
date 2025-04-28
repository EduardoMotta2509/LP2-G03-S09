#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;
#include <vector>

class Venta;

class Cliente {
private:
    string nombre;
    string direccion;
    string contacto;
    vector<Venta> listaCompras;
public:
    Cliente (string _nombre, string _direccion, string _contacto, vector<Venta> _listaCompras) : nombre(_nombre), direccion(_direccion), contacto(_contacto), listaCompras(_listaCompras) {}
    
    string getNombre(){ return nombre;}
    
    void añadirNuevaCompra(const Venta& nuevaCompra){
        listaCompras.push_back(nuevaCompra);
    }
};
#endif