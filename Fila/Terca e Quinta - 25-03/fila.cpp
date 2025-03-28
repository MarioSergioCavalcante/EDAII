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
    if(quantidade == 0){
        cout << "Fila vazia\n"; 
        return;
    }
    int indice = frente;
    for(int i = 0; i < quantidade; i++){
        cout << fila[indice] << " -> "; 
        indice = (indice + 1) % TAM;
    }
    cout << endl;
}

void enfileira(int *fila, int *qtd, int *tras, int valor){
    if(estaCheia(*qtd)){
        cout << "Não é possivel inserir nenhum elemento, porque a fila esta cheia" << endl;
        return; // return em função funciona como um break, para a execução da função
    }
    fila[(*tras)] = valor;
    (*tras) = ((*tras) + 1)  % TAM;
    (*qtd)++;
}

void desinfileira(int *fila, int *qtd, int *frente){
    if(estaVazia(*qtd)){
        cout << "Não possivel retirar nenhum elemento" << endl;
        return;
    }
    int auxiliar = fila[*frente];
    cout << "O valor retirado foi: " << auxiliar << endl;
    (*frente) = ((*frente) + 1) % TAM;
    (*qtd)--;
}


int main(){
    system("cls");
    int fila[TAM];
    int frente,  tras;
    int quantidade = 0;
    
    frente = 0;
    tras = 0;
    cout << "Esta vazia? " << estaVazia(quantidade) << endl;
    cout << "Esta cheia? " << estaCheia(quantidade) << endl;
    imprimeFila(fila, frente,quantidade);
    cout << "Acrescentando o elemento 10: "<< endl; 
    enfileira(fila, &quantidade, &tras, 10);
    imprimeFila(fila, frente, quantidade);
    enfileira(fila, &quantidade, &tras, 22);
    imprimeFila(fila, frente, quantidade);
    enfileira(fila, &quantidade, &tras, -10);
    imprimeFila(fila, frente, quantidade);
    enfileira(fila, &quantidade, &tras, -31);
    imprimeFila(fila, frente, quantidade);

    enfileira(fila, &quantidade, &tras, 90);
    imprimeFila(fila, frente, quantidade);

    desinfileira(fila, &quantidade, &frente);
    imprimeFila(fila, frente, quantidade);

    enfileira(fila, &quantidade, &tras, 0);
    imprimeFila(fila, frente, quantidade);

    desinfileira(fila, &quantidade, &frente);
    imprimeFila(fila, frente, quantidade);


    desinfileira(fila, &quantidade, &frente);
    imprimeFila(fila, frente, quantidade);



    return 0;
}