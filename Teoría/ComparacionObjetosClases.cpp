#include <iostream>
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string n, int e) : nombre(n), edad(e) {}

    // Método para comparar si dos objetos son iguales
    bool esIgual( const Persona& otra) const {
        return (nombre == otra.nombre && edad == otra.edad);

    }

    void mostrar() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    Persona p1("Juan", 25);
    Persona p2("Ana", 60);
    Persona p3("Juan", 25);  // Otro objeto con los mismos valores que p1

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    if (p1.esIgual(p2))
        cout << "p1 y p2 son iguales" << endl;
    else
        cout << "p1 y p2 son diferentes" << endl;

    if (p1.esIgual(p3))
        cout << "p1 y p3 son iguales" << endl;
    else
        cout << "p1 y p3 son diferentes" << endl;

    return 0;
}