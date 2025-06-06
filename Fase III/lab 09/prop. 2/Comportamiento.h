#ifndef COMPORTAMIENTO_H
#define COMPORTAMIENTO_H

#include <iostream>
using namespace std;

class Comportamiento{
public:
    Comportamiento() {}

    virtual void comer() = 0;
    virtual void dormir() = 0;
    virtual void desplazarse() = 0;
    
    ~Comportamiento() {}
};
#endif