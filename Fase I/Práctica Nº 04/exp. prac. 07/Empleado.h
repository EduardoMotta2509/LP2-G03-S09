#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
private:
    string cargo;
    double sueldo;

public:
    Empleado(string n, int e, string c, double s)
        : Persona(n, e), cargo(c), sueldo(s) {}

    ~Empleado() {
        cout << "Destructor de Empleado hecho." << endl;
    }

    void mostrarDatosEmpleado() const {
        // f) Acceso a métodos heredados
        cout << "Nombre: " << getNombre()
             << ", Edad: " << getEdad()
             << ", Cargo: " << cargo
             << ", Sueldo: " << sueldo << endl;
    }

    void setCargo(string c) { 
        cargo = c; 
    }
    void setSueldo(double s) { 
        sueldo = s; 
    }

    string getCargo() const { 
        return cargo; 
    }
    double getSueldo() const { 
        return sueldo; 
    }
};

#endif
