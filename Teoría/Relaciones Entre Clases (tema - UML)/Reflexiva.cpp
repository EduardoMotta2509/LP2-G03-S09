#include <iostream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    Empleado* jefe;  // Relación reflexiva: un empleado puede tener otro empleado como jefe

public:
    Empleado(string nombre) : nombre(nombre), jefe(nullptr) {}

    void asignarJefe(Empleado* nuevoJefe) {
        jefe = nuevoJefe;
    }

    void mostrarRelacion() const {
        cout << "Empleado: " << nombre;
        if (jefe)
            cout << " - Jefe: " << jefe->nombre;
        else
            cout << " - Sin jefe asignado";
        cout << endl;
    }
};

int main() {
    Empleado juan("Juan");
    Empleado ana("Ana");
    Empleado carlos("Carlos");

    juan.asignarJefe(&ana);
    ana.asignarJefe(&carlos);

    juan.mostrarRelacion();
    ana.mostrarRelacion();
    carlos.mostrarRelacion();

    return 0;
}
