#include <iostream>
#include <cmath>
//pow, sin, cos, cosh, sinh, sqrt, ... 
using namespace std;

struct Ponto{
    float x;
    float y;
};

int main(){
    Ponto p1, p2;
    cout << "Digite o valor de X do ponto p1: "; 
    cin >> p1.x;
    cout << "Digite o valor de Y do ponto p1: "; 
    cin >> p1.y;
    cout << "Digite o valor de X do ponto p2: "; 
    cin >> p2.x; 
    cout << "Digite o valor de Y do ponto p2: ";
    cin >> p2.y;
    //pow(base,expoente) -> base^expoente => pow(4,4) => 4*4*4*4
    float parte_x, parte_y;
    parte_x = pow(p1.x - p2.x, 2);
    parte_y = pow(p1.y - p2.y,2);
    
    float distancia = sqrt(parte_x + parte_y);
    cout << "Distancia = " << distancia; 

    return 0; 
}