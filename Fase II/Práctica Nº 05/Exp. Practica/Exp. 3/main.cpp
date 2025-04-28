#include "Empleado.h"
#include "Fecha.h"
#include "Contrato.h"

using namespace std;



int main() {
    // Crear un objeto Fecha
    Fecha fechaInicioContrato(1, 5, 2024);

    // Crear un objeto Contrato
    Contrato contratoEmpleado(123, "Contrato de trabajo indefinido", fechaInicioContrato);

    // Crear un objeto Empleado
    Empleado empleado1("Juan Pérez", contratoEmpleado);

    // Muestra la información del empleado y su contrato
    empleado1.mostrarEmpleado();

    return 0;
}