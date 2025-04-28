#include "Dispositivo.h"

//Muestra la info
void Dispositivo::mostrarInformacion() const {
    cout << "Marca: " << marca << ", Modelo: " << modelo
        << ", Año de Fabricación: " << anioFabricacion << endl;
}

int main() {
    //Arreglo de los dispositivos
    Dispositivo dispositivos[3] = {
        Dispositivo("Samsung", "Galaxy S21", 2021),       // Constructor parametrizado
        Dispositivo("Apple", "iPhone 13", 2021),          // Constructor parametrizado
        Dispositivo()                                    // Constructor predeterminado
    };

    cout << "Información de los dispositivos:" << endl;
    for (int i = 0; i < 3; ++i) {
        dispositivos[i].mostrarInformacion();
    }

    // Crear un dispositivo usando el constructor de copia
    cout << "\nCreando un dispositivo con el constructor de copia:" << endl;
    Dispositivo miDispositivo = dispositivos[0]; // Constructor de copia
    miDispositivo.mostrarInformacion();

    cout << "\nFin del programa:" << endl;
    return 0;
}