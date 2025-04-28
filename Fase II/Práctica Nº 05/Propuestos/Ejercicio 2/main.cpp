#include <iostream>
using namespace std;

#include "Cliente.h"
#include "Direccion.h"
#include "FechaRegistro.h"

int main(){
    Cliente c1("Juan", "Mariano Melgar", "Comandante Canga", "P-200", 27, 04, 2025);
    c1.mostrarCliente();
    
    return 0;
}