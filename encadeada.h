#ifndef ENCADEADA_H_INCLUDED
#define ENCADEADA_H_INCLUDED

template <typename TIPO>
struct Telemento
{
    TIPO dado;
    Telemento <TIPO> *prx;
};

template <typename TIPO>
struct Tlista
{
    Telemento <TIPO> *inicio;
};

template <typename TIPO>
void cria(Tlista <TIPO> &lista)
{
    lista.inicio = NULL;
}

template <typename TIPO>
Telemento <TIPO> *novo_ele (TIPO dado)
{
    Telemento <TIPO> *novo = new Telemento <TIPO> ;
    novo->dado = dado;
    novo ->prx = NULL;
    return novo;
}

template <typename TIPO>
int qtd(Tlista <TIPO> lista)
{
    Telemento <TIPO> *nav=lista.inicio;
    int cont=0;
    if (nav->prx == NULL) return 1;
    while (nav->prx != NULL)
    {
        nav=nav->prx;
        cont++;
    }
    return cont;
}

template <typename TIPO>
bool insere_fim (Tlista <TIPO> &lista, TIPO dado)
{
    Telemento <TIPO> *nav = lista.inicio;
    if (lista.inicio != NULL)
    {
        while(nav -> prx != NULL)
            nav = nav -> prx;
        Telemento <TIPO> *novo = novo_ele(dado);
        novo -> prx = nav -> prx;
        nav -> prx = novo;
        return true;

    }
    Telemento <TIPO> *novo = novo_ele(dado);
    novo->prx = lista.inicio;
    lista.inicio = novo;
    return true;

}

template <typename TIPO>
void insere_inicio (Tlista <TIPO> &lista, TIPO dado)
{
    Telemento <TIPO> *novo = novo_ele(dado);
    novo->prx = lista.inicio;
    lista.inicio = novo;
}

template <typename TIPO>
bool insere_posi (Tlista <TIPO> &lista, TIPO dado, int posi)
{
    Telemento <TIPO> *nav = lista.inicio;
    int cont=0;
    if (posi == qtd(lista))
    {
        insere_fim(lista, dado);
        return true;
    }
    if (lista.inicio != NULL && posi != 0)
    {
        while(nav -> prx != NULL)
        {
            if (cont== (posi-1)) break;
            nav = nav->prx;
            cont++;
        }
        Telemento <TIPO> *novo = novo_ele(dado);
        novo -> prx = nav -> prx;
        nav -> prx = novo;
        return true;
    }
    insere_inicio(lista, dado);
    return true;

}

template <typename TIPO>
bool remove_inicio (Tlista <TIPO> &lista)
{
    if (lista.inicio == NULL) return false;
    Telemento <TIPO> *nav = lista.inicio;
    lista.inicio = nav ->prx;
    delete nav;
    return true;
}

template<typename TIPO>
bool remove_fim( Tlista <TIPO> &lista)
{
    if (lista.inicio==NULL) return false;
    Telemento <TIPO> *nav = lista.inicio;
    if (qtd(lista)==1)
    {
        remove_inicio(lista);
        return true;
    }
    else
    {
        Telemento <TIPO> *aux = lista.inicio->prx;
        while (aux->prx != NULL)
        {
            nav=nav->prx;
            aux=aux->prx;
        }
        nav->prx = NULL;
        delete aux;
        return true;
    }
}

template <typename TIPO>
bool remove_posi (Tlista <TIPO> &lista, int pos)
{
    if (lista.inicio == NULL) return false;
    if (pos==0)
    {
        remove_inicio(lista);
        return true;
    }

    if (pos==qtd(lista))
    {
        remove_fim(lista);
        return true;
    }
    Telemento <TIPO> *nav = lista.inicio;
    Telemento <TIPO> *aux = lista.inicio->prx;
    int cont=0;
    while (cont < (pos-1) && nav->prx != NULL)
    {
        aux=aux->prx;
        nav=nav->prx;
        cont++;
    }
    if (aux != NULL)
    {
        nav->prx = aux->prx;
        delete aux;
    }
    return true;

}

template <typename TIPO>
void imprime (Tlista <TIPO> lista)
{

   Telemento <TIPO> *nav = lista.inicio;
   int cond=1;
    if (lista.inicio != NULL)
    {
        while(cond!=0)
        {
            cout << nav->dado<<endl;
            if (nav -> prx  == NULL) cond=0;
            nav = nav->prx;
        }
    }

}
#endif // ENCADEADA_H_INCLUDED
