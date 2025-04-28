#include <iostream>
using namespace std;

#include "Empresa.h"
#include "Gerente.h"
#include "Direccion.h"

//version 23:54

int main(){
    Empresa e1("Genrete Juan",10.100, "Distrito 1", "Calle 2", "Manzana 1");
    return 0;
}

//PANTALLA:
//  Constructor invocado para: Genrete Juan
//  Constructor invocado para la dirección. 
//  Constructor invocado para la EMPRESA. 
//  Destructor invocado para la EMPRESA. 
//  Destructor invocado para la dirección. 
//  Destructor invocado para: Genrete Juan