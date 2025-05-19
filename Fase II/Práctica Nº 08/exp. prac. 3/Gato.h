#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "El gato dice: Miauuu" << endl;
    }
};

#endif
