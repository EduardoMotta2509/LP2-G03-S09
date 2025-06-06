#include <iostream>
using namespace std;
#include <vector>

#include "Producto.h"
#include "Electronicos.h"
#include "Ropa.h"

int Producto::totalCategorias = 0;

float infoUniversal(vector<Producto*> preciosInventarios){
    float precioTotal;
    for (int i=0; i<preciosInventarios.size(); i++ ) {
        precioTotal = precioTotal + preciosInventarios[i]->calcularPrecioInventario();
    }
    cout<<"\n";
    cout<<"Hay "<<Producto::getTotalCategorias()<<" categorias de productos"<<endl;
    cout<<"El precio de todos los productos de la tienda es S/."<<precioTotal<<endl;
    cout<<"\n";
    return precioTotal;
};

int main(){
    Electronicos Motherboards("ROG STRIX B860-A GAMING WIFI", 800.90, "unidades", 50, 1.186, "alta", true);
    Ropa buzos("Black Baggy", 59.90, "prendas", 200, "varon", "M", true, "adulto", false);

    Motherboards.aplicarDescuento(51);
    buzos.aplicarDescuento(3);
    
    vector<Producto*> productos;
    productos.push_back(&Motherboards);
    productos.push_back(&buzos);
    
    Motherboards.mostrarInfo();
    buzos.mostrarInfo();
    
    infoUniversal(productos);
    
    return 0;
}

