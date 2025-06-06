#include <iostream> 
#include "FiguraGeometrica.h" 
#include "Circulo.h" 
#include "Rectangulo.h" 
#include "Triangulo.h" 

using namespace std; 

int main() { 
    const int NUM_FIGURAS = 3; 

    FiguraGeometrica* figuras[NUM_FIGURAS]; 

    figuras[0] = new Circulo(5.0); 
    figuras[1] = new Rectangulo(4.0, 6.0); 
    figuras[2] = new Triangulo(3.0, 4.0, 3.0, 4.0, 5.0); 

    cout << "Cálculo de las Figuras Geométricas" << endl; 

    for (int i = 0; i < NUM_FIGURAS; ++i) { 
        cout << "\nFigura " << i + 1 << ":" << endl; 
        cout << "  Área: " << figuras[i]->calcularArea() << endl; 
        cout << "  Perímetro: " << figuras[i]->calcularPerimetro() << endl; 
    } 

    for (int i = 0; i < NUM_FIGURAS; ++i) { 
        delete figuras[i]; 
        figuras[i] = nullptr; 
    } 
    return 0; 
} 