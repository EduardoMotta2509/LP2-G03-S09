#ifndef SISTEMAENTREGA_H
#define SISTEMA ENTREGA_H

#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class SistemaEntrega {
private:
    vector<T> puntosParada;
    T puntoInicio;
    T puntoFinal;

public:
    SistemaEntrega(T inicio, T fin, vector<T> paradas) : puntoInicio(inicio), puntoFinal(fin), puntosParada(paradas) {}

    void generarInforme(){
        cout << "\n====== INFORME DEL SISTEMA DE ENTREGA ======" << endl;
        if (puntoInicio==0){
            cout<<"Punto de patida en su ubicación actual"<<endl;
        } else {
            cout << "Punto de inicio: " << puntoInicio << "m" << endl;
        }
        

        for (int i = 0; i < puntosParada.size(); ++i){
            cout << "  Parada " << i + 1 << ": " << puntosParada[i] << "m" << endl;
        }

        cout << "Punto final: " << puntoFinal << "m" << endl;

        T distanciaTotal = calcularDistancia(puntoInicio, puntosParada[0]);
        for (size_t i = 0; i < puntosParada.size() - 1; ++i){
            distanciaTotal += calcularDistancia(puntosParada[i], puntosParada[i+1]);
        }
        distanciaTotal += calcularDistancia(puntosParada.back(), puntoFinal);

        cout << "Distancia total: " << distanciaTotal << "m" << endl;
        calcularTiempoEntrega(distanciaTotal);
        cout << "=============================================\n";
    }

    template <typename U>
        U calcularDistancia(U puntoA, U puntoB){
            return (puntoA > puntoB) ? (puntoA - puntoB) : (puntoB - puntoA);
    }
    
    template <typename V>
    void calcularTiempoEntrega(V distancia){
        if(distancia == 0){
            cout << "Su pedido ya llegó a su destino" << endl;
        } else {
            if(distancia > 60){
                cout << "Tiempo estimado: " << (distancia * 0.7) / 60 << " - " << (distancia * 1.3) / 60 << " horas" << endl;
            } else {
                cout << "Tiempo estimado: " << distancia * 0.7 << " - " << distancia * 1.3 << " minutos" << endl;
            }
        }
    }
    
    void agregarPuntoParada(T nuevoPunto){
        puntosParada.push_back(nuevoPunto);
    }
};
#endif