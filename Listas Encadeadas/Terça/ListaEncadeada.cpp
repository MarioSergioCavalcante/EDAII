#include <iostream>
using namespace std;

struct No{
    char letra; 
    No* proximo;
};
No* topo; //Variável Global: 
          //todas as funções tem acesso a ela; 

No* criarNo(char letra){
   No* novo_no = new No(); 
   novo_no->letra = letra;
   novo_no->proximo = NULL;
   return novo_no;  
}

void push(char letra){
    No* novo_no = criarNo(letra);
    novo_no->proximo = topo;
    topo = novo_no;
}

void printPilha(){
    No* aux = topo;
    while(aux != NULL){
        cout << aux->letra << endl;
        aux = aux->proximo;
    }
}

char pop(){
    char letra_removida = topo->letra;
    topo = topo->proximo;
    return letra_removida;
}
int main(){
    topo = NULL;
    push('A');
    push('B');
    push('C');
    push('D');
    printPilha();
    cout << "Letra removida: " << pop() << endl;
    cout << "Letra removida: " << pop() << endl;
    cout << "Letra removida: " << pop() << endl;
    printPilha();
    return 0;
}