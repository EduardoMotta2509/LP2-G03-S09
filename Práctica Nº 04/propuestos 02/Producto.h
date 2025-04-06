#ifndef PRODUCTO_H
#define PRODUCTO_H

using namespace std;
#include <iostream>

class Producto {
private:
    string codigo;
    string descripcion;
    string proveedor;
    float precio;
public:
    Producto(string _codigo, string _descripcion, string _proveedor, float _precio) : codigo(_codigo), descripcion(_descripcion), proveedor(_proveedor), precio(_precio) {}

    float getPrecio(){ return precio; }

    void mostrarProducto(){
        cout<<"PRODUCTO: "<<descripcion<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"Código: "<<codigo<<endl;
        cout<<"Proveedor: "<<proveedor<<endl;
    }

};
#endif