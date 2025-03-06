#include <iostream>
using namespace std;
//Faça um código que recebe dois numeros do usuário, 
//e depois calcula a soma desses dois números;
//depois calcule a subtraçao desses dois numeros;
//e depois a soma novamente. 

float somaDoisNumeros(float num1, float y){
    float soma = num1 + y;
    return soma;
}

float subtracoDoisNumeros(float numero1, float num2){
    return numero1 - num2;
}
int main(){
    float num1, num2;
    cout << "Digite o numero 1: "; 
    cin >> num1;
    cout << "Digite o numero 2: ";
    cin >> num2;
    float soma1 = somaDoisNumeros(num1, num2);
    float sub = num1 - num2;
    cout << "Digite o numero 1: "; 
    cin >> num1;
    cout << "Digite o numero 2: ";
    cin >> num2;
    float soma2 = somaDoisNumeros(num1, num2);
    cout << "Soma1 : " << soma1 << endl;
    cout << "sub: " << sub << endl;
    cout << "Soma2: " << soma2 << endl;
    return 0;
}