#ifndef NOTAS_H
#define NOTAS_H

#include <iostream>
using namespace std;

#include "Estudiante.h"
#include "Asignatura.h"

class Notas{
private:
    Estudiante* estudiante;
    vector<float> notas;
    float promedio=0;
public:
    Notas(Estudiante* _estudiante, vector<float> _notas) : estudiante(_estudiante), notas(_notas) {}

    void cambiarNotas(vector<float> _notas){
        notas=_notas;
    }

    float calcularPromdeio(){
        float suma;
        for (int i=0; i<notas.size(); i++){
            suma+=notas[i];
        }
        promedio=suma/notas.size();
        return promedio;
    }

    void mostrarNotas(){
        vector<Asignatura> curso = estudiante->getAsignaturas();
        for(int i=0; i<notas.size(); i++){
            cout<<"         ASIGNATURA: "<<curso[i]<<" Nota: "<<notas[i]<<endl;
        }
    }
};
#endif