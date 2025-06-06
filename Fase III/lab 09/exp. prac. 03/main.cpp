#include <iostream> 
#include "Figura.h" 
#include "Circulo.h" 
#include "Rectangulo.h" 
#include "Triangulo.h" 

using namespace std; 

int main() { 
    const int n=3; 
    Figura* figuras[n]; 
    figuras[0]= new Circulo(3.0); 
    figuras[1]= new Rectangulo(3.0,4.0); 
    figuras[2]= new Triangulo(2.0,3.0); 
    cout<<"Calculando áreas de las figuras: "<<endl; 
    for(int i=0; i<n;i++){ 
        cout<<"El área de la figura "<< i+1<<" es: "<<figuras[i]->calcularArea()<<endl; 
    } 
    return 0; 
} 