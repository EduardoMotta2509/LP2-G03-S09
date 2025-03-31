#ifndef IREPOSITORIOUSUARIOS_H
#define IREPOSITORIOUSUARIOS_H

#include <iostream>
#include "Usuario.h"

class IRepositorioUsuarios {
public:
    virtual void guardarUsuario(Usuario usuario) = 0;
    virtual void eliminarUsuario(string idUsuario) = 0;
    virtual Usuario* buscarUsuarioXID(string idUsuario) = 0;
    virtual vector<Usuario> listarUsuarios() = 0;
    virtual ~IRepositorioUsuarios() = default;
};
#endif
