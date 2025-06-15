#include <iostream>
using namespace std;
#include <vector>
#include "Entrega.h"

int Entrega::codigo=1000;

template <typename T>
T calcularDistancia(T puntoA, T puntoB){
    return (puntoA > puntoB) ? (puntoA-puntoB) : (puntoB-puntoA);
}

template <typename T>
void calcularTiempoEntrega(T distancia){
    if(distancia==0){
        cout<<"Su pedido ya llegó a su destino"<<endl;
    }
    else{
        if(distancia>60){
            cout<<"El tiempo estimado de entrega es de "<<(distancia*0.7)/60<<" - "<<(distancia*1.3)/60<<" horas"<<endl;
        } else{
            cout<<"El tiempo estimado de entrega es de "<<distancia*0.7<<" - "<<distancia*1.3<<" minutos"<<endl;
        }
        
    }
}

template <typename T, typename U, typename V>
void generarInforme(T puntoPartida, U puntoEntrega, vector<V> puntosParada){
    cout<<"\n"<<"------------INFORME DE ENTREGA------------"<<endl;
    cout<<"Punto de partida a "<<puntoPartida<<"m  de distancia"<<endl;
    for(int i=0; i<puntosParada.size(); i++){
        cout<<"     Punto de parada "<<i+1<<": a "<<puntosParada[i]<<"m de distancia"<<endl;
    }
    if(puntoEntrega == 0){
        cout<<"Punto de entrega en su ubicación actual."<<endl;
    } else{
        cout<<"Punto de entrega a "<<puntoEntrega<<"m de distancia"<<endl;
    }
    

    V sumaTotal=0;
    for (int i=0; i<puntosParada.size(); i++){
        //cout<<i<<". "<<sumaTotal<<" + "<<puntosParada[i];
        sumaTotal = sumaTotal + puntosParada[i];
        //cout<<" = "<<sumaTotal<<endl;
        
    }
    cout<<"Distancia de la entrega: "<<sumaTotal<<"m de distancia"<<endl;
    calcularTiempoEntrega(sumaTotal);
    cout<<"\n";
}

int main(){
    Entrega e1;
    e1.asignarVehiculo("Camión - ABC123");
    e1.asignarVehiculo(202);
    e1.planificarHorario("10:30 a.m.");
    e1.planificarHorario(1430);

    vector<int> paradas1 = {20, 15, 25};
    generarInforme(100, 0, paradas1);

    vector<float> paradas2 = {2.5, 4.5, 1.3};
    generarInforme(50.2, 10.5, paradas2);

    return 0;
}