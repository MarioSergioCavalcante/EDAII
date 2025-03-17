#include <iostream>
#include <cstdlib>
#define TAM 5
using namespace std;

bool estaCheia(int qtd){
    return qtd == TAM;
}

bool estaVazia(int qtd){
    return qtd == 0;
}

void imprimeFila(char* fila, int frente, int qtd){
    if(estaVazia(qtd)){
        cout << "A fila esta vazia" << endl;
        return;
    }
    int index = frente;
    for(int i = 0; i < qtd; i++){
        cout << fila[index] << " -> ";
        index = (index + 1) % TAM;
    }
}
int main(){
    system("cls");
    char fila[TAM] = {'A','B','C','D','E'};
    int frente = 2, final = 1;
    int quantidade = 5; //Quantos elementos estão presentes na minha fila
    cout << "A fila esta vazia? " << estaVazia(quantidade) << endl;
    cout << "A fila esta cheia? " << estaCheia(quantidade) << endl;
    cout << "Imprimir a lista: " << endl;
    imprimeFila(fila, frente, quantidade);
 
}