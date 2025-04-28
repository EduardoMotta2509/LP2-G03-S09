#ifndef DISPOSITIVO_H
#define DISPOSITIVO_H

#include <iostream>
#include <string>
using namespace std;

class Dispositivo {
private:
    string marca;
    string modelo;
    int anioFabricacion;

public:
    // Constructor predeterminado
    Dispositivo() : marca("Desconocida"), modelo("Desconocido"), anioFabricacion(0) {
        cout << "Constructor predeterminado llamado para: " << modelo << endl;
    }

    // Constructor parametrizado
    Dispositivo(string marca, string modelo, int anioFabricacion)
        : marca(marca), modelo(modelo), anioFabricacion(anioFabricacion) {
        cout << "Constructor parametrizado llamado para: " << modelo << endl;
    }

    // Constructor de copia
    Dispositivo(const Dispositivo& otro) : marca(otro.marca), modelo(otro.modelo), anioFabricacion(otro.anioFabricacion) {
        cout << "Constructor de copia llamado para: " << modelo << endl;
    }

    // Destructor
    ~Dispositivo() {
        cout << "Destructor llamado para: " << modelo << endl;
    }

    void mostrarInformacion() const;
};

#endif 