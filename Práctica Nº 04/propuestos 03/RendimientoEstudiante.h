#ifndef RENDIMIENTOESTUDIANTE_H
#define RENDIMIENTOESTUDIANTE_H

#include <iostream>
using namespace std;

#include "Estudiante.h"
#include "Notas.h"
#include "Asistencia.h"

class RendimientoEstudiante{
private:
    Estudiante* estudiante;
    Notas* consolidadoNotas;
    Asistencia* consolidadoAsistencia;
public:
    RendimientoEstudiante(Estudiante* _estudiante, Notas* _consolidadoNotas, Asistencia* _consolidadoAsistencia) : estudiante(_estudiante), consolidadoNotas(_consolidadoNotas), consolidadoAsistencia(_consolidadoAsistencia) {}

    void imprimirConsolidadoRendimiento(){
        cout<<"---------CONSOLIDADO RENDIMIENTO DEL ESTUDIANTE---------"<<endl;
        cout<<estudiante->infoEstudiante();
        cout<<"               ---CONSOLIDADO DE NOTAS---               "<<endl;
        consolidadoNotas->mostrarNotas();
        cout<<"               ---RECORD DE ASISTENCIAS---              "<<endl;
        consolidadoAsistencia->imprimirReporteGeneral();
    }
};
#endif