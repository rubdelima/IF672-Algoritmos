#include <iostream>
#include <string>
#include <cstring>
using namespace std;

    /*
    1 - instanciar lista
    2 - inserir início
    3 - inserir fim
    4 - inserir por posição
    5 - imprimir
    5.5 - tamanho
    6 - remover inicio
    7 - remover fim
    8 - remover posição
    */

// delete apontador
struct noLista
{
    char      dado;
    noLista *prox;
};

noLista *inicializar() { return NULL; }

void inserirInicio(noLista *&l, char info)
{
    noLista *novo = new noLista;
    novo->dado    = info;
    novo->prox    = l;
    l             = novo;
}

bool RemoveInicio(noLista *&ApontadorInicioLista)
{
    if (ApontadorInicioLista != NULL)
    {
        noLista *PonteiroPegaPosicaoExcluir = ApontadorInicioLista;
        ApontadorInicioLista = ApontadorInicioLista->prox;
        // delete (PonteiroPegaPosicaoExcluir);
        return true;
    }
    else
    {
        return false;
    }
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
        std::cout << l->dado;
        l = l->prox;
    }
}

int tamanho(noLista *l)
{
    int cont = 0;
    while (l != NULL)
    {
        cont++;
        l = l->prox;
    }
    return cont;
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
    bool append = true;
    int cursor = 1;
    char car;
    bool laco = true;
    int tamanho = 0;
    while(cin >> car){
        if (car == '['){
        append = false;
        }
        if (car == ']'){
        append = true;
        }
        if (car == '+'){
            imprimir(l1);
            std::cout << '\n';
            for (int i = 0; i < tamanho; i++) {
                RemoveInicio(l1);
            }
            cursor = 1;
            tamanho = 0;
        } else if (append && car != ']' && car != '['){
          inserirFim(l1, car);
          tamanho++;
        }else if (car != ']' && car != '['){
          inserir_posicao(l1, car, cursor);
          cursor++;
          tamanho++;
        }
        if (car == '*'){break;}
    }
    imprimir(l1);
    std::cout << '\n';
    return 0;
}