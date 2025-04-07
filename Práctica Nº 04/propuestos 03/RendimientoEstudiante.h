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
        cout<<"\n"<<"---------CONSOLIDADO RENDIMIENTO DEL ESTUDIANTE---------"<<endl;
        estudiante->infoEstudiante();
        cout<<"\n"<<"               ---CONSOLIDADO DE NOTAS---               "<<endl;
        consolidadoNotas->mostrarNotas();
        cout<<"\n"<<"               ---RECORD DE ASISTENCIAS---              "<<endl;
        consolidadoAsistencia->imprimirReporteGeneral();
    }
};
#endif