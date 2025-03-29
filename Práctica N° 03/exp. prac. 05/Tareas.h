#ifndef TAREABASE_H
#define TAREABASE_H

#include <iostream>
#include <vector>
#include "Interfaces.h"

using namespace std;

class TareaBase : public IMostrable{
public:
    string id;
    string nombre;
    string descripcion;
    string fechaLimite;
    string estado;

    TareaBase(string _id, string _nombre, string _descripcion, string _fechaLimite, string _estado){
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
    
    virtual void mostrarInformación() override = 0;
};

class TareaSimple : public TareaBase{
public:
    TareaSimple(string _id, string _nombre, string _descripcion, string _fechaLimite, string _estado) : TareaBase(_id, _nombre, _descripcion, _fechaLimite, _estado){}

    virtual void mostrarInformación() override {
        cout<<"         ·································································"<<endl;
        cout<<"         Tarea Simple: "<<endl;
        cout<<"              Nombre: "<< nombre <<"  ID: "<< id <<" Fecha Límite:  "<< fechaLimite << endl;
        cout<<"              Descripcion: "<< descripcion << endl;
        cout<<"              Estado: "<< estado << endl;
        cout<<"         ·································································"<<endl;
    }
};

class TareaCompuesta : public TareaBase{
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
    void mostrarInformación() override {
        cout<<"      TAREA COMPUESTA"<<endl;
        cout<<"       Nombre: "<< nombre <<"  ID: "<< id <<" Fecha Límite:  "<< fechaLimite << endl;
        cout<<"       Descripcion: "<< descripcion << endl;
        cout<<"       Estado: "<< estado << endl;
        cout<<"      CONTIENE-->"<<endl;

        for ( int i=0; i<subtareas.size(); i++ ){
            subtareas[i]->mostrarInformación();
        }
    }
};

#endif