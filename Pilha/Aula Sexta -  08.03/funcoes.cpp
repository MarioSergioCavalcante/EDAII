#include <iostream>
#include <cstdlib>
#define TAM 100 //macro de definição
using namespace std;

int estaVazia(int topo){
    if(topo == -1){
        return true;
    }
    return false;
}

int estaCheia(int topo){
    if(topo == (TAM - 1)){
        return true;
    }
    return false;
}

void print(char *pilha, int topo){
    if(estaVazia(topo)){
        cout << "Pilha Vazia" << endl;
        return;
    }

    for(int i = topo; i >= 0; i--){
        cout << pilha[i] << endl;
    }
    cout << endl;
    
}

void push(char *pilha,  int *topo, char dado){
    if(estaCheia(*topo)){
        cout << "Esta cheio" << endl;
        return; 
    }
    (*topo) = (*topo) + 1;
    pilha[(*topo)] = dado;
    cout << "O dado: " << dado << " foi adicionado a minha pilha" << endl;
}

char pop(char *pilha, int *topo){
    if(estaVazia(*topo)){
        cout << "Pilha Vazia";
        return 'E';
    }
    char value = pilha[(*topo)];
    (*topo)--;
    return value;
}