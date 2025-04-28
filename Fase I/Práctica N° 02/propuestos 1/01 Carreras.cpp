#include <iostream>
using namespace std;

class Auto {
private:
    string nombre;
    int velocidad;
    int distanciaRecorrida;
public:
    Auto(string _nombre, int _velocidad) {
        nombre = _nombre;
        velocidad = _velocidad;
        distanciaRecorrida = 0;
    }
    void avanzar() {
        distanciaRecorrida += velocidad; 
    }
    int getDistancia() {
        return distanciaRecorrida;
    }
    string getNombre() {
        return nombre;
    }
};

class Carrera {
private:
    int distanciaTotal;
    Auto jugador;
    Auto computadora;
public:
    Carrera(int _distancia, string nombreJugador, int dificultad) 
        : distanciaTotal(_distancia), jugador(nombreJugador, 10), computadora("Computadora", dificultad) {}
    
    void iniciar() {
        cout << "Carrera inciada\n";
        while (jugador.getDistancia() < distanciaTotal && computadora.getDistancia() < distanciaTotal) {
            jugador.avanzar();
            computadora.avanzar();
            cout << jugador.getNombre() << " ha recorrido " << jugador.getDistancia() << " metros.\n";
            cout << computadora.getNombre() << " ha recorrido " << computadora.getDistancia() << " metros.\n";
        }
        determinarGanador();
    }
    void determinarGanador() {
        if (jugador.getDistancia() >= distanciaTotal && computadora.getDistancia() >= distanciaTotal) {
            cout << "Empate bro :( \n";
        } else if (jugador.getDistancia() >= distanciaTotal) {
            cout << "Muy bien " << jugador.getNombre() << " usted ganó la carrera\n";
        } else {
            cout << "La pc ganó\n";
        }
    }
};

int main() {
    string nombre;
    cout << "Digite su nombre: ";
    cin >> nombre;
    
    Carrera carrera(200, nombre, 12); // 100 metros de distancia, dificultad 12
    carrera.iniciar();
}
