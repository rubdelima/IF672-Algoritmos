#include <iostream>
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
    cout << "\n[1] - Inserir no inicio da lista\n";
    cout << "[2] - Inserir no fim da lista\n";
    cout << "[3] - Inserir por posicao\n";
    cout << "[4] - Imprimir lista\n";
    cout << "[5] - Remover no inicio da lista\n";
    cout << "[6] - Remover no fim da lista\n";
    cout << "[7] - Remover por posicao\n";
}

struct noLista
{
    int      dado;
    noLista *prox;
};

noLista *inicializar() { return NULL; }

void inserirInicio(noLista *&l, int info)
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

void inserirFim(noLista *&l, int info)
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
        cout << l->dado << "\n";
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

bool inserir_posicao(noLista *&l, int info, int pos)
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

int main(int argc, char const *argv[])
{
    noLista *l1 = inicializar();
    int      Terminar, opcao, valor, posicao;
    do {
        ExibirMenu();
        cout << "\nDigite uma opcao : ";
        cin >> opcao;
        switch (opcao)
        {
            case 1:
                cout << "\nQual valor a ser inserido ? ";
                cin >> valor;
                inserirInicio(l1, valor);
                cout << "\nOperacao realizada com sucesso ! \n";
                break;
            case 2:
                cout << "\nQual valor a ser inserido ? ";
                cin >> valor;
                inserirFim(l1, valor);
                cout << "\nOperacao realizada com sucesso ! \n";
                break;
            case 3:
                cout << "\nQual valor a ser inserido ? ";
                cin >> valor;
                cout << "\nEm qual posicao ? ";
                cin >> posicao;
                if (inserir_posicao(l1, valor, posicao))
                {
                    cout << "\nOperacao realizada com sucesso ! \n";
                }
                else
                {
                    cout << "\nPosicao invalida ! \n";
                }
                break;
            case 4:
                cout << "\nAbaixo estao os elementos da lista \n\n";
                imprimir(l1);
                break;
            case 5:
                if (RemoveInicio(l1))
                {
                    cout << "\nOperacao realizada com sucesso ! \n";
                }
                else
                {
                    cout << "\nLista vazia, impossivel realizar "
                            "operacao ! \n";
                }
                break;
            case 6:
                if (RemoveFim(l1))
                {
                    cout << "\nOperacao realizada com sucesso ! \n";
                }
                else
                {
                    cout << "\nLista vazia, impossivel realizar "
                            "operacao ! \n";
                }
                break;
            case 7:
                cout << "\nQual a posicao que voce deseja excluir ? ";
                cin >> posicao;
                if (RemovePosicao(l1, posicao))
                {
                    cout << "\nOperacao realizada com sucesso ! \n";
                }
                else
                {
                    cout << "\nPosicao invalida ! \n";
                }
        }

        cout << "\n\
Deseja encerrar as operacoes com a lista ? Digite [0] para encerrar : ";
        cin >> Terminar;

    } while (Terminar != 0);
}