#include "Trabajador.h"
#include "Gerente.h"

const int MAX_TRABAJADORES = 5;

int main() {
    // Crear arreglo de trabajadores
    Trabajador* trabajadores[MAX_TRABAJADORES];

    // Crear trabajadores
    trabajadores[0] = new Trabajador("Carlos", 201);
    trabajadores[1] = new Trabajador("Laura", 202);
    trabajadores[2] = new Trabajador("Miguel", 203);

    // Crear gerente
    Gerente* gerente1 = new Gerente("Sofía", 300);

    // Asociar trabajadores al gerente
    gerente1->agregarTrabajador(trabajadores[0]);
    gerente1->agregarTrabajador(trabajadores[1]);
    gerente1->agregarTrabajador(trabajadores[2]);

    // Asociaciones reflexivas (compañeros entre sí)
    trabajadores[0]->agregarCompanero(trabajadores[1]);
    trabajadores[0]->agregarCompanero(trabajadores[2]);

    trabajadores[1]->agregarCompanero(trabajadores[0]);
    trabajadores[1]->agregarCompanero(trabajadores[2]);

    trabajadores[2]->agregarCompanero(trabajadores[0]);
    trabajadores[2]->agregarCompanero(trabajadores[1]);

    // Mostrar información
    gerente1->mostrarInfo();
    gerente1->mostrarTrabajadoresACargo();

    for (int i = 0; i < 3; i++) {
        trabajadores[i]->mostrarInfo();
        trabajadores[i]->mostrarCompaneros();
    }

    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete trabajadores[i];
    }
    delete gerente1;

    return 0;
}