#include <iostream> 
#include "Animal.h" 
#include "Perro.h" 
using namespace std; 
int main() { 
    Perro miperrito; 
    Animal perritowAnimal = miperrito; 
    perritowAnimal.hacerSonido(); 
    return 0; 
} 