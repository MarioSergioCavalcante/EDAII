#include <iostream> 
#define TYPE char
using namespace std;

struct No{
    TYPE dado; 
    No *proximo;
};
//Função que criar No a partir de um dado que foi passado;
//pelo usuario
No* criaNo(TYPE dado){
    No *novo_no = new No(); //Criação dinâmica!
    novo_no->dado = dado;   //Inicializa com o dado passado pelo usuário
    novo_no->proximo = NULL; //Inicializa apontando para o vazio
    return novo_no;  //Retorna o endereço do Nó criado. 
}
//Cria uma variável que vai armazenar o endereço do topo da minha pilha
No *topo;

void push(TYPE dado){
    No *novo_no = criaNo(dado);
    novo_no->proximo = topo;
    topo = novo_no;
}
bool estaVazio(){
    return topo == NULL;
}
void printPilha(){
    if(estaVazio()){
        cout << "Pilha Vazia" << endl;
        return;
    }
    No *aux = topo;
    while(aux != NULL){
        cout << aux->dado << endl;
        aux = aux->proximo;
    }
    cout << "-----\n";
}

TYPE pop(){
    if(estaVazio()){
        cout << "Pilha Vazia" << endl;
        return 0;
    }
    No *removido = topo;
    TYPE dado_removido = removido->dado;
    topo = removido->proximo;
    delete(removido);
    return dado_removido;
}

