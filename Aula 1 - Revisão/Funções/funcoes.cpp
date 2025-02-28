#include <iostream>
using namespace std;

//tipo nomeFuncao(parametros)
//tipo: inteiro
//nome: soma
//parametros: x é um inteiro, y é inteiro
int soma(int x, int y){
    int resultado = x + y;
    return resultado;
} 

int subtracao(int x, int y){
    int resultado = x - y;
    return resultado;
}

int DizOi(){
    cout << "Oi!" << endl; 
    return 0;
}

void imprimeDoisNumeros(int x, int y){
    cout << "Numero 1: " << x;
    cout << "\nNumero 2: " << y;
}
void imprimeHelloWorld(){
    cout << "Hello World! " << endl;
}
int main(){
    int num1 = 10;
    int num2 = 5;

    int resultado_soma = soma(num1, num2);
    cout << "Resultado Soma: " << resultado_soma << endl;
    int resultado_sub = subtracao(num1, num2);
    cout << "Resultado Sub: " << resultado_sub << endl;


    return 0;
}