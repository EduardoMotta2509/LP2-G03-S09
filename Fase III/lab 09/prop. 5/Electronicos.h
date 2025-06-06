#ifndef ELECTRONICOS_H
#define ELECTRONICOS_H

#include <iostream>
using namespace std;
#include "Producto.h"

class Electronicos: public Producto {
private:
    float voltaje;
    string gama;
    bool importado;
public:
    Electronicos(string _nombre, float _precio, string _medida, int _stock, float vol, string gam, bool import): Producto(_nombre, _precio, _medida, _stock), voltaje(vol), gama(gam), importado(import) {}

    
    virtual float calcularPrecioInventario() override {
        return precio*stock;
    }
    virtual float aplicarDescuento(int cantidadSolicitada) override {
        float precioFinal;
        if(stock<cantidadSolicitada){
            cout<<"ERROR: La cantidad solicitada mayor al stock disponible"<<endl;
        }
        else{
            if(cantidadSolicitada>=5 && cantidadSolicitada<10){
                cout<<"\n";
                cout<<"Usted solicitó "<<cantidadSolicitada<<" "<<medida<<" de "<<nombre<<"s"<<endl;
                cout<<"Aplicando descuento para 5 o más unidades (15%)..."<<endl;
                precioFinal=cantidadSolicitada*precio*0.15;
                cout<<"El precio con del descuento pasó de S/."<<cantidadSolicitada*precio<<" a S/."<<precioFinal<<endl;
            }
            else if (cantidadSolicitada>=10 && cantidadSolicitada<25){
                cout<<"\n";
                cout<<"Usted solicitó "<<cantidadSolicitada<<" "<<medida<<" de "<<nombre<<"s"<<endl;
                cout<<"Aplicando descuento para 10 o más unidades (25%)..."<<endl;
                precioFinal=cantidadSolicitada*precio*0.25;
                cout<<"El precio con del descuento pasó de S/."<<cantidadSolicitada*precio<<" a S/."<<precioFinal<<endl;
            }
            else if (cantidadSolicitada>=25){
                cout<<"\n";
                cout<<"Usted solicitó "<<cantidadSolicitada<<" "<<medida<<" de "<<nombre<<"s"<<endl;
                cout<<"Aplicando descuento para 25 o más unidades (50%)..."<<endl;
                precioFinal=cantidadSolicitada*precio*0.5;
                cout<<"El precio con del descuento pasó de S/."<<cantidadSolicitada*precio<<" a S/."<<precioFinal<<endl;
            }
            stock=stock-cantidadSolicitada;
        }
        return precioFinal;
    }
    void mostrarInfo() override {
        Producto::mostrarInfo();
        cout<<"\n";
        cout<<"     Informacion especial de la categoría Electrónicos:"<<endl;
        cout<<"     Voltaje: "<<voltaje<<endl;
        cout<<"     Gama: "<<gama<<endl;
        if (importado==true){
            cout<<"     -Protucto importado-"<<endl;
        }else{
            cout<<"     -Protucto peruano-"<<endl;
        }

    }
};
#endif