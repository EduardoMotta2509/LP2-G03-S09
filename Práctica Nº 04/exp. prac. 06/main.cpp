#include "Auto.h"

int main() {
    Auto auto1("Toyota", 150);

    cout << "Info del auto:\n";
    auto1.mostrarAuto();

    cout << "\nModificación de la potencia del motor...\n";
    auto1.getMotor().setHP(180);

    cout << "Información actualizada del auto:\n";
    auto1.mostrarAuto();

    return 0;
}
