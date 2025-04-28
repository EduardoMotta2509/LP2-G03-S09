#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <vector>
using namespace std;
class Tienda{
private:
    string nombre;
    string direccion;
    string tipoDeTienda;
    vector<string> productos;
    int stock;
public:
    Tienda(string _nombre, string _direccion, string _tipoDeTienda, vector<string> _productos, int _stock){
        nombre=_nombre;
        direccion=_direccion;
        tipoDeTienda=_tipoDeTienda;
        productos=_productos;
        stock=_stock;
    }
    void venderProducto(int cant, string _producto){
        for (int i=0; i<productos.size();i++){
            if(productos[i]==_producto){
                cout<<"···························"<<endl;
                cout<<"Se vendieron "<<cant<<" "<<productos[i]<<endl;
                stock=stock-cant;
                cout<<"Nuevo stock: "<<stock<<endl;
                cout<<"···························"<<endl;
            }
        }
        
    }
    void agregarProducto(string _nuevo){
        cout<<"---------------"<<endl;
        cout<<"Se agregó ("<<_nuevo<<") a la lista de productos"<<endl;
        cout<<"STOCK: "<<stock<<endl;
        for (int i=0; i<productos.size();i++){
            cout<<"     "<<i+1<<".- "<<productos[i]<<endl;
        }
        productos.push_back(_nuevo);
        cout<<"NUEVA lista de productos: "<<endl;
        for (int i=0; i<productos.size();i++){
            cout<<"     "<<i+1<<".- "<<productos[i]<<endl;
        }
        cout<<"---------------"<<endl;
    }
};
#endif