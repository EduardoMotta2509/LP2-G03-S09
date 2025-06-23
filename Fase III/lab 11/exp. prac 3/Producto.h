#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

class Producto {
private:
	char nombre[50];
	float precio;
	int cantidad;

public:
	Producto() : precio(0.0), cantidad(0) {
        strcpy(nombre, "");
    }
    
    Producto(const string& n, float p, int c) : precio(p), cantidad(c) {
        strncpy(nombre, n.c_str(), sizeof(nombre)-1);
        nombre[sizeof(nombre)-1] = '\0';
    }
    
    void setNombre(const string& n) {
        strncpy(nombre, n.c_str(), sizeof(nombre)-1);
        nombre[sizeof(nombre)-1] = '\0';
    }
    
    void setPrecio(float p) { precio = p; }
    void setCantidad(int c) { cantidad = c; }
    
    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    int getCantidad() const { return cantidad; }
    
    void mostrar() const {
        cout << "Nombre: " << nombre << " | Precio: " << precio << " | Cantidad: " << cantidad << endl;
    }
    
    void guardar(ofstream& archivo) const {
        archivo.write(reinterpret_cast<const char*>(this), sizeof(Producto));
    }
    
    void leer(istream& archivo) {
        archivo.read(reinterpret_cast<char*>(this), sizeof(Producto));
    }
    };

#endif