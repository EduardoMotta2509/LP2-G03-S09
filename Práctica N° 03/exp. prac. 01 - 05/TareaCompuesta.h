#ifndef TAREACOMPUESTA_H
#define TAREACOMPUESTA_H

#include <iostream>
#include <vector>

#include "TareaBase.h"
#include "IVisualizarTarea.h"


using namespace std;

class TareaCompuesta : public TareaBase {
public:
    vector<TareaBase*> subtareas;

    TareaCompuesta(string _id, string _nombre, string _descripcion, string _fechaLimite, string _estado, vector<TareaBase*> _subtareas) : TareaBase(_id, _nombre, _descripcion, _fechaLimite, _estado){
        subtareas=_subtareas;
    }

    void agregarSubtarea(TareaBase* nuevaTarea){
        subtareas.push_back(nuevaTarea);
    }
    void eliminarSubtarea(string idTarea){
        for ( int i=0; i<subtareas.size(); i++ ){
            if ( subtareas[i]->getId() == idTarea ){
                delete subtareas[i];
                subtareas.erase( subtareas.begin() + i );
                break;
            }
        }
    }
    void cambiarEstado(string nuevoEstado){
        for ( int i=0; i<subtareas.size(); i++ ){
            subtareas[i]->setEstado(nuevoEstado);
        }
    }
    void mostrarTarea() override {
        cout<<"      TAREA COMPUESTA"<<endl;
        cout<<"       Nombre: "<< nombre <<"  ID: "<< id <<" Fecha Límite:  "<< fechaLimite << endl;
        cout<<"       Descripcion: "<< descripcion << endl;
        cout<<"       Estado: "<< estado << endl;
        cout<<"      CONTIENE-->"<<endl;

        for ( int i=0; i<subtareas.size(); i++ ){
            subtareas[i]->mostrarTarea();
        }
    }
};

#endif