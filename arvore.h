#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
template <typename TIPO>
struct Tno
{
    int chave;
    TIPO dado;
    Tno <TIPO> *dir;
    Tno <TIPO> *esq;
};

template <typename TIPO>
struct Tarvore
{
    Tno <TIPO> *raiz;
};

template <typename TIPO>
void inicializa (Tarvore <TIPO> &arvore)
{
    arvore.raiz = NULL;
}

template <typename TIPO>
Tno <TIPO> *novo_no (TIPO dado, int chave)
{
    Tno <TIPO> *novo = new Tno <TIPO> ;
    novo->dado = dado;
    novo->chave = chave;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

template <typename TIPO>
bool insere (Tno <TIPO> * &no, TIPO dado, int chave)
{

    if (no == NULL)
    {
        Tno <TIPO> *novo = novo_no(dado, chave);
        no = novo;
        return true;
    }
    if (chave < no->chave)
        insere(no->esq, dado, chave);



    else if (chave > no->chave)
        insere(no->dir, dado, chave);


}

template <typename TIPO>
bool imprime (Tno <TIPO> *no)
{
    if (no == NULL) return true;
    cout<<no->dado<<'\t';
    imprime(no->esq);
    imprime(no->dir);
}

template <typename TIPO>
TIPO pesquisa (Tno <TIPO> *no, int chave)
{
    if (chave == no->chave)
    {
        return no->dado;
    }

    if (chave < no->chave)
        pesquisa(no->esq, chave);

    else if (chave > no->chave)
        pesquisa(no->dir, chave);

}

template <typename TIPO>
bool qtd (Tno <TIPO> *no, int &cont)
{
    if (no == NULL){
        return true;
    }
    cont++;
    qtd(no->esq, cont);
    qtd(no->dir, cont);
}

template <typename TIPO>
void remover (Tno <TIPO> *&no)
{
    Tno <TIPO> *apagar;
    Tno <TIPO> *maior = no->esq;
    if (maior == NULL)
    {
        apagar = no;
        no = no->dir;
        delete apagar;
        return;
    }
    Tno <TIPO> *pai = NULL;
    while (maior->dir != NULL)
    {
        pai = maior;
        maior = maior->dir;
    }
    maior->dir = no->dir;
    if (pai != NULL)
    {
        pai->dir = maior->esq;
        maior->esq = no->esq;
    }
    apagar = no;
    no = maior;
    delete apagar;
}

template <typename TIPO>
void busca_remove (Tno <TIPO> *&no, int chave)
{
    if (no != NULL)
    {
        if (no->chave == chave)
        {
            remover(no);
        }
        else
        {
            if (chave > no->chave)
            {
                busca_remove(no->dir, chave);
            }
            else
            {
                busca_remove(no->esq, chave);
            }
        }
    }
}


template <typename TIPO>
int altura (Tno <TIPO> *no)
{
    if (no == NULL) return -1;
    else
    {
        int he = altura(no->esq);
        int hd = altura(no->dir);
        if (he < hd)
        {
            return hd+1;
        }else return he+1;
    }
}

#endif // ARVORE_H_INCLUDED
