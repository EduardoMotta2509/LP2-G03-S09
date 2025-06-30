#ifndef EVENTO_H
#define EVENTO_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Evento {
private:
    string nombre;
    string fecha;
    vector<string> asistentes;

public:
    Evento(string n, string f) : nombre(n), fecha(f) {}

    string getNombre() { return nombre; }
    string getFecha() { return fecha; }

    void agregarAsistente(const string& nombreAsistente) {
        asistentes.push_back(nombreAsistente);
        cout << "Asistente agregado correctamente.\n";
    }

    void mostrarAsistentesOrdenados() {
        if (asistentes.empty()) {
            cout << "No hay asistentes registrados para este evento.\n";
            return;
        }
        sort(asistentes.begin(), asistentes.end());
        cout << "Asistentes del evento \"" << nombre << "\" en orden alfabético:\n";
        for (const auto& a : asistentes) {
            cout << "- " << a << endl;
        }
    }

    void mostrarResumen() {
        cout << "Evento: " << nombre << " | Fecha: " << fecha << " | Asistentes: " << asistentes.size() << endl;
    }
};
#endif