#ifndef GESTORTAREAS_H
#define GESTORTAREAS_H

#include <iostream>
#include <vector>
#include "TareaBase.h"
#include "IRepositorioTareas.h"
#include "ITareaGestionable.h"
#include "IVisualizarTarea.h"


using namespace std;

class GestorTareas : public IVisualizarTarea, public ITareaGestionable{
private:
    IRepositorioTareas* repo;
public:
    GestorTareas(IRepositorioTareas* _repo) : repo(_repo){}

    void agregarTarea(TareaBase* nuevaTarea){
        repo->guardarTarea(nuevaTarea);
    }

    void eliminarTarea(string idTarea){
        repo->eliminarTarea(idTarea);
    }

    void mostrarTarea() override {
        vector<TareaBase*> tareas = repo->listarTareas();
        cout<<"Tareas en el sistema: "<<endl;
        for (TareaBase* tarea : tareas){
            tarea->mostrarTarea();
        }
    }
    
    ~GestorTareas() {
        delete repo;
    }
};
#endif