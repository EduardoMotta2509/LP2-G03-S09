#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

class Producto{
private:
    string nombre;
    float precio;
    float descuento;
public:
    Producto() : nombre(""), precio(0.0), descuento(0.0) {}

    Producto& setNombre(string n){
        this->nombre=n;
        return *this;
    }
    Producto& setPrecio(float p){
        this->precio=p;
        return *this;
    }
    Producto& setDescuento(float d){
        this->descuento=d;
        return *this;
    }

    float calcularPrecioFinal(){
        float precioFinal=precio-(precio*descuento);
        return precioFinal;
    }

};
#endif
