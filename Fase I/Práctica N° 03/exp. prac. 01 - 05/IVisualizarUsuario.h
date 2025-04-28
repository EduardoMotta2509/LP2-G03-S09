#ifndef IVISUALIZARUSUARIO_H
#define IVISUALIZARUSUARIO_H

#include <iostream>

class IVisualizarUsuario {
public:
    virtual void mostrarUsuario() = 0;
    virtual ~IVisualizarUsuario() = default;
};
#endif