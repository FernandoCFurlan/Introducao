#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

template <typename TIPO>
struct TelementoP
{
    TIPO dado;
    TelementoP <TIPO> *prx;
};

template <typename TIPO>
struct Tpilha
{
    TelementoP <TIPO> *inicio;
    int qtd;
};

template <typename TIPO>
void inicializarP(Tpilha <TIPO> &pilha)
{
    pilha.inicio = NULL;
    pilha.qtd=0;
}

template <typename TIPO>
TelementoP <TIPO> *novo_eleP (TIPO dado)
{
    TelementoP <TIPO> *novo = new TelementoP <TIPO> ;
    novo->dado = dado;
    novo->prx = NULL;
    return novo;
}

template <typename TIPO>
void insere_inicio (Tpilha <TIPO> &pilha, TIPO dado)
{
    TelementoP <TIPO> *novo = novo_eleP(dado);
    novo->prx = pilha.inicio;
    pilha.inicio = novo;
    pilha.qtd++;
}

template <typename TIPO>
TIPO remove_inicioP (Tpilha <TIPO> &pilha)
{
    TIPO aux = pilha.inicio->dado;
    TelementoP <TIPO> *nav = pilha.inicio;
    pilha.inicio = nav ->prx;
    pilha.qtd--;
    delete nav;
    return aux;
}

template <typename TIPO>
void imprime (Tpilha <TIPO> pilha)
{
    int cont=0;
    TelementoP <TIPO> *nav=pilha.inicio;
    for (cont=0; cont<pilha.qtd; cont++)
    {
        cout<<nav->dado<<'\t';
        nav=nav->prx;
    }
}

#endif // PILHA_H_INCLUDED
