#include <iostream>
#define TAM 10  //macro de definição
using namespace std;

int isEmpty(int topo){
    if(topo == -1){
        return true;
    }
    return false;
}

int isFull(int topo){
    if(topo == (TAM - 1)){
        return true;
    }
    return false;
}

void print(char *pilha, int topo){
    if(isEmpty(topo)){
        cout << "Pilha Vazia" << endl;
        return;
    }

    for(int i = topo; i >= 0; i--){
        cout << pilha[i] << endl;
    }
    cout << endl;
}

int main(){

    char pilha[TAM] = {'a','b','c'};
    int topo = 2; //Guarda a posição do meu vetor que é o topo da pilha;
    
    cout << "A pilha tá cheia? " << isFull(topo) << endl;
    cout << "A pilha está vazia? " << isEmpty(topo) << endl;
    print(pilha, topo);
    return 0;
}