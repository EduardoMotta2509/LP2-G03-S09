#ifndef TAREABASE_H
#define TAREABASE_H

#include <iostream>
#include <vector>
#include "IVisualizarTarea.h"


using namespace std;

class TareaBase : public IVisualizarTarea{
public:
    string id;
    string nombre;
    string descripcion;
    string fechaLimite;
    string estado;

    TareaBase(string _id, string _nombre, string _descripcion, string _fechaLimite, string _estado) {
        id=_id;
        nombre=_nombre;
        descripcion=_descripcion;
        fechaLimite=_fechaLimite;
        estado=_estado;
    }

    string getId(){
        return id;
    }

    void setEstado(string _estado){
        estado=_estado;
    }
    
    virtual void mostrarTarea() override = 0;
    
    virtual ~TareaBase() override = default;
};
#endif