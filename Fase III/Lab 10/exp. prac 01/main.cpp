#include <iostream>
using namespace std;
#include <vector>

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
    int a = 20;
    int b = 10;

    cout<<"La distancia entre "<<a<<" y "<<b<<" es "<<calcularDistancia(a,b)<<"."<<endl;
    cout<<"Tiempo de entrega del pedido a "<<a<<"m de distancia"<<endl;
    calcularTiempoEntrega(a);
    cout<<"Tiempo de entrega del pedido a "<<b<<"m de distancia"<<endl;
    calcularTiempoEntrega(b);

    float c = 30.6;
    float d = 21.909;
    cout<<"La distancia entre "<<c<<" y "<<d<<" es "<<calcularDistancia(c,d)<<"."<<endl;
    cout<<"Tiempo de entrega del pedido a "<<c<<"m de distancia"<<endl;
    calcularTiempoEntrega(c);
    cout<<"Tiempo de entrega del pedido a "<<d<<"m de distancia"<<endl;
    calcularTiempoEntrega(d);

    vector<int> puntosParada1 = {50, 40, 30, 20, 2};
    generarInforme(100, 0, puntosParada1);
    
    vector<float> puntosParada2 = {2.3543, 5.124, 2.124};
    generarInforme(100.2143, 10.2, puntosParada2);

    return 0;
}