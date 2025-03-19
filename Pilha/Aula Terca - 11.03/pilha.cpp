#include <iostream>
#include <cstdlib>
#define TAM 5  //macro de definição
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

char pop(char* pilha, int *topo){
    if(estaVazia(*topo)){ //Verificar se a pilha está vazia!
        cout << "A pilha está vazia!\n";//Se tiver, imprimir uma mensagem dizendo que a pilha está vazia
        return 'E';  //Informa 'E', caso haja um erro na retirada de um elemento
    }
    //Senão, criar uma variável auxiliar, que vai guardar o topo da pilha;
    char aux = pilha[(*topo)];
    //Dimininuir o topo da pilha
    (*topo) = (*topo) - 1;
    //Retornar a variável auxiliar.
    return aux;
}

int main(){
    system("cls");
    char pilha[TAM];
    int topo = -1; //Guarda a posição do meu vetor que é o topo da pilha;
    push(pilha, &topo, 'a');
    push(pilha, &topo, 'b');
    push(pilha, &topo, 'c');
    push(pilha, &topo, 'd');
    push(pilha, &topo, 'e');
    push(pilha, &topo, 'f');
    
    
    
    print(pilha, topo);
    cout << "O elemento retirado foi: " << pop(pilha, &topo) << endl;
    print(pilha, topo);
    push(pilha, &topo, 'f');
    print(pilha, topo);
    return 0;
}