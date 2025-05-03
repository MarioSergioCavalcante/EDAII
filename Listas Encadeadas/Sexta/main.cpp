#include <iostream>
#include "Pilha.cpp"
using namespace std;

int main(){
    topo = NULL;
    for(char letra = 'A'; letra <= 'Z'; letra++){
        push(letra);   
    }

    printPilha();
    while(topo != NULL){
        cout << "Dado removido: " << pop() << endl;
    }

    printPilha();

    return 0;
}