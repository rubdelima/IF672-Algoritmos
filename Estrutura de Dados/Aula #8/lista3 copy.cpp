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
void ExibirMenu()
{
    std::cout << "\n[1] - Inserir no inicio da lista\n";
    std::cout << "[2] - Inserir no fim da lista\n";
    std::cout << "[3] - Inserir por posicao\n";
    std::cout << "[4] - Imprimir lista\n";
    std::cout << "[5] - Remover no inicio da lista\n";
    std::cout << "[6] - Remover no fim da lista\n";
    std::cout << "[7] - Remover por posicao\n";
}

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

bool RemoveFim(noLista *&ApontadorInicioLista)
{
    noLista *PonteiroPercorre = ApontadorInicioLista;
    noLista *PonteiroGuardaPosicaoAnterior;
    if (ApontadorInicioLista == NULL) { return false; }
    else if (ApontadorInicioLista->prox == NULL)
    {
        ApontadorInicioLista = NULL;
        return true;
    }
    else
    {
        while (PonteiroPercorre->prox != NULL)
        {
            PonteiroGuardaPosicaoAnterior = PonteiroPercorre;
            PonteiroPercorre              = PonteiroPercorre->prox;
        }
        PonteiroGuardaPosicaoAnterior->prox = NULL;
        return true;
    }
}

void imprimir(noLista *l)
{
    while (l != NULL)
    {
        std::cout << l->dado;
        l = l->prox;
    }
    std::cout << '\n';
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

void clearList(noLista *l){
    noLista *aux;
    while(l->prox != NULL){
        aux = l->prox;
        l = l->prox;
        delete aux;
    }
}

bool inserir_posicao(noLista *&l, char info, int pos)
{
    int tam = tamanho(l);
    if (pos > tam + 1) { return false; }
    else if (pos <= 0)
    {
        return false;
    }
    else
    {
        if (pos == 1) { inserirInicio(l, info); }
        else if (pos == tam + 1)
        {
            inserirFim(l, info);
        }
        else
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
        return true;
    }
}

bool RemovePosicao(noLista *&ApontadorInicioLista, int Posicao)
{
    int Tamanho = tamanho(ApontadorInicioLista);
    if (Posicao > Tamanho) { return false; }
    else if (Posicao <= 0)
    {
        return false;
    }
    else
    {
        if (Posicao == 1) { RemoveInicio(ApontadorInicioLista); }
        else
        {
            int      Contador = 1;
            noLista *PonteiroPegaPosicaoAnterior;
            noLista *PonteiroPegaPosicaoDelete = ApontadorInicioLista;
            noLista *PonteiroPegaPosicaoPosteriro;
            while (Contador != Posicao)
            {
                PonteiroPegaPosicaoAnterior = PonteiroPegaPosicaoDelete;
                PonteiroPegaPosicaoDelete =
                    PonteiroPegaPosicaoDelete->prox;
                PonteiroPegaPosicaoPosteriro =
                    PonteiroPegaPosicaoDelete->prox;
                Contador++;
            }
            PonteiroPegaPosicaoAnterior->prox =
                PonteiroPegaPosicaoPosteriro;
            // delete PonteiroPegaPosicaoDelete;
        }
        return true;
    }
}

int main()
{
    noLista *l1 = inicializar();
    string str;
    while(getline (cin,str)){
    string::iterator it;
    bool append = true;
    int cursor = 1;
    int tamanho = 0;
    for(it = str.begin(); it < str.end(); it++){
      char a = *it;
      if (a == '['){
        append = false;
      }
      if (a == ']'){
      append = true;
      }
      if (a == '\n'){
            imprimir(l1);
            std::cout << '\n';
            std::cout <<  'Nova Lista';
            for (int i = 0; i < tamanho; i++){
                RemoveFim(l1);
            }
            //noLista *l1 = inicializar();
            cursor = 1;
      }else if (append && a != ']' && a != '['){
        inserirFim(l1, a);
        tamanho = tamanho + 1;
      }else if (a != ']' && a != '['){
        inserir_posicao(l1, a, cursor);
        cursor++;
        tamanho+1;
      }
    }
    imprimir(l1);
    }
    imprimir(l1);
    std::cout << '\n';
    return 0;
}