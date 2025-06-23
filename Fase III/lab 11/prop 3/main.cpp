#include "Persona.h"

int main() {
    Persona p1("Lucía", 30, "Av. Central 456");
    p1.guardar("persona.dat");

    Persona p2;
    p2.cargar("persona.dat");
    p2.mostrar();

    return 0;
}
