#include <iostream>
#include <cstring>
#include "Pilha.cpp"
using namespace std;


bool checaPalindromo(char *palavra){
    for(int i = 0; i< strlen(palavra); i++){
        push(palavra[i]); //Serve para eu empilhar letra a letra. 
    }
    for(int i = 0; i < strlen(palavra); i++){
        if(palavra[i] != pop()){
            return false;
        }
    }
    return true;
}

int main(){
    topo = NULL;
    char palavra[100]; //Vetor de caracteres, ou seja, string
    cout << "Digite a palavra: ";
    cin >> palavra;
    if(checaPalindromo(palavra)){
        cout << "Eh palindromo" << endl;
    }else{
        cout << "Nao eh palindromo" << endl;
    }
    return 0;
}