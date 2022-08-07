#include <iostream>
#include <string>
using namespace std;

struct noLista
{
    char     dado;
    noLista *prox;
    int      tam;
};

noLista *inicializar() { return NULL; }

void inserirInicio(noLista *&l, char info)
{
    noLista *novo = new noLista;
    novo->dado    = info;
    novo->prox    = l;
    l             = novo;
}


void inserirFim(noLista *&l, char info)
{
    noLista *novo = new noLista;
    novo->dado    = info;
    novo->prox    = NULL;
    if (l == NULL) { l = novo; }
    else
    {
        noLista *p = l;
        while (p->prox != NULL) { p = p->prox; }
        p->prox = novo;
    }
}

void imprimir(noLista *l)
{
    while (l != NULL)
    {
        cout << l->dado;
        l = l->prox;
    }
}


void inserir_posicao(noLista *&l, char info, int pos)
{
    int      cont = 1;
    noLista *novo = new noLista;
    novo->dado    = info;
    // novo->prox
    noLista *p = l;
    while (cont < pos - 1)
    {
        p = p->prox;
        cont++;
    }
    novo->prox = p->prox;
    p->prox    = novo;

}

int main()
{
    noLista *l1 = inicializar();
    string str;
    getline (cin,str);
    string::iterator it;
    bool append = true;
    int cursor = 1;
    for(it = str.begin(); it < str.end(); it++){
      char a = *it;
      if (a == '['){
        append = false;
      }
      if (a == ']'){
      append = true;
      }
      if (append && a != ']' && a != '['){
        inserirFim(l1, a);
      }else if (a != ']' && a != '['){
        inserir_posicao(l1, a, cursor);
        cursor++;
      }
    }
    imprimir(l1);
    return 0;
}
