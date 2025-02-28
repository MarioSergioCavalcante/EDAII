#include <iostream>
using namespace std;

float calculoDoIMC(float peso, float altura){
    float resultado_imc = peso/(altura*altura);
    return resultado_imc;
}

void classificarIMC(float imc){
    if(imc < 18.5){
        cout << "Abaixo do Peso" << endl;
    }else{
        if(imc < 24.9){
            cout << "Peso normal" << endl;
        }else{
            if(imc < 29.9){
                cout << "Sobrepeso" << endl;
            }else{
                if(imc < 39.9){
                    cout << "Obesidade" << endl;
                }else{
                    cout << "Obesidade Grave" << endl;
                }
            }
        }
    }
}
int main(){
    float altura, peso; 
    cout << "Digite a altura: ";
    cin >> altura;
    cout << "Digite o peso: ";
    cin >> peso;
    float imc = calculoDoIMC(peso, altura);
    cout << "Seu IMC deu: " << imc << endl;
    classificarIMC(imc);  
    return 0;
}