#ifndef FIGURA_H
#define FIGURA_H

class Figura {
public:
    virtual double calcularArea() = 0; // Método puro (abstracto)
    virtual ~Figura() {}
};

#endif
