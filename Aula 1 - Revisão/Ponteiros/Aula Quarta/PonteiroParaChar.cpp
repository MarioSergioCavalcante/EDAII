#include <iostream>

using namespace std;

int main(){
    char letra_1;
    letra_1 = 'c';
    char *pletra;
    pletra = &letra_1;
    cout <<"O valor armazenado na variavel e: " << letra_1 << endl;
    cout <<"O endereco dessa variavel e: " << &letra_1 << endl;
    cout << "O valor do ponteiro eh: " << pletra << endl;
    cout << "O valor armazenado: " << (*pletra) << endl;
    
    return 0;
}