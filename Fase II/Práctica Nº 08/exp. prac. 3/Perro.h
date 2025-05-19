#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro dice: Guauuuu" << endl;
    }
};

#endif
