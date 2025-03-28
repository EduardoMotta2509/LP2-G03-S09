#include <iostream>
using namespace std;

class Rueda {
    private:
        float tamano;
    public:
    Rueda(float _tamano = 0){
        tamano= _tamano;
    }
     void setTamano(float _tamano){
        tamano= _tamano;
     }
     float getTamano(){
        return tamano;
     }
};

class Carro {
    private:
        Rueda rueda1, rueda2, rueda3, rueda 4
        bool Moviendose;
    public:
        Carro(float tamanoRueda) : rueda1(tamanoRueda), rueda2(tamanoRueda), rueda3(tamanoRueda), rueda4(tamanoRueda){
            Moviendose= false;
        }
        void mover(){
            if (!Moviendose){
                Moviendose= true;
                cout<<"El auto está en movimiento.\n"<<endl;
            }
            else{
                cout<<"El auto ya se está moviendo. \n"<<endl;
            }
        }

        void detener(){
            if (Moviendose){
                Moviendose= false;
                cout<<"El auto se ha detenido. \n"<<endl;
            }
            else{
                cout<<"El auto ya estaba detenido.\n"<<endl;
            }
        }

        void CambiarRueda(int num, float nuevoTamano){
            if (Moviendose){
                cout<<"No puede cambiarse de ruedas mientras que siga en movimiento el coche. \n"<<endl;
                return;
            }
            switch(num){
                case 1: rueda1.setTamano(nuevoTamano); break;
                case 2: rueda2.setTamano(nuevoTamano); break;
                case 3: rueda3.setTamano(nuevoTamano); break;
                case 4: rueda4.setTamano(nuevoTamano); break;
                default: cout<<"Número de rueda inválido. \n"<<endl;
                return;
            }
            cout<<"Rueda"<<num<<" ha sido cambiada con éxito"<<endl;
        }

};

int main(){
    Carro propioCarro(15);
    propioCarro.mover();
    propioCarro.CambiarRueda(3,20);
    propioCarro.detener();
    propioCarro.CambiarRueda(3,20);
    return 0;
}