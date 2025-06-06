#include <iostream> 
#include "Animal.h" 
#include "Perro.h" 
#include "Gato.h" 
#include "Vaca.h" 
using namespace std; 

int main() { 
    const int n=3; 
    Animal* Ani[n]; 
    Ani[0]= new Perro(); 
    Ani[1]= new Gato(); 
    Ani[2]= new Vaca(); 

    cout<<"Sonido de los animales"<<endl; 
    for(int i=0; i<n;i++){ 
        cout<<"El sonido del animal "<< i+1<<" es: "; 
        Ani[i]->hacerSonido(); 
    } 
    return 0; 
} 