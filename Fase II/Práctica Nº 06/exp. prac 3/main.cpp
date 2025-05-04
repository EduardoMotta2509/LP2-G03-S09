#include <iostream>
using namespace std;

class Banco{
private:
    static float tasaInteres;
public:
    Banco() {};

    static void setTasaInteres(float t){
        tasaInteres = t;
        cout<<"Tasa de interes cambiada a: "<< t <<endl;
    }

    static float getTasa(){ return tasaInteres; }
};

//Inicializamos la Tasa de interes
float Banco::tasaInteres = 0.0;

class CuentaBancaria{
private:
    float saldo;
    Banco banco;
public:
    CuentaBancaria(float s, Banco b): saldo(s), banco(b){}

    void realizarDeposito(float cant){
        saldo=saldo+cant;
        cout<<"Se depositó: S/."<<cant<<endl;
    }
    void realizarRetiro(float cant){
        if (saldo>=cant){
            saldo=saldo-cant;
            cout<<"Se retiró: S/."<<cant<<endl;
        }
        else{
            cout<<"Cantidad supera al saldo."<<endl;
        }
    }

    void calcularInteresGanado(float tiempoAnios){
        float interesGanado = saldo * banco.getTasa() * tiempoAnios;
        cout<<"El interes ganado en "<<tiempoAnios<<" años será de: S/."<<interesGanado<<endl;
    }
};

int main(){
    
    Banco b1;
    b1.setTasaInteres(1.5);

    CuentaBancaria c1(200.50, b1);
    c1.realizarRetiro(100);
    c1.realizarDeposito(10);
    c1.calcularInteresGanado(1.2);

    return 0;
}
    