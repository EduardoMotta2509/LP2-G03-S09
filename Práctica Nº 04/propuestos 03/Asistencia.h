#ifndef ASISTENCIA_H
#define ASISTENCIA_H

#include <iostream>
#include <vector>
using namespace std;

#include "Estudiante.h"

class Asistencia{
private:
    Estudiante* estudiante;
    vector<vector<string>> reporteAsistencias;
public:
    Asistencia(Estudiante* _estudiante, vector<vector<string>> _reporteAsistencias) : estudiante(_estudiante), reporteAsistencias(_reporteAsistencias) {}

    void registrarAsistenciaCurso(string codigoCurso, vector<string> asistenciaCurso){
        vector<Asignatura> asignatura = estudiante->getAsignaturas();
        for (int i=0; i<asignatura.size(); i++){
            if (asignatura[i].getCodigo() == codigoCurso){
                cout<<"Curso -> "<<asignatura[i].getNombre()<<" con código: "<<asignatura[i].getCodigo()<<" ENCONTRADO"<<endl;
                cout<<"Registrando Asistencia..."<<endl;
                reporteAsistencias[i] = asistenciaCurso;
            }
        }
    }

    void imprimirReporteGeneral(){
        vector<Asignatura> asignatura = estudiante->getAsignaturas();
        cout<<"\nImprimir Asistencia General"<<endl;
        for (int i=0; i<reporteAsistencias.size(); i++){
            cout<<"Curso -> "<<asignatura[i].getNombre()<<" código: "<<asignatura[i].getCodigo()<<endl;
            for (int j=0; j<reporteAsistencias[i].size(); j++){
                cout<<"     Asistencia marcada como: "<<reporteAsistencias[i][j]<<endl;
            }
        }
    }
};
#endif