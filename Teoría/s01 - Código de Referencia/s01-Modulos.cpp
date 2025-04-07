//////////////////////////////////////////////////////
/////////////// En archivo Persona.h //////////////////

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }

    // Mostrar información
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    // Destructor
    ~Persona() {
        cout << "Persona destruida: " << nombre << endl;
    }
};

#endif



//////////////////////////////////////////////////////
/////////////// En archivo main.cpp //////////////////

#include "Persona.h" // Incluir el archivo de la clase

int main() {
    // Crear un objeto de la clase Persona
    Persona p1("Adriana", 30);
    
    // Llamar a un método de la clase
    p1.mostrarInformacion();

    return 0;
}
