#ifndef REGISTROESTUDIANTES_H
#define REGISTROESTUDIANTES_H

#include <iostream>
using namespace std;

#include "RendimientoEstudiante.h"

class RegistroEstudiantes{
private:
    vector<RendimientoEstudiante> Registro;
public:
    RegistroEstudiantes(vector<RendimientoEstudiante> _Registro) : Registro(_Registro) {}

    void agregarRendimientoEstudiantil(vector<RendimientoEstudiante> NuevoRendimientoEstudiantil){
        Registro.push_back(NuevoRendimientoEstudiantil);
    }

    void imprimirRegistro(){
        for (int i=0; i<Registro.size(); i++){
            Registro[i].imprimirConsolidadoRendimiento();
        }
    }
};
#endif