#include <iostream>
#define TAM 5
using namespace std;

int isEmpty(int topo){
    if (topo == -1){
        return 1;
    }
    return 0;
}
int isFull(int topo){
    if(topo == (TAM - 1)){
        return 1;
    }else{
        return 0;
    }
}

void print(int *pilha, int topo){
    if(isEmpty(topo)){
        cout << "Pilha Vazia" << endl;
        return ;
    }

    for(int i = topo; i  >= 0; i--){
        cout << pilha[i] << endl;
    }
}

void push(int *pilha, int *topo, int dado){
    if(isFull((*topo))){
        cout << "Pilha Cheia" << endl;
        return ;
    }
    (*topo) = (*topo) + 1;
    pilha[(*topo)] = dado;
    cout << "O valor " << dado <<" foi adicionado" << endl;
}


int pop(int *pilha, int *topo){
    if(isEmpty(*topo)){
        cout << "Pilha Vazia"; 
        return  -9999;
    }
    int dado = pilha[(*topo)];
    (*topo) = (*topo) - 1;
    cout << "Valor removido: " << dado << endl;
    return dado;
}
int main(){
    int pilha[TAM];
    int topo = -1; //Indica que minha pilha está vazia
    push(pilha, &topo, 8);
    push(pilha, &topo, 7);
    push(pilha, &topo, 103);
    push(pilha, &topo, -85);
    push(pilha, &topo, -3);
    push(pilha, &topo, -9);
    print(pilha, topo);
    pop(pilha, &topo);
    print(pilha, topo);
    push(pilha, &topo, 10);
    print(pilha, topo);
    return 0;
}