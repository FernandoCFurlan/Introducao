#include <iostream>
using namespace std;
#include "arvore.h"

int main()
{
    Tarvore <char> arv;
    inicializa(arv);
    insere(arv.raiz, 'a', 0);
    insere(arv.raiz, 'f', 1);
    insere(arv.raiz, 'c', 2);
    insere(arv.raiz, 'g', 3);
    insere(arv.raiz, 'e', -1);
    insere(arv.raiz, 'b', -2);
    insere(arv.raiz, 'd', -3);
    imprime(arv.raiz);
    cout<<endl<<altura(arv.raiz)<<endl;
    busca_remove(arv.raiz, 2);
    imprime(arv.raiz);
    cout<<endl<<altura(arv.raiz)<<endl;


    return 0;
}
