#ifndef ITAREAGESTIONABLE_H
#define ITAREAGESTIONABLE_H

#include <iostream>
#include "TareaBase.h"


using namespace std;

class ITareaGestionable{
public:
    virtual void agregarTarea(TareaBase* nuevaTarea) = 0;
    virtual void eliminarTarea(string idTarea) = 0;
    virtual ~ITareaGestionable() = default;
};
#endif