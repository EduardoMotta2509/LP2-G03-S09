#ifndef AUTOR_H
#define AUTOR_H

#include <iostream>
#include <vector>
#include "Libro.h"
using namespace std;

class Autor{
public:
    string nombre;
    string nacionalidad;
    vector<Libro> librosEscritos;
    Autor(string _nombre, string _nacionalidad, vector<Libro> _librosEscritos){
        nombre=_nombre;
        nacionalidad=_nacionalidad;
        librosEscritos=_librosEscritos;
    }
};
#endif