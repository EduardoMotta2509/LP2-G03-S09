#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>

using namespace std;

class Libro{
private:
    string titulo;
    string autor;
    int año;
public:
    int valoracion;
    Libro(string _titulo, string _autor, int _año, int _valoracion){
        titulo=_titulo;
        autor=_autor;
        año=_año;
        valoracion=_valoracion;
    }

    string getTitulo(){
        return titulo;
    }
    string getAutor(){
        return autor;
    }
    int getAño(){
        return año;
    }

    void setTitulo(string _titulo){
        titulo=_titulo;
    }
    void setAutor(string _autor){
        autor=_autor;
    }
    void setAño(int _año){
        año=_año;
    }

    bool esIgualA(const Libro& otro) const{
        return(titulo==otro.titulo && autor==otro.autor && año==otro.año && valoracion==otro.valoracion);
    }

    void mostrarInfo(){
        cout<<"·····························"<<endl;
        cout<<"     Título: "<<titulo<<endl;
        cout<<"     Autor: "<<autor<<endl;
        cout<<"     Año: "<<año<<endl;
        cout<<"     Valoración: "<<valoracion<<endl;
        cout<<"·····························"<<endl;
    }
};
#endif