#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "Sonido genérico de animal" << endl;
    }

    virtual ~Animal() {}
};

#endif
