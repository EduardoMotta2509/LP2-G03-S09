#include <iostream>
#include "Reproductor.h"
#include "ReproductorMP3.h"

using namespace std;

int main() {
    Reproductor* Rep = new ReproductorMP3();

    Rep->reproducir();
    Rep->pausar();
    Rep->detener();

    delete Rep;
    return 0;
}
