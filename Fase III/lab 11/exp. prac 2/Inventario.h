#ifndef INVENTARIO_H
#define INVENTARIO_H


#include <iostream>
#include <fstream>
#include <cstring>
#include "Producto.h"
#include <vector>
using namespace std;

class Inventario {
private:
    string nombreArchivo;

public:
    Inventario(const string& archivo) : nombreArchivo(archivo) {}
    
    void registrarProducto() {
        string nombre;
        float precio;
        int cantidad;
    
        cout << "Ingrese nombre del producto: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Ingrese precio: ";
        cin >> precio;
        cout << "Ingrese cantidad: ";
        cin >> cantidad;
    
        Producto p(nombre, precio, cantidad);
        ofstream archivo(nombreArchivo, ios::binary | ios::app);
        if (!archivo) throw runtime_error("No se pudo abrir el archivo para escritura.");
        p.guardar(archivo);
        archivo.close();
    }
    
    void actualizarProducto() {
        string nombre;
        cout << "Ingrese nombre del producto a actualizar: ";
        cin.ignore(); getline(cin, nombre);
    
        fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
        if (!archivo) throw runtime_error("Archivo no encontrado.");
    
        Producto p;
        bool encontrado = false;
        while (!archivo.eof()) {
            streampos pos = archivo.tellg();
            p.leer(archivo);
            if (archivo && p.getNombre() == nombre) {
                float nuevoPrecio;
                int nuevaCantidad;
                cout << "Nuevo precio: ";
                cin >> nuevoPrecio;
                cout << "Nueva cantidad: ";
                cin >> nuevaCantidad;
    
                p.setPrecio(nuevoPrecio);
                p.setCantidad(nuevaCantidad);
    
                archivo.seekp(pos);
                archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
                encontrado = true;
                break;
            }
        }
        archivo.close();
        if (!encontrado) throw runtime_error("Producto no encontrado.");
    }
    
    void realizarVenta() {
        string nombre;
        int cantidadVendida;
        cout << "Ingrese nombre del producto: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Cantidad a vender: ";
        cin >> cantidadVendida;
    
        fstream archivo(nombreArchivo, ios::binary | ios::in | ios::out);
        if (!archivo) throw runtime_error("Archivo no encontrado.");
    
        Producto p;
        bool encontrado = false;
        while (!archivo.eof()) {
            streampos pos = archivo.tellg();
            p.leer(archivo);
            if (archivo && p.getNombre() == nombre) {
                if (p.getCantidad() < cantidadVendida) throw runtime_error("Cantidad insuficiente para venta.");
                p.setCantidad(p.getCantidad() - cantidadVendida);
                archivo.seekp(pos);
                archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto));
                encontrado = true;
                break;
            }
        }
        archivo.close();
        if (!encontrado) throw runtime_error("Producto no encontrado.");
    }
    
    void generarInforme() {
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo) throw runtime_error("Archivo no encontrado.");
        Producto p;
        cout << "\n-- INFORME DE INVENTARIO --\n";
        while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
            p.mostrar();
        }
        archivo.close();
    }
    
    Producto buscarProductoPorNombre(const string& nombre) {
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo) throw runtime_error("Archivo no encontrado.");
        Producto p;
        while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
            if (p.getNombre() == nombre) return p;
        }
        throw runtime_error("Producto no encontrado.");
    }
};

#endif