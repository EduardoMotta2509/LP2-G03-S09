#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int cantidad;

public:
    Producto(string _nombre = "", double _precio = 0, int _cantidad = 0) {
        nombre = _nombre;
        precio = _precio;
        cantidad = _cantidad;
    }

    void setPrecio(double _precio) {
        if (_precio >= 0) {
            precio = _precio;
        }
    }

    void setCantidad(int _cantidad) {
        if (_cantidad >= 0) {
            cantidad = _cantidad;
        }
    }

    string getNombre() {
        return nombre;
    }

    double getPrecio() {
        return precio;
    }

    int getCantidad() {
        return cantidad;
    }

    bool reducirStock(int cantidadVendida) {
        if (cantidadVendida > 0 && cantidadVendida <= cantidad) {
            cantidad -= cantidadVendida;
            return true;
        }
        return false;
    }
};

class Factura {
private:
    Producto productos[3];
    double total;
    int indice;

public:
    Factura() {
        total = 0;
        indice = 0;
    }

    void agregarProducto(Producto &producto, int cantidadComprada) {
        if (indice < 3) {
            if (producto.reducirStock(cantidadComprada)) {
                productos[indice] = Producto(producto.getNombre(), producto.getPrecio(), cantidadComprada);
                total += producto.getPrecio() * cantidadComprada;
                indice++;
            } else {
                cout << "No hay suficiente stock de " << producto.getNombre() << ".\n";
            }
        } else {
            cout << "No se pueden agregar más productos a la factura.\n";
        }
    }

    void aplicarDescuento(double porcentaje) {
        if (porcentaje > 0 && porcentaje <= 100) {
            total -= (total * porcentaje / 100);
        }
    }

    void aplicarImpuesto(double porcentaje) {
        if (porcentaje > 0) {
            total += (total * porcentaje / 100);
        }
    }

    void mostrarFactura() {
        cout << "\n--- Factura ---\n";
        for (int i = 0; i < indice; i++) {
            cout << productos[i].getNombre() << " x" << productos[i].getCantidad() 
                 << " - S/ " << productos[i].getPrecio() * productos[i].getCantidad() << "\n";
        }
        cout << "Total: S/ " << total << "\n";
    }
};

int main() {
    string nombre;
    int precio;
    int cantidad;
    Producto p1("Laptop", 3000, 5);
    Producto p2("Mouse", 50, 10);
    Producto p3("Teclado", 100, 7);

    Factura factura;
    factura.agregarProducto(p1, 1);
    factura.agregarProducto(p2, 2);
    factura.agregarProducto(p3, 1);

    factura.aplicarDescuento(10);
    factura.aplicarImpuesto(18);
    factura.mostrarFactura();

    return 0;
}