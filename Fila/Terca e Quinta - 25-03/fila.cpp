#include<iostream>
#define TAM 5
using namespace std;

bool estaCheia(int qtd){
    return qtd == TAM;
}

bool estaVazia(int qtd){
    return qtd == 0;
}

void imprimeFila(int *fila, int frente, int quantidade){

    int indice = frente;
    for(int i = 0; i < quantidade; i++){
        cout << fila[indice] << " -> "; 
        indice = (indice + 1) % TAM;
    }
    cout << endl;
}

int main(){
    system("cls");
    int fila[TAM] = {1,2,3,4,5};
    int frente,  tras;
    int quantidade = 5;
    
    frente = tras = 0; //C++ 
    frente = 2;
    tras = 1;
    cout << "Esta vazia? " << estaVazia(quantidade) << endl;
    cout << "Esta cheia? " << estaCheia(quantidade) << endl;
    imprimeFila(fila, frente,quantidade);
    return 0;
}