#ifndef TAREASIMPLE_H
#define TAREASIMPLE_H

#include <iostream>
#include <vector>

#include "TareaBase.h"
#include "IVisualizarTarea.h"


using namespace std;

class TareaSimple : public TareaBase{
public:
    TareaSimple(string _id, string _nombre, string _descripcion, string _fechaLimite, string _estado) : TareaBase(_id, _nombre, _descripcion, _fechaLimite, _estado){}

    virtual void mostrarTarea() override {
        cout<<"         -------------------------------------------------------------------------"<<endl;
        cout<<"         Tarea Simple: "<<endl;
        cout<<"              Nombre: "<< nombre <<"  ID: "<< id <<" Fecha Límite:  "<< fechaLimite << endl;
        cout<<"              Descripcion: "<< descripcion << endl;
        cout<<"              Estado: "<< estado << endl;
        cout<<"         -------------------------------------------------------------------------"<<endl;
    }
};
#endif