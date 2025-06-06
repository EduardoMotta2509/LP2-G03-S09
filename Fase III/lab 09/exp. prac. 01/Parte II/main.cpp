#include <iostream> 
#include "Animal.h" 
#include "Perro.h" 
using namespace std; 
int main() { 
    Perro miperrito; 
    Animal* perritoAnimal = &miperrito; 
    perritoAnimal->hacerSonido(); 
    return 0; 
} 