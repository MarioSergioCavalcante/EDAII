#include <iostream>
#include <cstring>
#include "funcoes.cpp"
#include <cstdlib>
int main(){
    system("cls");
    char parenteses[TAM]; //Minha pilha de Tamanho definido
    int topo = -1;
    char equacao[TAM];
    cout << "Digite a equacao: ";
    cin >> equacao;
   for(int i = 0; i < strlen(equacao);i++){
        if(equacao[i] == '('){
            push(parenteses, &topo, '(');
        }else{
            if(equacao[i] == ')'){
                if(estaVazia(topo)){
                    cout << "Desbalanceada! "; 
                    exit(0);
                }
                pop(parenteses, &topo);
            }
        }   
   }
   if(estaVazia(topo)){
        cout << "Balanceada! " << endl;
   }else{
        cout << "Desbalanceada! " << endl;
   }
   return 0;
}