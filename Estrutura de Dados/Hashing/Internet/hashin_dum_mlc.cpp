#include <iostream>

using namespace std;

const int UMPRIMO = 37;


int funcaoHash(string s, int M) {
    long h = 0;
    for (unsigned i = 0; i < s.length(); i++) {
        h = (UMPRIMO * h + s[i]) % M;  

    }
    return h;
}

class noh{
friend class tabelaHash;
private:
    string chave;
    string valor;
    noh* proximo = NULL;
public:
    noh();
};

class tabelaHash{
private:
    noh** elementos;
    int capacidade;
public:
    tabelaHash(int cap);
    ~tabelaHash();
    void insere(string chave, string valor);
    string recupera(string chave);
    void altera (string chave, string valor);
    void remove (string chave);
    void percorre ();
};

noh::noh(){
    chave = "";
    valor = "";
}

tabelaHash::tabelaHash(int cap = 100){
    elementos = new noh*[cap];
    capacidade = cap;
    for (int i = 0; i < cap; i++){
        elementos[i] = NULL;
    }
}

tabelaHash::~tabelaHash(){
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

void tabelaHash::insere(string chave, string valor){
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

string tabelaHash::recupera(string chave){
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

void tabelaHash::altera(string chave, string valor){
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

void tabelaHash::remove(string chave){
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

void tabelaHash::percorre(){
    noh* atual;
    for (int i = 0; i < capacidade; ++i){
        cout << i << ":";
        atual = elementos[i];
        while (atual != NULL){
            cout << atual->chave << " : "<< atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }
}

int main(){
    tabelaHash th(2);
    th.insere ("Chave", "Valor");
    th.insere ("thave", "Valor");
    th.insere ("eeehave", "Valor");
    th.percorre();
    th.remove ("Chave");
    th.percorre();
    return 0;
}