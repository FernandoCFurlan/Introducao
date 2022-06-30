#ifndef DUPLAMENTE_H_INCLUDED
#define DUPLAMENTE_H_INCLUDED


template <typename TIPO>
struct Telemento_D
{
    TIPO dado;
    Telemento_D <TIPO> *prx;
    Telemento_D <TIPO> *ant;
};

template <typename TIPO>
struct Tlista_D
{
    Telemento_D <TIPO> *inicio;
    Telemento_D <TIPO> *fim;
    int qtd;
};

template <typename TIPO>
void cria_D(Tlista_D <TIPO> &lista)
{
    lista.qtd = 0;
    lista.inicio = NULL;
    lista.fim = NULL;
}

template <typename TIPO>
Telemento_D <TIPO> *novo_ele_D (TIPO dado)
{
    Telemento_D <TIPO> *novo = new Telemento_D <TIPO> ;
    novo->dado = dado;
    novo ->prx = NULL;
    novo ->ant = NULL;
    return novo;
}

template <typename TIPO>
void imprime_D (Tlista_D <TIPO> lista)
{

   Telemento_D <TIPO> *nav = lista.inicio;
   int cond=1;
    if (lista.inicio != NULL)
    {
        while(cond!=0)
        {
            cout << nav->dado<<'\t';
            if (nav -> prx  == NULL) cond=0;
            nav = nav->prx;
        }
    }

}

template <typename TIPO>
void insere_inicio_D (Tlista_D <TIPO> &lista, TIPO dado, int &cif, int &cmuda)
{
    Telemento_D <TIPO> *novo = novo_ele_D(dado);
    novo->prx = lista.inicio;
    lista.inicio = novo;
    cmuda++;
    if (novo->prx != NULL)
    {
        Telemento_D <TIPO> *aux = novo->prx;
        aux->ant = novo;
        cmuda++;
        cif++;

    }
    if (!lista.qtd)
    {
        lista.fim = novo;
        cmuda++;
        cif++;
    }
    lista.qtd++;
}

template <typename TIPO>
bool insere_fim_D (Tlista_D <TIPO> &lista, TIPO dado, int &cif, int &cmuda)
{
    if (lista.inicio== NULL)
    {
        insere_inicio_D(lista, dado, cif, cmuda);
        return true;
    }
    Telemento_D <TIPO> *aux = lista.fim;
    Telemento_D <TIPO> *novo = novo_ele_D(dado);
    aux->prx = novo;
    novo->prx = NULL;
    novo->ant = lista.fim;
    lista.fim = novo;
    lista.qtd++;
    return true;

}

template <typename TIPO>
bool insere_posi_D (Tlista_D <TIPO> &lista, TIPO dado, int posi, int &cif, int &claco, int &cmuda)
{

    if (posi == lista.qtd)
    {
        insere_fim_D(lista, dado, cif, cmuda);
        cif++;
        return true;
    }
    if (posi == 0 || lista.qtd == 0)
    {
        insere_inicio_D(lista, dado, cif, cmuda);
        cif++;
        return true;
    }
    if (posi > (lista.qtd/2))
    {
        cif++;
        Telemento_D <TIPO> *nav = lista.fim;
        int cont=lista.qtd;
        while (nav->ant != NULL)
        {
            claco++;
            if (cont== posi+1){ break; cif++;}
            nav = nav->ant;
            cont--;
        }
        Telemento_D <TIPO> *novo1 = novo_ele_D(dado);
        novo1->ant = nav->ant;
        cmuda++;
        nav->ant->prx = novo1;
        cmuda++;
        nav->ant = novo1;
        cmuda++;
        novo1->prx = nav;
        cmuda++;
        lista.qtd++;
        return true;

    }
    else
    {
        cif++;
        Telemento_D <TIPO> *nav = lista.inicio;
        int cont=0;
        while (nav->prx != NULL && cont != posi)
        {
            claco++;
            if (cont == posi-1){ break; cif++;}
            nav = nav->prx;
            cont++;
        }
        Telemento_D <TIPO> *novo2 = novo_ele_D(dado);
        novo2->prx = nav->prx;
        cmuda++;
        nav->prx->ant = novo2;
        cmuda++;
        nav->prx = novo2;
        cmuda++;
        novo2->ant = nav;
        cmuda++;
        lista.qtd++;
        return true;
    }

}

template <typename TIPO>
bool remove_inicio_D (Tlista_D <TIPO> &lista, int &cif, int &cmuda)
{
    if (lista.inicio == NULL) {cif++; return false;}
    if (lista.qtd==1)
    {
        cif++;
        lista.inicio = NULL;
        cmuda++;
        lista.fim = lista.inicio;
        cmuda++;
        lista.qtd--;
        return true;
    }
    Telemento_D <TIPO> *nav = lista.inicio;
    lista.inicio = nav->prx;
    cmuda++;
    if (lista.inicio != NULL)
    {
        lista.inicio->ant = NULL;
        cif++;
        cmuda++;
    }
    delete nav;
    lista.qtd--;
    return true;
}

template<typename TIPO>
bool remove_fim_D( Tlista_D <TIPO> &lista, int &cif, int &cmuda)
{
    if (lista.inicio==NULL) {cif++; return false;}
    Telemento_D <TIPO> *nav = lista.fim;

    if (nav->ant == NULL)
    {
        remove_inicio_D(lista, cif, cmuda);
        cif++;
        return true;
    }
    else
    {
        cif++;
        nav->ant->prx = NULL;
        cmuda++;
        lista.fim = nav->ant;
        cmuda++;
    }
    delete nav;
    lista.qtd--;
    return true;
}


template <typename TIPO>
bool remove_posi_D (Tlista_D <TIPO> &lista, int pos, int &cif, int &claco, int &cmuda)
{
    if (lista.inicio == NULL){cif++; return false;}
    if (pos >= lista.qtd) {cif++; return false;}
    if (pos==0)
    {
        cif++;
        remove_inicio_D(lista, cif, cmuda);
        return true;
    }

    if (pos==lista.qtd-1)
    {
        cif++;
        remove_fim_D(lista, cif, cmuda);
        return true;
    }
    else if (pos > ((lista.qtd-1)/2))
    {
        cif++;
        Telemento_D <TIPO> *nav = lista.fim;
        int cont=lista.qtd;
        while (nav->ant != NULL)
        {
            if (cont == (pos+1)) {cif++; break;}
            nav = nav->ant;
            cont--;
            claco++;
        }
        nav->ant->prx = nav->prx;
        cmuda++;
        nav->prx->ant = nav->ant;
        cmuda++;
        delete nav;
        lista.qtd--;
        return true;

    }
    else
    {
        cif++;
        Telemento_D <TIPO> *nav = lista.inicio;
        int cont=0;
        while (nav->prx != NULL)
        {
            if (cont == (pos)) {cif++; break;}
            nav = nav->prx;
            cont++;
            claco++;
        }
        nav->ant->prx = nav->prx;
        cmuda++;
        nav->prx->ant = nav->ant;
        cmuda++;
        delete nav;
        lista.qtd--;
        return true;
    }

}

template <typename TIPO>
bool operator < (Telemento_D <TIPO> a, Telemento_D <TIPO> b) {return a.dado<b.dado;}

template <typename TIPO>
void ordena_B_D (Tlista_D <TIPO> &lista, int &cif, int &claco, int &cmuda)
{
    int i, j, cond;
    TIPO troca;
    cond =1;

    for (i=lista.qtd-1; (i>=1) && (cond == 1); i--)
    {
        Telemento_D <TIPO> *nav = lista.inicio;
        cond = 0;
        for (j=0; j<i; j++)
        {

            if(nav->prx->dado < nav->dado)
            {
                cif++;
                troca=nav->dado;
                nav->dado = nav->prx->dado;
                cmuda++;
                nav->prx->dado= troca;
                cmuda++;
                cond = 1;
            }
            nav= nav->prx;
        }
    }

}
/*
template <typename TIPO>
int partition (Tlista_D<TIPO> &lista, int low, int high, int &cif, int &claco, int &cmuda){

    Telemento_D <TIPO> *navI = lista.inicio;
    Telemento_D <TIPO> *navJ = lista.inicio;
    Telemento_D <TIPO> *navLOW = lista.inicio;
    int i = low;

    int cont = 0;

    while(navI -> prx != NULL or navI != NULL)
    {

        if(cont == i)
        {
            cif++;
            break;
        }
        navI = navI->prx;
        claco++;
        cont++;
    }

    cont = 0;

    while(navJ -> prx != NULL or navJ != NULL)
    {
        if(cont == low+1)
        {
            cif++;
            break;
        }
        navJ = navJ->prx;
        claco++;
        cont++;
    }

    navLOW = navI;

    for(int j = low+1; j<=high; j++)
    {
        claco++;
        if(navJ->dado < navLOW->dado)
        {
            cif++;
            i++;
            if(navI->prx!=NULL)
            {
                cif++;
                navI=navI->prx;
            }
            TIPO t = navI->dado;
            navI->dado= navJ->dado;
            cmuda++;
            navJ->dado = t;
            cmuda++;
        }
        if(navJ->prx!=NULL)
        {
            cif++;
            navJ=navJ->prx;
        }
    }

    TIPO t = navLOW->dado;
    navLOW->dado= navI->dado;
    cmuda++;
    navI->dado = t;
    cmuda++;

    return i;
}

template <typename TIPO>
void ordena_Q_D(Tlista_D<TIPO> &lista, int low, int high, int &cif, int &claco, int &cmuda){
    if (low < high)
    {


        int pivo = partition(lista, low, high, cif, claco, cmuda);


        ordena_Q_D(lista, low, pivo - 1, cif, claco, cmuda);
        ordena_Q_D(lista, pivo + 1, high, cif, claco, cmuda);
    }
}*/
#endif // DUPLAMENTE_H_INCLUDED
