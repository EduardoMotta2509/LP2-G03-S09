#include <iostream>
#include "Usuario.h"
#include "Administrador.h"
#include "HabitacionSimple.h"
#include "HabitacionDoble.h"
#include "Suite.h"
#include "Hotel.h"
#include "Reserva.h"
#include "ValidarFechaExcepcion.h"


using namespace std;
int main() {
    Hotel hotel;
    vector<Usuario*> usuarios;
    usuarios.push_back(new Usuario("Lucía", "123", "Perú", "lucia@mail.com", "1234"));
    usuarios.push_back(new Administrador("Mario", "999", "Perú", "admin@mail.com", "admin", &hotel));

    string correo, clave;
    cout << "Correo: "; cin >> correo;
    cout << "Clave: "; cin >> clave;

    Usuario* actual = nullptr;
    bool esAdmin = false;
    for (auto u : usuarios)
        if (u->autenticar(correo, clave)) {
            actual = u;
            esAdmin = dynamic_cast<Administrador*>(u);
            break;
        }

    if (!actual) { cout << "Login inválido\n"; return 0; }

    int op;
    do {
        cout << "\n1. Actualizar datos\n2. Buscar habitación\n3. Reservar\n4. Cancelar reserva\n5. Ver historial\n";
        if (esAdmin) cout << "6. Agregar habitación\n7. Gestionar disponibilidad\n8. Ver reportes\n";
        cout << "0. Salir\nOpción: "; cin >> op;

        switch (op) {
            case 1: {
                string n, d, nac;
                cout << "Nuevo nombre: "; cin >> n;
                cout << "Nuevo DNI: "; cin >> d;
                cout << "Nueva nacionalidad: "; cin >> nac;
                actual->actualizarDatos(n, d, nac);
                break;
            }
            case 2: {
                string cod;
                cout << "Código habitación: "; cin >> cod;
                Habitacion* h = actual->buscarHabitacion(hotel, cod);
                if (h) cout << "Tipo: " << h->getTipo() << ", Precio: S/." << h->getPrecio() << endl;
                else cout << "No encontrada.\n";
                break;
            }
            case 3: {
                string cod, tipo, ini, fin;
                cout << "Código: "; cin >> cod;
                cout << "Tipo: "; cin >> tipo;
                cout << "Inicio: "; cin >> ini;
                cout << "Fin: "; cin >> fin;
                try {
                    actual->reservar(hotel, cod, tipo, ini, fin);
                    cout << "Reserva registrada.\n";
                } catch (ValidarFechaExcepcion& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                string cod;
                cout << "Código reserva: "; cin >> cod;
                if (actual->cancelarReserva(hotel, cod)) cout << "Cancelada.\n";
                else cout << "No encontrada o no autorizada.\n";
                break;
            }
            case 5: actual->verHistorial(); break;
            case 6:
                if (esAdmin) {
                    string tipo, cod; double precio;
                    cout << "Tipo: "; cin >> tipo;
                    cout << "Código: "; cin >> cod;
                    cout << "Precio: "; cin >> precio;
                    dynamic_cast<Administrador*>(actual)->agregarHabitacion(tipo, cod, precio);
                }
                break;
            case 7:
                if (esAdmin) {
                    string cod; bool est;
                    cout << "Código habitación: "; cin >> cod;
                    cout << "1 = desbloquear, 0 = bloquear: "; cin >> est;
                    dynamic_cast<Administrador*>(actual)->gestionarDisponibilidad(cod, est);
                }
                break;
            case 8:
                if (esAdmin) dynamic_cast<Administrador*>(actual)->verReportesOcupacion();
                break;
        }
    } while (op != 0);

    return 0;
}