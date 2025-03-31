#ifndef REPOSITORIOTAREAS_H
#define REPOSITORIOTAREAS_H

#include <vector>
#include <iostream>
#include "TareaBase.h"
#include "IRepositorioTareas.h"

class RepositorioTareas : public IRepositorioTareas {
private:
    vector<TareaBase*> tareas;
public:
    
    void guardarTarea(TareaBase* tarea) override {
        tareas.push_back(tarea);
    }
    
    void eliminarTarea(string idTarea) override {
        for ( int i=0; i<tareas.size(); i++ ){
            if ( tareas[i]->getId() == idTarea ){
            delete tareas[i];
            tareas.erase(tareas.begin() + i);
            break;
            }
        }
    }
  
    TareaBase* buscarTareaXID(string idTarea) override {
        for ( int i=0; i<tareas.size(); i++ ){
            if (tareas[i]->getId() == idTarea){
                return tareas[i];
                break;
            }
        }
        return nullptr;
    }
    
    vector<TareaBase*> listarTareas() override {
        return tareas;
    }
};
#endif