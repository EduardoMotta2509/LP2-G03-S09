#ifndef IVISUALIZARTAREA_H
#define IVISUALIZARTAREA_H

#include <iostream>

class IVisualizarTarea {
public:
    virtual void mostrarTarea() = 0;
    virtual ~IVisualizarTarea() = default;
};
#endif