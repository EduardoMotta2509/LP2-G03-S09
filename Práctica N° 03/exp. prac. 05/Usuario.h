#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <vector>
#include "Tareas.h"
#include "Interfaces.h"

using namespace std;

class Usuario : public IMostrable{
public:
    string id;
    string nombre;
    vector<TareaBase*> tareasAsignadas;

    Usuario(string _id, string _nombre, vector<TareaBase*> _tareasAsignadas) {
        id=_id;
        nombre=_nombre;
        tareasAsignadas=_tareasAsignadas;
    }

    string getID(){
        return id;
    }
    void asignarTarea(TareaBase* tarea){
        tareasAsignadas.push_back(tarea);
    }

    void desasignarTarea(string idTarea){
        for ( int i=0; i<tareasAsignadas.size(); i++ ){
            if ( tareasAsignadas[i]->getId() == idTarea ){
                tareasAsignadas.erase( tareasAsignadas.begin() + i );
                break;
            }
        }
    }

    void mostrarInformación() override {
        cout<<" Nombre: "<< nombre <<" ID: "<< id <<endl;
        cout<<"························· TAREAS ASIGNADAS························· "<<endl;
        for ( int i=0; i<tareasAsignadas.size(); i++ ){
            tareasAsignadas[i]->mostrarInformación();
        }
    }
};
#endif