////// ARREGLO ESTATICO DE OBJETOS //////

#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor por defecto
    Persona() {
        nombre = "Desconocido";
        edad = 0;
    }

    // Constructor con parámetros
    Persona(string _nombre, int _edad) {
        nombre = _nombre;
        edad = _edad;
    }

    // Método para mostrar información
    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    // Declarar un arreglo estático de 3 objetos Persona
    Persona personas[3] = {
        Persona("Adriana", 30),
        Persona("Carlos", 25),
        Persona("Elena", 28)
    };

    // Recorrer el arreglo y mostrar información
    for (int i = 0; i < 3; i++) {
        personas[i].mostrar();
    }

    return 0;
}


////// ARREGLO DINAMICO DE OBJETOS //////

#include <iostream>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor con parámetros
    Persona(string _nombre = "Desconocido", int _edad = 0) {
        nombre = _nombre;
        edad = _edad;
    }

    // Método para mostrar información
    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    int n;

    // Solicitar el tamaño del arreglo
    cout << "Ingrese la cantidad de personas: ";
    cin >> n;

    // Crear un arreglo dinámico de objetos Persona
    Persona* personas = new Persona[n];

    // Leer información de las personas
    for (int i = 0; i < n; i++) {
        string nombre;
        int edad;
        cout << "Ingrese el nombre y edad de la persona " << i + 1 << ": ";
        cin >> nombre >> edad;
        personas[i] = Persona(nombre, edad); // Inicialización del objeto
    }

    // Mostrar información de las personas
    cout << "\nLista de personas:\n";
    for (int i = 0; i < n; i++) {
        personas[i].mostrar();
    }

    // Liberar memoria
    delete[] personas;

    return 0;
}

