#include <iostream>

using namespace std;

const int UMPRIMO = 37;


int funcaoHash(int s, int M) {
    long int h = 0;
        h = s % M;  
    return h;
}



class noh{
friend class tabelaHash;
private:
    int chave;
    string valor;
    noh* proximo = NULL;
public:
    noh(){
        chave = 0;
        valor = "";
    }
};

class tabelaHash{
private:
    noh** elementos;
    int capacidade;
public:
    tabelaHash(int cap = 100){
        elementos = new noh*[cap];
        capacidade = cap;
        for (int i = 0; i < cap; i++){
            elementos[i] = NULL;
        }
    }
    ~tabelaHash(){
        for (int i = 0; i < capacidade; ++i){
            noh* atual = elementos[i];
            while(atual != NULL){
                noh* aux = atual;
                atual = atual->proximo;
                delete aux;

        }
    }
    delete[] elementos;
    }
    void insere(int chave, string valor){
        int hash = funcaoHash(chave,capacidade);
        if (recupera(chave) == "NÂO ENCONTRADO"){
            if (elementos[hash] == NULL){
                elementos[hash] = new noh;
                elementos[hash]->chave = chave;
                elementos[hash]->valor = valor;
            }else{
                cout << "COLIDIU: " << chave << endl;
                noh* atual = elementos[hash];
                while(atual->proximo != NULL){
                    atual = atual->proximo;
                }
                noh* novo = new noh;
                novo->chave = chave;
                novo->valor = valor;
                atual->proximo = novo;
            }
        }else{
            cout << "O ITEM JÁ ESTÁ NA TABELA" << endl;
        }
    }
    string recupera(int chave){
        int hash = funcaoHash(chave,capacidade);
        if (elementos[hash] != NULL and elementos[hash]->chave == chave){
            return elementos[hash]->valor;
        }else{
            noh* atual = elementos[hash];

            while (atual != NULL and atual->chave != chave){
                atual = atual->proximo;
            }

            if (atual != NULL and atual->chave == chave){
                return atual->valor;
            }else{
                return "NÂO ENCONTRADO";
            }
        }
    }
    void altera (int chave, string valor){
        int hash = funcaoHash(chave,capacidade);
        if (elementos[hash] != NULL and elementos[hash]->chave == chave){
            elementos[hash]->valor = valor;
        }else{
            noh* atual = elementos[hash];
            while(atual != NULL and atual->chave != chave){
                atual = atual->proximo;
            }
            if (atual != NULL and atual->chave == chave){
                atual->valor = valor;
            }else{
                cerr << "ERRO NA ALTERAÇÃO" << endl;
            }
        }

    }
    void remove (int chave){
        int hash = funcaoHash(chave,capacidade);
        if (elementos[hash] != NULL and elementos[hash]->chave == chave){
            noh* aux = elementos[hash];
            elementos[hash] = elementos[hash]->proximo;
            delete aux;
        } else {
            noh* atual = elementos[hash];
            noh* anterior;
            while (atual != NULL and atual->chave != chave){
                anterior = atual;
                atual = atual->proximo;
            }
            if (atual != NULL and atual->chave == chave){
                anterior->proximo = atual->proximo;
                delete atual;
            } else {
                cerr << "ERRO NA REMOÇÃO" << endl;
            }
        }
    }
    void percorre (){
        noh* atual;
        for (int i = 0; i < capacidade; ++i){
            atual = elementos[i];
            cout << atual->chave << ":";
            while (atual != NULL){
                cout << " " << atual->valor;
                atual = atual->proximo;
            }
            cout << endl;
        }
    }
};

int main(){
    tabelaHash th(3);
    //th.insere(chave, valor)
    th.insere (1, "Abel");
    th.insere (2, "Ferreira");
    th.insere (3, "Palmeiras");
    th.insere(1, "PORKS");
    th.percorre();
    //th.remove (1);
    //th.percorre();
    return 0;
}