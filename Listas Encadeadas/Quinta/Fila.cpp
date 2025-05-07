#include <iostream>
#define TYPE char
using namespace std;


struct No{
    TYPE dado;
    No* proximo;
};
No* frente;
No* tras;
No* criarNovoNo(TYPE dado_do_novo_no){
    No* novo_no = new No();
    novo_no->dado = dado_do_novo_no;
    novo_no->proximo = NULL;
    return novo_no;
}

void enfileira(TYPE novo_dado){
    No* novo_no = criarNovoNo(novo_dado);
    if(frente == NULL){
        frente = novo_no;
        tras = novo_no;
        return;
    }
        tras->proximo = novo_no;
        tras = novo_no;
    
}

void imprimeFila(){
    No *aux = frente;
    while(aux != NULL){
        cout << aux->dado << " -> ";
        aux = aux->proximo;
    }
    cout << "NULL" << endl;
    cout << "---------\n";
}

TYPE desinfileira(){
    if(frente == NULL){
        cout<< "Impossivel remover, FILA VAZIA! " << endl;
        return 0;
    }
    No* removido = frente;
    frente = removido->proximo;
    return removido->dado;

}
int main(){
    frente = NULL;
    tras = NULL;
    enfileira(3.2);
    enfileira(4.1);
    imprimeFila();
    enfileira(0);
    enfileira(4.2);
    imprimeFila();
    cout << "Removendo a letra da frente: " << desinfileira() << endl;
    imprimeFila();
    cout << "Removendo a letra da frente: " << desinfileira() << endl;
    imprimeFila();
    cout << "Removendo a letra da frente: " << desinfileira() << endl;
    imprimeFila();
    cout << "Removendo a letra da frente: " << desinfileira() << endl;
    imprimeFila();

}