#include <iostream>
using namespace std;

int main(){
    int idade = 10;
    //tipo *nome_do_ponteiro;
    int *ponteiro_idade = &idade;
    cout << "O valor da idade eh: " << idade << endl;
    cout << "A posicao da idade eh: " << &idade << endl;
    cout << "O valor do ponteiro: " << ponteiro_idade << endl;
    cout << "O valor armazenado no endereco de memoria: " << (*ponteiro_idade) << endl;
    cout << "Idade + 2: " << (*ponteiro_idade) + 2 << endl;
    return 0;
}