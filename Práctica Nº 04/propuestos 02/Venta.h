#ifndef VENTA_H
#define VENTA_H

#include <iostream>
using namespace std;
#include "Producto.h"
#include "Cliente.h"
#include <vector>

class Venta{
private:
    string nroFactura;
    string fecha;
    Cliente* cliente;
    vector<Producto> listaProdVendidos;
    vector<int> listaCantXProd;
    float total = 0;
public:
    Venta(string _nroFactura, string _fecha, Cliente* _cliente, vector<Producto> _listaProdVendidos, vector<int> _listaCantXProd) : nroFactura(_nroFactura), fecha(_fecha), cliente(_cliente), listaProdVendidos(_listaProdVendidos), listaCantXProd(_listaCantXProd) {}

    void calcularPrecioTotal(){
        for (int i=0; i<listaProdVendidos.size(); i++) {
            float precioTotal = (listaProdVendidos[i].getPrecio())*(listaCantXProd[i]);
            total = precioTotal;
        }
    }

    float getTotal() {return total; }

};
#endif

