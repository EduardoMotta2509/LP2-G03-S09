#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H

class Reproductor {
public:
    virtual void reproducir() = 0;
    virtual void pausar() = 0;
    virtual void detener() = 0;
    virtual ~Reproductor() {}
};

#endif
