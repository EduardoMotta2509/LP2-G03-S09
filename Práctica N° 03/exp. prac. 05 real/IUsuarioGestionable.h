#ifndef IUSUARIOGESTIONABLE_H
#define IUSUARIOGESTIONABLE_H

#include <iostream>
#include "Usuario.h"


using namespace std;

class IUsuarioGestionable{
public:
    virtual void agregarUsuario(Usuario* nuevoUsuario) = 0;
    virtual void eliminarUsuario(string idUsuario) = 0;
    virtual ~IUsuarioGestionable() = default;
};
#endif