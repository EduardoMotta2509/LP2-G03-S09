#include <iostream>
using namespace std;
#include <string>

class Vector2D{
public:
    int x;
    int y;

    Vector2D(int _x, int _y): x(_x), y(_y){}

    Vector2D operator + (const Vector2D& otro) const {
        return Vector2D(x+otro.x, y+otro.y);
    }
    
    Vector2D operator - (const Vector2D& otro) const {
        return Vector2D(x-otro.x, y-otro.y);
    }
    
    string mostrarVector(){
        string compX= to_string(x);
        string compY= to_string(y);
        return "Vector: V("+compX+", "+compY+") ";
    }
};

int main(){
    Vector2D v1(5,7);
    Vector2D v2(4,5);

    Vector2D suma = v1+v2;
    Vector2D resta = v1-v2;

    cout<<"La suma es: "<<suma.mostrarVector()<<endl;
    cout<<"La resta es: "<<resta.mostrarVector()<<endl;

    return 0;
}
    