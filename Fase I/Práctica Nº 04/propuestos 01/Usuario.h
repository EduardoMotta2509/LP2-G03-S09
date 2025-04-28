#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <vector>
#include "Libro.h"
using namespace std;

class Usuario{
private:
    string nombre;
    string direccion;
    string contacto;
    vector<Libro> librosPrestados;
public:
    Usuario(string _nombre, string _direccion, string _contacto, vector<Libro> _librosPrestados) : nombre(_nombre), direccion(_direccion), contacto(_contacto), librosPrestados(_librosPrestados) {}

    string getNombre(){ return nombre; }

    void añadirLibroPrestado(Libro libro){
        librosPrestados.push_back(libro);
    }
};
#endif