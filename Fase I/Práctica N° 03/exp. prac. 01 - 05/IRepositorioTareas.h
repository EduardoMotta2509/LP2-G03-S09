#ifndef IREPOSITORIOTAREAS_H
#define IREPOSITORIOTAREAS_H

#include <iostream>
#include "TareaBase.h"

class IRepositorioTareas {
public:
    virtual void guardarTarea(TareaBase* tarea) = 0;
    virtual void eliminarTarea(string idTarea) = 0;
    virtual TareaBase* buscarTareaXID(string idTarea) = 0;
    virtual vector<TareaBase*> listarTareas() = 0;
    
    virtual ~IRepositorioTareas() = default;
};
#endif