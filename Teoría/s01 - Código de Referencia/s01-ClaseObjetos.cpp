#include <iostream>
using namespace std;

class Persona {
private:
    // Atributos privados (solo accesibles dentro de la clase)
    string nombre;
    int edad;

public:
    // Constructor (inicializa los atributos)
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }

    // Métodos de acceso (Getters)
    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    // Métodos modificadores (Setters)
    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    void setEdad(int _edad) {
        if (_edad > 0) { // Validación simple
            edad = _edad;
        }
    }

    // Método público para mostrar los datos
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }

    // Destructor (se ejecuta al destruir el objeto)
    ~Persona() {
        cout << "Objeto destruido: " << nombre << endl;
    }
};

int main() {
    // Crear un objeto de la clase
    Persona p1("Adriana", 30);
    
    // Mostrar información del objeto
    p1.mostrarInformacion();

    // Modificar atributos con métodos de acceso
    p1.setEdad(35);
    cout << "Nueva edad: " << p1.getEdad() << endl;

    return 0; // Destructor se ejecuta automáticamente al final
}
