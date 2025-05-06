#include <iostream>
using namespace std;

#include "Persona.h"
#include "Empleado.h"
#include "Cliente.h"

int main(){
    Persona p1("Juan", 19, 4000.40, "jaun@gmail.com");
    p1.setEmail("juan19@hotmail.com");
    p1.mostrarPersona();

    Empleado e1("Pedro", 23, 2000.50, "pedro@linkedln.com", "T-100");
    e1.setEmail("PedroSalas@ucsm.edu.pe");
    e1.mostrarEmpleado();

    Cliente c1("Mario", 40, 5000.60, "mario@gmail.com", "12345678");
    c1.setEmail("mario40@yahoo.com");
    c1.mostrarCliente();

    return 0;
}