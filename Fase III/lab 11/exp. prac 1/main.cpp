#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "Producto.h"
#include "Inventario.h"
using namespace std;

int main() {
	Inventario inventario("productos.dat");
	int opcion;

	do {
		cout << "\n1. Registrar producto\n2. Actualizar producto\n3. Realizar venta\n4. Generar informe\n5. Salir\nOpcion: ";
		cin >> opcion;
		try {
			switch (opcion) {
			case 1:
				inventario.registrarProducto();
				break;
			case 2:
				inventario.actualizarProducto();
				break;
			case 3:
				inventario.realizarVenta();
				break;
			case 4:
				inventario.generarInforme();
				break;
			case 5:
				cout << "Saliendo...\n";
				break;
			default:
				cout << "OpciC3n invC!lida.\n";
				break;
			}
		} catch (const exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	} while (opcion != 5);

	return 0;
}