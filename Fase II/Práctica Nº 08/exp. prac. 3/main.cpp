#include <iostream>
#include "Animal.h"
#include "Perro.h"
#include "Gato.h"
#include "Vaca.h"

using namespace std;

int main() {
    Animal* animal;

    animal = new Perro();
    animal->hacerSonido();
    delete animal;

    animal = new Gato();
    animal->hacerSonido();
    delete animal;

    animal = new Vaca();
    animal->hacerSonido();
    delete animal;

    return 0;
}
