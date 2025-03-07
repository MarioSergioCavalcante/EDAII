#include <iostream>

using namespace std;

int main(){
    const int tam = 5000;
    cout << "Oxi: " << endl;
    int *vetor = new int(tam); 
    for(int i = 0; i < tam; i++){
        vetor[i] = i;
    }
    cout << "Vetor: "; 
    for(int i = 0; i < tam; i++){
        cout << vetor[i] << " ";
    }
    delete(vetor);
    return 0;
}