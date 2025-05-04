#ifndef GRUPO_H
#define GRUPO_H

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include "Alumno.h"

class Alumno;

class Grupo{
private:
    vector<Alumno> alumnos;
    int cantidad;
public:
    Grupo(int c): alumnos(c), cantidad(c) {}

    string representarGrupo(){
        string cantidadS = to_string(cantidad);
        string representacion = "Grupo de tamaño: "+ cantidadS;
        return representacion;
    }

    void agregarAlumno(const string& nombre, const int& edad, const float& promedio) {
        alumnos.emplace_back(nombre, edad, promedio);
    }

    void ordenarAlumnos(){
        sort(alumnos.begin(), alumnos.end(), [](const Alumno& a, const Alumno& b) {
            return a.getPromedio() < b.getPromedio();
        });
    }

    void calcularPromedioGeneral(){
        float sumaProms;
        for(int i=0; i<alumnos.size(); i++){
            sumaProms=sumaProms+alumnos[i].getPromedio();
        }
        float promGeneral = sumaProms/cantidad;
        cout<<"El promedio general es: "<<promGeneral<<endl;
    }

    Alumno mejorPromedio(){
        ordenarAlumnos();
        Alumno mejor = alumnos.back();
        cout << "El mejor promedio corresponde al alumno: "<< mejor.getNombre()<< " su promedio: " << mejor.getPromedio() << endl;
        return mejor;
    }


};
#endif