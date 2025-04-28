#include <iostream>
using namespace std;

#include "Producto.h"

int main(){
    Producto p1;
    Producto p2;
    Producto p3;
    
    p1.setNombre("Casaca").setPrecio(149.90).setDescuento(0.5);
    p2.setNombre("Jean").setPrecio(89.90).setDescuento(0.25);
    p3.setNombre("Polo").setPrecio(39.90).setDescuento(0.15);
    // Declarar un arreglo estático de 3 objetos Producto
    float preciosFinales[3] = {
        p1.calcularPrecioFinal(),
        p2.calcularPrecioFinal(),
        p3.calcularPrecioFinal()
    };
    float totalAcumulado;
    // Recorrer el arreglo y sumar los precios finales
    for (int i = 0; i < 3; i++) {
        totalAcumulado = totalAcumulado + preciosFinales[i];
    }
    cout<<"El total acumulado es: "<<totalAcumulado;
    return 0;
}