#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
using namespace std;
#include "Asignatura.h"

class Estudiante{
private:
    string nombre;
    string direccion;
    string nroMatricula;
    vector<Asignatura> asignaturas;
public:
    Estudiante(string _nombre, string _direccion, string _nroMatricula, vector<Asignatura> _asignaturas) : nombre(_nombre), direccion(_direccion), nroMatricula(_nroMatricula), asignaturas(_asignaturas) {}

    vector<Asignatura> getAsignaturas(){ return asignaturas; }

    void añadirAsignatura(Asignatura nuevaAsignatura){
        asignaturas.push_back(nuevaAsignatura);
    }

    void infoEstudiante(){
        cout<<"Nombre: "<<nomre<<" nro de Matrícula: "<<nroMatricula<<endl;
        cout<<"Dirección: "<<direccion<<endl;
        cout<<"Asignaturas que el estudiante lleva: "<<endl;
        for (int i=0; i<asignaturas.size(); i++){
            cout<<" -"<<asignaturas[i].getNombre();
        }
    }

};
#endif
