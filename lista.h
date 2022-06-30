#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

template <typename TIPO>
struct TelementoF
{
    TIPO dado;
    TelementoF <TIPO> *prx;
    TelementoF <TIPO> *ant;

};

template <typename TIPO>
struct Tfila
{
    TelementoF <TIPO> *inicio;
    TelementoF <TIPO> *fim;
    int qtd;
};

template <typename TIPO>
void inicializarF(Tfila <TIPO> &fila)
{
    fila.inicio = NULL;
    fila.fim = NULL;
    fila.qtd=0;
}

template <typename TIPO>
TelementoF <TIPO> *novo_eleF (TIPO dado)
{
    TelementoF <TIPO> *novo = new TelementoF <TIPO> ;
    novo->dado = dado;
    novo->prx = NULL;
    novo->ant = NULL;
    return novo;
}

template <typename TIPO>
bool insere_fimF (Tfila <TIPO> &fila, TIPO dado)
{
    if (fila.inicio== NULL)
    {
        TelementoF <TIPO> *novo1 = novo_eleF(dado);
        fila.fim = novo1;
        fila.inicio = novo1;
        fila.qtd++;
        return true;
    }
    TelementoF <TIPO> *aux = fila.fim;
    TelementoF <TIPO> *novo = novo_eleF(dado);
    aux->prx = novo;
    novo->prx = NULL;
    novo->ant = fila.fim;
    fila.fim = novo;
    fila.qtd++;
    return true;

}

template <typename TIPO>
TIPO remove_inicioF (Tfila <TIPO> &fila)
{
    TIPO aux = anula_dado(aux);
    if (fila.inicio == NULL) return aux;
    aux = fila.inicio->dado;
    TelementoF <TIPO> *nav = fila.inicio;
    fila.inicio = nav ->prx;
    if (nav->prx != NULL)  nav->prx->ant = NULL;
    fila.qtd--;
    delete nav;
    return aux;
}

template <typename TIPO>
TIPO mostra_inicioF (Tfila <TIPO> &fila)
{
    TIPO aux = anula_dado(aux);
    if (fila.inicio == NULL) return aux;
    return fila.inicio->dado;
}



#endif // LISTA_H_INCLUDED
