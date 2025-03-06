#include <iostream>

using namespace std;

void imprimeOsNumeros(int num1, int num2){
    cout << "Num1: " << num1 << endl;
    cout << "Num2: " << num2 << endl;
}

void troca(int *num1, int *num2){
    int aux = (*num1);
    (*num1) = (*num2);
    (*num2) = aux;
}

int main(){
    int num1, num2;
    num1 = 2;
    num2 = 8;
    imprimeOsNumeros(num1, num2);
    troca(&num1, &num2);
    cout << "Depois da troca: " << endl;
    imprimeOsNumeros(num1, num2);

    return 0;
}