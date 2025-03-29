#ifndef INTERFACES_H
#define INTERFACES_H

#include <iostream>

using namespace std;

class IMostrable{
public:
    virtual void mostrarInformación()= 0;
    virtual ~IMostrable() = default;
};

class IGestionable{
public:
    virtual void agregarTarea()=0;
    virtual void eliminarTarea()=0;
    virtual~IGestionable() {};
};
#endif

