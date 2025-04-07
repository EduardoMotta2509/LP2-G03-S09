#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <iostream>
using namespace std;

class Profesor;

class Asignatura{
private:
    string codigo;
    string nombre;
    string descripcion;
    Profesor docenteImpartidor;
public:
    Asignatura(string _codigo, string _nombre, string _descripcion, Profesor _docenteImpartidor) : codigo(_codigo), nombre(_nombre), descripcion(_descripcion), docenteImpartidor(_docenteImpartidor) {}

    string getCodigo(){return codigo;}
    void cambiarDocente(Profesor nuevoDocente){
        docenteImpartidor=nuevoDocente;
    }

};
#endif