#include <iostream>
using namespace std;

struct Ponto{
    float x, y;
};

int main(){

    Ponto a;
    a.x = 1;
    //nome_da_variavel.membro = valor;
    a.y = 1;
    cout << "Ponto A  = " << a.x << " , " << a.y << endl;
    Ponto b = {0.5, 0.8};
    cout <<"Ponto B = " << b.x <<" , " << b.y << endl;
    Ponto c;
    cout << "Digite o valor do X do ponto C: ";
    cin >> c.x;
    cout << "Digite o valor do Y do ponto C: ";
    cin >> c.y;
    cout <<"Ponto C = " << c.x <<" , " << c.y << endl;
    return 0;
}

// Utilizem a struct ponto para calcular a distancia entre dois
// pontos no eixo catesiano; 