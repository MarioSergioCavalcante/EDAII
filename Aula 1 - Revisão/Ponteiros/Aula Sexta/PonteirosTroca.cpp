#include <iostream>

using namespace std;

void imprimeOsNumeros(int num1, int num2){
    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;
}

void troca(int num1, int num2){
    int aux = num1;
    num1 = num2;
    num2 = aux;
    cout << "Dentro da funcao: \n";
    imprimeOsNumeros(num1, num2);
}
int main(){
    int num1 = 2;
    int num2 = 8;
    imprimeOsNumeros(num1, num2);
    troca(num1, num2);
    cout << "Troca Realizada: \n"; 
    imprimeOsNumeros(num1, num2);

    return 0;
}