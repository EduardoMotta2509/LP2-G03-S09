#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Usuario {
    private:
        string nombre;
        string dni;
        string nacionalidad;
public:
    Usuario(string _nombre, string _dni, string _nacionalidad) : nombre(_nombre), dni(_dni), nacionalidad(_nacionalidad) {}
    string getNombre() const {
        cout << "Usuario: getNombre" << endl;
        return nombre;
    }
    string getDni() const {
        cout << "Usuario: getDni" << endl;
        return dni;
    }
    string getNacionalidad() const {
        cout << "Usuario: getNacionalidad" << endl;
        return nacionalidad;
    }
    void actualizarDatos(const string& nuevoNombre, const string& nuevoDni, const string& nuevaNacionalidad) {
        cout << "Usuario: actualizarDatos" << endl;
        nombre = nuevoNombre;
        dni = nuevoDni;
        nacionalidad = nuevaNacionalidad;
    }
};
#endif