#include "Empleado.h"

int main() {
    // e) Crear objeto derivado
    Empleado emp("Carlos", 30, "Ingeniero de Software", 4500.0);

    // f) Acceder a métodos heredados (indirectamente, con get/set)
    cout << "Datos heredados desde Persona:" << endl;
    cout << "Nombre: " << emp.getNombre() << ", Edad: " << emp.getEdad() << endl;

    // g) Mostrar datos completos del empleado
    cout << "\nDatos completos del Empleado:" << endl;
    emp.mostrarDatosEmpleado();

    // h) Modificar y mostrar atributos propios
    emp.setCargo("Líder de Proyecto");
    emp.setSueldo(6000.0);

    cout << "\nDatos modificados del Empleado:" << endl;
    emp.mostrarDatosEmpleado();

    return 0;
}
