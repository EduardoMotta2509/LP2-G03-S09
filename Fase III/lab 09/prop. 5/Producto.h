#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

class Producto{
protected:
    string nombre;
    float precio;
    string medida;
    int stock;

public:
    static int totalCategorias;
    
    Producto(string _nombre, float _precio, string _medida, int _stock): nombre(_nombre), precio(_precio), medida(_medida), stock(_stock) {
        totalCategorias++;
    }

    static int getTotalCategorias(){
        return totalCategorias;
    }
    static void setTotalCategorias(int newTotal){
        totalCategorias=newTotal;
    }

    virtual float calcularPrecioInventario() = 0;
    virtual float aplicarDescuento(int cantidadSolicitada) = 0;
    virtual void mostrarInfo(){
        cout<<"\n";
        cout<<"Informacion del producto:"<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"Stock: "<<stock<<" "<<medida<<endl;
    }
    ~Producto(){}
};
#endif