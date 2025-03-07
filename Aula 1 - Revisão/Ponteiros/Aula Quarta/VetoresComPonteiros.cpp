#include <iostream> 

using namespace std;


int main(){

    int *vetor = new int(5);

    for(int i = 0; i < 5; i++){
        vetor[i] = i;
    }

    for(int i = 0; i < 5; i++){
        cout << vetor[i] << " ";
    }

    return 0;
}