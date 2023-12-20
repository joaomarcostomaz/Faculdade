#include "../include/pilha.hpp"
#include <cstdlib>
#include <ctime>
#define MAXTAM 10

using namespace std;


int main(){
    srand(time(0));
    Pilha p;

    Fila_circular f;

    
    for(int i = 0; i < MAXTAM; i++){
        int valor = rand() % 10;
        p.Empilha(valor);
        cout << "o valor "<< valor << " foi inserido"<< endl;
    }
    p.Imprime();

    for(int i = 1; i < MAXTAM; i++){
        p.get_top();
        p.Desempilha();
        //p.Imprime();
    }

    p.Empilha(7);
    cout << "o valor 7 foi inserido"<< endl;
    p.Empilha(5);
    cout << "o valor 5 foi inserido"<< endl;
    p.Empilha(9);
    cout << "o valor 9 foi inserido"<< endl;

    p.Destroi();
    //p.Imprime();


}