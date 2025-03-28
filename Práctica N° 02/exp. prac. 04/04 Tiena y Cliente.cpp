#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    int stock;  

public:
    Producto() {
        nombre = "";
        precio = 0.0;
        stock = 0;
    }
    
    
    Producto(string _nombre, double _precio, int _stock) {
        nombre = _nombre;
        precio = _precio;
        stock = _stock;
    }
    
    string getNombre() {
        return nombre;
    }
    
    double getPrecio() {
        return precio;
    }
    
    int getStock() {
        return stock;
    }
    
   
    bool reducirStock(int cantidadVendida) {
        if (cantidadVendida > 0 && cantidadVendida <= stock) {
            stock -= cantidadVendida;
            return true;
        }
        return false;
    }
};

class Tienda {
private:
    Producto productos[5];  

public:
    Tienda() : productos{
        Producto("Manzana", 1.50, 10),
        Producto("Leche", 2.00, 5),
        Producto("Pan", 1.00, 20),
        Producto("Huevos", 3.00, 15),
        Producto("Queso", 4.00, 8)
    } {}
    
    void mostrarProductos() {
        cout << "\nProductos disponibles:\n";
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << productos[i].getNombre() 
                 << " - Precio: $" << productos[i].getPrecio() 
                 << " - Stock: " << productos[i].getStock() << "\n";
        }
    }
    
    Producto& obtenerProducto(int indice) {
        if (indice >= 1 && indice <= 5) {
            return productos[indice - 1];
        } else {
            cout << "Índice inválido, se retorna el primer producto.\n";
            return productos[0];
        }
    }
};

class Cliente {
private:
    string nombre;
    Producto compras[10]; 
    int numCompras;       

public:
    Cliente(string _nombre) {
        nombre = _nombre;
        numCompras = 0;
    }
    
    void agregarProducto(Tienda &tienda, int indice, int cantidad) {
        Producto &prod = tienda.obtenerProducto(indice);
        if (prod.reducirStock(cantidad)) {
            if (numCompras < 10) {
                compras[numCompras] = Producto(prod.getNombre(), prod.getPrecio(), cantidad);
                numCompras++;
                cout << nombre << " ha agregado " << cantidad << " unidad(es) de " 
                     << prod.getNombre() << " a su carrito.\n";
            } else {
                cout << "El carrito está lleno.\n";
            }
        } else {
            cout << "No hay suficiente stock de " << prod.getNombre() << ".\n";
        }
    }
    
    void pagarCuenta() {
        double total = 0.0;
        cout << "\n--- Factura de " << nombre << " ---\n";
        for (int i = 0; i < numCompras; i++) {
            double subtotal = compras[i].getPrecio() * compras[i].getStock();
            cout << compras[i].getNombre() << " x" << compras[i].getStock() 
                 << " - Subtotal: $" << subtotal << "\n";
            total += subtotal;
        }
        cout << "Total a pagar: $" << total << "\n";
    }
};

int main() {
    Tienda tienda;
    Cliente cliente("Jose");
    
    int opcion, indice, cantidad;
    
    do {
        cout << "\nMenú:\n";
        cout << "1. Ver productos\n";
        cout << "2. Agregar producto al carrito\n";
        cout << "3. Pagar\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                tienda.mostrarProductos();
                break;
            case 2:
                cout << "Ingrese el número del producto: ";
                cin >> indice;
                cout << "Ingrese la cantidad a comprar: ";
                cin >> cantidad;
                cliente.agregarProducto(tienda, indice, cantidad);
                break;
            case 3:
                cliente.pagarCuenta();
                break;
            case 4:
                cout << "Gracias por su compra.\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 4);
    
    return 0;
}