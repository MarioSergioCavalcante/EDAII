#include <iostream>
#include "Pilha.cpp"
using namespace std;


void convert2Bin(int numero){
    topo = NULL;
    
    while(numero > 1){
        push(numero % 2);
        numero = numero / 2;
    }
    push(numero);
    while(topo != NULL){
        cout << topo->dado;
        topo = topo->proximo;
    }
    cout << endl;
}   

int main(){
    int numero;
    cout << "Digite o número";
    cin >> numero;
    cout << "O numero em binario eh: ";
    convert2Bin(numero);
}