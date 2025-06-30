#include <iostream>
#include <vector>
#include <limits>
#include "Evento.h"
using namespace std;

int main() {
    vector<Evento> eventos;
    int opcion;

    cout << "     BIENVENIDO AL SISTEMA DE GESTIÓN DE EVENTOS\n";

    do {
        cout << "\nMENÚ DE OPCIONES:\n";
        cout << "1. Agregar nuevo evento\n";
        cout << "2. Agregar asistente a un evento\n";
        cout << "3. Mostrar asistentes ordenados de un evento\n";
        cout << "4. Buscar eventos por fecha\n";
        cout << "5. Salir\n";
        cout << "Ingrese la opción deseada: ";
        while (!(cin >> opcion) || opcion < 1 || opcion > 5) {
            cout << "Entrada inválida. Ingrese un número entre 1 y 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.ignore(); // Limpiar buffer de salto de línea

        string nombreEvento, fecha, nombreAsistente;
        bool encontrado = false;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del evento: ";
                getline(cin, nombreEvento);
                cout << "Ingrese la fecha del evento (formato YYYY-MM-DD): ";
                getline(cin, fecha);
                eventos.emplace_back(nombreEvento, fecha);
                cout << "Evento agregado correctamente.\n";
                break;

            case 2:
                cout << "Ingrese el nombre del evento al que desea agregar un asistente: ";
                getline(cin, nombreEvento);
                for (auto& e : eventos) {
                    if (e.getNombre() == nombreEvento) {
                        cout << "Ingrese el nombre del asistente: ";
                        getline(cin, nombreAsistente);
                        e.agregarAsistente(nombreAsistente);
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado)
                    cout << "Evento no encontrado.\n";
                break;

            case 3:
                cout << "Ingrese el nombre del evento para ver su lista de asistentes: ";
                getline(cin, nombreEvento);
                for (auto& e : eventos) {
                    if (e.getNombre() == nombreEvento) {
                        e.mostrarAsistentesOrdenados();
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado)
                    cout << "Evento no encontrado.\n";
                break;

            case 4:
                cout << "Ingrese la fecha para buscar eventos (formato YYYY-MM-DD): ";
                getline(cin, fecha);
                for (auto& e : eventos) {
                    if (e.getFecha() == fecha) {
                        e.mostrarResumen();
                        encontrado = true;
                    }
                }
                if (!encontrado)
                    cout << "No se encontraron eventos para esa fecha.\n";
                break;
        }

    } while (opcion != 5);

    cout << "Gracias por usar el sistema de gestión de eventos.\n";
    return 0;
}