#include <iostream>
using namespace std; 

//tipo nome_funcao (parametros){
//parametros: tipo nome_do_parametro
//A sequencia de códigos que eu desejo que função realize
//}


//Tipo: void -> não tem retorno
//nome: imprimeMensagem
//parâmetros: nenhum
void imprimeMensagem(int opcao){
    cout << "Hello World!" << endl;
    if(opcao == 0){
        return;
    }
    cout << "Bem vindo aula de programacao" << endl;
}
int main(){
    imprimeMensagem(1);
    int a = 1; 
    int b = 2;
    imprimeMensagem(0);
    int c = a + b;
    imprimeMensagem(99);
    return 0;
}