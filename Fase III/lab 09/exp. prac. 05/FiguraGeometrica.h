#ifndef FIGURA_GEOMETRICA_H 
#define FIGURA_GEOMETRICA_H 

class FiguraGeometrica { 
public: 
    virtual double calcularArea() = 0; 
    virtual double calcularPerimetro() = 0; 
    virtual ~FiguraGeometrica() {} 
}; 
#endif 