#ifndef HABILIDADESBASICAS_H
#define HABILIDADESBASICAS_H

#include <iostream>
using namespace std;

class HabilidadesBasicas{
public:
    HabilidadesBasicas() {}

    virtual void atacar() = 0;
    virtual void defender(float dmgRecibido) = 0;
    virtual void Ultimate() = 0;

    ~HabilidadesBasicas() {}

};
#endif