#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string n = "", int e = 0) : nombre(n), edad(e) {}

    void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    void setNombre(string n) { nombre = n; }
    void setEdad(int e) { edad = e; }

    string getNombre() const { 
        return nombre; 
    }
    int getEdad() const { 
        return edad; 
    }

    ~Persona() {
        cout << "Destructor de Persona ejecutado." << endl;
    }
};

#endif
