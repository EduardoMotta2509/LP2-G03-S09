#ifndef REPRODUCTORMP3_H
#define REPRODUCTORMP3_H

#include "Reproductor.h"
#include <iostream>

using namespace std;

class ReproductorMP3 : public Reproductor {
public:
    void reproducir() override {
        cout << "Reproduciendo archivo MP3" << endl;
    }

    void pausar() override {
        cout << "Reproducción en pausa" << endl;
    }

    void detener() override {
        cout << "Reproducción detenida" << endl;
    }
};

#endif
