#include <iostream>
using namespace std;

class Producto {
private:
    string nombre;
    int stock;
public:
    Producto(string _nombre, int _stock) {
        nombre = _nombre;
        stock = _stock;
    }
    string getNombre() {
        return nombre;
    }
    int getStock() {
        return stock;
    }
    void reducirStock(int cantidad) {
        stock -= cantidad;
    }
};

class Inventario {
private:
    Producto productos[5] = {
        Producto("Manzana", 10),
        Producto("Banana", 8),
        Producto("Naranja", 5),
        Producto("Pera", 7),
        Producto("Uva", 4)
    };
public:
    void mostrarProductos() {
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << productos[i].getNombre() << " - Stock: " << productos[i].getStock() << endl;
        }
    }
    void realizarPedido(int indice, int cantidad) {
        if (indice >= 1 && indice <= 5 && productos[indice - 1].getStock() >= cantidad) {
            productos[indice - 1].reducirStock(cantidad);
            cout << "Pedido realizado: " << cantidad << " " << productos[indice - 1].getNombre() << "\n";
        } else {
            cout << "No hay suficiente stock o índice inválido.\n";
        }
    }
};

int main() {
    Inventario inventario;
    int opcion, cantidad;

    while (true) {
        cout << "\nINVENTARIO\n";
        inventario.mostrarProductos();
        cout << "Seleccione un producto del 1 al 5 para comprar o 0 para salir: ";
        cin >> opcion;
        if (opcion == 0) break;
        cout << "Ingrese la cantidad a comprar: ";
        cin >> cantidad;
        inventario.realizarPedido(opcion, cantidad);
    }

    return 0;
}