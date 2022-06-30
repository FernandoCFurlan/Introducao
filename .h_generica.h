#ifndef _H_GENERICA_H_INCLUDED
#define _H_GENERICA_H_INCLUDED

template <typename TIPO>
struct Telemento
{
    TIPO dado;
};


template <typename TIPO, int Max>
struct Tlista
{
    Telemento <TIPO> elementos [Max];
    int quantidade;
};

template <typename TIPO, int Max>
bool inicializa (Tlista <TIPO, Max> &lista)
{
    lista.quantidade=0;
    return true;
}

template <typename TIPO, int Max>
void imprime (Tlista <TIPO, Max> lista)
{
    for (int i=0; i<lista.quantidade; i++)
    {
       imprime_carta(lista.elementos[i].dado);
    }
}

template <typename TIPO, int Max>
bool insere_fim (Tlista <TIPO, Max> &lista, TIPO dado)
{
    if (lista.quantidade >= Max)
    {
        return false;
    }else{
            Telemento <TIPO> ele;
            ele.dado=dado;
            lista.elementos[lista.quantidade] = ele;
            lista.quantidade++;
            return true;
          }
}
template <typename TIPO, int Max>
bool insere_inicio (Tlista <TIPO, Max> &lista, TIPO dado)
{
    if (lista.quantidade < Max)
    {

        Telemento <TIPO> ele;
        ele.dado = dado;
        for (int i=lista.quantidade; i>0; i--)
        {
            lista.elementos[i]=lista.elementos[i-1];
        }
        lista.elementos[0] = ele;
        lista.quantidade++;
        return true;
    }else{
            return false;
         }
}

template <typename TIPO, int Max>
bool insere_posi (Tlista <TIPO, Max> &lista, TIPO dado, int pos)
{
    if (lista.quantidade < Max)
    {
        for (int i=lista.quantidade; i>pos; i--)
        {
            lista.elementos[i]=lista.elementos[i-1];
        }
        Telemento <TIPO> ele;
        ele.dado=dado;
        lista.elementos[pos]=ele;
        lista.quantidade++;
        return true;
    }else{
            return false;
         }
}

template <typename TIPO, int Max>
bool remove_fim (Tlista <TIPO, Max> &lista)
{
    if (lista.quantidade > 0)
    {
        lista.quantidade--;
        return true;
    }
    else{
            return false;
        }
}

template <typename TIPO, int Max>
bool remove_inicio (Tlista <TIPO, Max> &lista)
{
    if (lista.quantidade > 0)
    {
        for (int i=0; i<lista.quantidade-1; i++ )
        {
            lista.elementos[i]=lista.elementos[i+1];
        }
            lista.quantidade--;
            return true;
    }else{
            return false;
         }
}

template <typename TIPO, int Max>
bool remove_posi (Tlista <TIPO, Max> &lista, int pos)
{
      if (lista.quantidade > 0)
    {
        for (int i=pos; i<lista.quantidade-1; i++ )
        {
            lista.elementos[i]=lista.elementos[i+1];
        }
        lista.quantidade--;
        return true;
    }else{
            return false;
         }
}

template <typename TIPO, int Max>
int qtd (Tlista <TIPO, Max> lista)
{
    return lista.quantidade;
}
#endif // _H_GENERICA_H_INCLUDED
