#include <iostream>
#include <vector>
using namespace std;

#include "Cliente.h"
#include "Producto.h"
#include "Venta.h"
#include "Pago.h"
#include "RegistroPagos.h"

//versión 19:00

int main() {
	// Productos
	Producto prod1("P001", "Notebook", "Lenovo", 1500);
	Producto prod2("P002", "Mouse Gamer", "Logitech", 300);
	Producto prod3("P003", "Teclado Mecánico", "Redragon", 450);
	Producto prod4("P004", "Monitor 24''", "Samsung", 800);
    Producto prod5("P005", "Impresora Multifunción", "HP", 1200);
    Producto prod6("P006", "Disco SSD 1TB", "Kingston", 600);
    Producto prod7("P007", "Tablet 10''", "Xiaomi", 950);
    Producto prod8("P008", "Auriculares Bluetooth", "Sony", 350);
    Producto prod9("P009", "Webcam HD", "Logitech", 400);
    Producto prod10("P010", "Silla Ergonómica", "Noblechairs", 1300);

	// Clientes
	vector<Venta> vacio;
	Cliente cliente1("Juan Pérez", "Calle Falsa 123", "juan@mail.com", vacio);
	Cliente cliente2("Ana López", "Av. Siempre Viva 456", "ana@mail.com", vacio);
    Cliente cliente3("Carlos Gómez", "Mitre 789", "carlos@mail.com", vacio);
    Cliente cliente4("Lucía Fernández", "Belgrano 321", "lucia@mail.com", vacio);
    Cliente cliente5("María Torres", "San Martín 654", "maria@mail.com", vacio);
    Cliente cliente6("Andrés Ríos", "Urquiza 111", "andres@mail.com", vacio);
    Cliente cliente7("Valentina Díaz", "Corrientes 202", "valen@mail.com", vacio);

	// Ventas para Juan
	    //venta 1
	vector<Producto> productosVenta1 = {prod1, prod2};
	vector<int> cantidadesVenta1 = {1, 2};
	Venta venta1("F001", "2025-04-06", &cliente1, productosVenta1, cantidadesVenta1);
	venta1.calcularPrecioTotal();
	//venta1.mostrarVenta();
	
	    //venta 2
	vector<Producto> productosVenta2 = {prod10, prod9};
	vector<int> cantidadesVenta2 = {6, 4};
	Venta venta2("F002", "2025-04-07", &cliente1, productosVenta2, cantidadesVenta2);
	venta2.calcularPrecioTotal();
	//venta2.mostrarVenta();



	// Ventas para Ana
	    //venta 1
	vector<Producto> productosVenta3 = {prod2, prod3};
	vector<int> cantidadesVenta3 = {1, 1};
	Venta venta3("F003", "2025-05-06", &cliente2, productosVenta3, cantidadesVenta3);
	venta3.calcularPrecioTotal();
	venta3.mostrarVenta();
	
	    //venta 2
	vector<Producto> productosVenta4 = {prod8, prod7};
	vector<int> cantidadesVenta4 = {4, 11};
	Venta venta4("F004", "2025-05-16", &cliente2, productosVenta4, cantidadesVenta4);
	venta4.calcularPrecioTotal();
	venta4.mostrarVenta();

	// Pagos para Juan
	Pago pago1(&cliente1, {});
	pago1.hacerPago(venta1);
	pago1.hacerPago(venta2);
	//pago1.mostrarHistorial();
	
    
    // Pagos para Ana
	Pago pago2(&cliente2, {});
	pago2.hacerPago(venta3);
	pago2.hacerPago(venta4);
	pago2.mostrarHistorial();

	// Registro de pagos
	RegistroPagos registro({pago1});
	registro.nuevoPagante(pago2);
	registro.mostrarPagantes();


	// Buscar por nombre
	cout << endl;
	registro.buscarXnombre("Ana López");
	registro.buscarXnombre("Pedro García"); // No existe

	return 0;
}
