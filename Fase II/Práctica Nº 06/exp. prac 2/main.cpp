#include <iostream>
using namespace std;

class Circulo{
private:
    float radio;
    float diametro;
public:
    Circulo(float r): radio(r), diametro(2*r){}

    float calcArea(){
        float area = 3.14*radio*radio;
        return area;
    }
};

int main(){
    Circulo c1(20.3);
    float area1 = c1.calcArea();
    cout<<"Area 1 = "<<area1<<" u^2"<<endl;
    
    Circulo c2(2);
    float area2 = c2.calcArea();
    cout<<"Area 2 = "<<area2<<" u^2"<<endl;
    
    Circulo c3(25.6);
    float area3 = c3.calcArea();
    cout<<"Area 3 = "<<area3<<" u^2"<<endl;
    return 0;
}

    