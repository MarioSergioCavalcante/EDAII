#include <iostream>
using namespace std;

float calcularIMC(float peso, float altura){
    float imc = peso/(altura*altura);
    return imc;

}

void classificarIMC(float imc){
    if(imc < 18.5){
        cout << "Abaixo do peso" << endl;
    }else{
        if( imc < 24.9){
                cout << "Peso normal! "<< endl;
        }else{
            if(imc < 29.9){
                cout << "Sobrepeso" << endl;
            }else{
                if(imc < 39.9){
                    cout << "Obesidade" << endl;
                }else{
                    cout << "Obesidade Grave," << endl;
                }
            }
        }
    }
}

int main(){
    float peso, altura;
    cout << "Digite o peso (em kg): "; 
    cin >> peso;
    cout << "Digite a altura: ";
    cin >> altura;
    float imc = calcularIMC(peso, altura);
    cout << "Valor do IMC: "<< imc << endl;
    classificarIMC(imc);

    return 0;
}