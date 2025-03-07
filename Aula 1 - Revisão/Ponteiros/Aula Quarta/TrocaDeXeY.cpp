#include <iostream>

using namespace std;


void imprimeXY(char x, char y){
    cout << "X: " << x << endl << "Y: " << y << endl;
}

void troca(char x, char y){
    char aux = x; 
    x = y;
    y = aux;
}
int main(){
    char x, y; 
    x = 'a';
    y = 'z';
    cout << "Valores de X e Y antes da troca: " << endl; 
    imprimeXY(x, y);
    troca(x, y);
    cout << "Valores de X e Y apos a troca: " << endl;
    imprimeXY(x,y);
    return 0;

}