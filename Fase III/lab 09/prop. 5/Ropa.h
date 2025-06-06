#ifndef ROPA_H
#define ROPA_H

#include <iostream>
using namespace std;
#include "Producto.h"

class Ropa: public Producto {
private:
    string genero;
    string talla;
    bool importado;
    string publico;
    bool ofertaAgotada;
public:
    Ropa(string _nombre, float _precio, string _medida, int _stock, string gen, string tall, bool import, string pub, bool ago): Producto(_nombre, _precio, _medida, _stock), genero(gen), talla(tall), importado(import), publico(pub), ofertaAgotada(ago) {}

    
    virtual float calcularPrecioInventario() override {
        return precio*stock;
    }
    virtual float aplicarDescuento(int cantidadSolicitada) override {
        float precioFinal;
        if(stock<cantidadSolicitada){
            cout<<"ERROR: La cantidad solicitada mayor al stock disponible"<<endl;
        }
        else{
            do{
                if(cantidadSolicitada==2){
                    cout<<"\n";
                    cout<<"Usted solicitó "<<cantidadSolicitada<<" "<<medida<<" de "<<nombre<<"s"<<endl;
                    cout<<"Aplicando descuento 2x1..."<<endl;
                    precioFinal=cantidadSolicitada/2*precio;
                    cout<<"El precio con del descuento pasó de S/."<<cantidadSolicitada*precio<<" a S/."<<precioFinal<<endl;
                    ofertaAgotada=true;
                }
                else if (cantidadSolicitada*precio>=49.90){
                    cout<<"\n";
                    cout<<"Usted solicitó "<<cantidadSolicitada<<" "<<medida<<" de "<<nombre<<"s"<<endl;
                    cout<<"Aplicando descuento para compras mayores a 49.90 (15%)..."<<endl;
                    precioFinal=cantidadSolicitada*precio*0.15;
                    cout<<"El precio con del descuento pasó de S/."<<cantidadSolicitada*precio<<" a S/."<<precioFinal<<endl;
                    ofertaAgotada=true;
                }
                else if (genero=="varon" && publico=="adultos"){
                    cout<<"\n";
                    cout<<"Usted solicitó "<<cantidadSolicitada<<" "<<medida<<" de "<<nombre<<"s"<<endl;
                    cout<<"Aplicando descuento para ropa de adultos varones (20%)..."<<endl;
                    precioFinal=cantidadSolicitada*precio*0.2;
                    cout<<"El precio con del descuento pasó de S/."<<cantidadSolicitada*precio<<" a S/."<<precioFinal<<endl;
                    ofertaAgotada=true;
                }
            } while (ofertaAgotada==false);    
            stock=stock-cantidadSolicitada;
        }
        return precioFinal;
    }
    void mostrarInfo() override {
        Producto::mostrarInfo();
        cout<<"\n";
        cout<<"     Informacion especial de la categoría ROPA:"<<endl;
        cout<<"     Genero: "<<genero<<endl;
        cout<<"     Talla: "<<talla<<endl;
        cout<<"     Publico: "<<publico<<endl;
        if (importado==true){
            cout<<"     -Protucto importado-"<<endl;
        }else{
            cout<<"     -Protucto peruano-"<<endl;
        }

    }
};
#endif