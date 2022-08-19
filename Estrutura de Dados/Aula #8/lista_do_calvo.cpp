#include<iostream>
#include<cstdio>
using namespace std;

class No{
    public:
        char element; // Elemento do nó
        No *next; // Proximo valor do Nó
        // Construtores
        // Construtor que recebe valores
        No (const char& elemento, No *nextval){
                element = elemento;
                next = nextval;
        };
        // Construtores que não recebe valores
        No (No *nextval=NULL){
            next = nextval;
        };
        
};

class Lista{
    private:
        No *head; // Cabeça ou inicio do ponteiro
        No *tail; // Cauda/ fim do ponteiro
        No *curr; // Cursor, onde o ponteiro está atualmente
        int cnt; // Tamanho da lista

    public:
        // Construtores
        Lista(){
            curr = head = tail = new No();
            cnt = 0;
        }
        // Destrutores
        ~Lista(){
            while(head != NULL){
                curr = head;
                head = head->next;
                delete curr;
            }
        }
        // Funções
        //Adicionar no fim
        void append(char letra){
            //tail = tail->next = new No(letra, NULL);
            No *novo = new No(letra, NULL); // Criar um nó com o elemento
            tail->next = novo; // Fazer a antiga cauda apontar para o novo elemneto
            tail = novo; // colocar como novo elemento da cauda
            cnt = cnt +1; // aumenta o tamanho
        }
        // Adicionar na lista
        void mergelistini(Lista *listab){
            listab->tail->next = head;
            head = listab->head;
        }
        void addcursor(int posicao, char letra){
            int cont = 0;
            curr = head;
            while(curr->next != NULL){
                if(cont == posicao){
                    No *novo = new No(letra, NULL);
                    No *prox = curr->next;
                    novo->element = letra;
                    curr->next = novo;
                    novo->next = prox;
                    cnt++;
                    break;
                }else{
                    curr = curr->next;
                    cont++;
                }
            }
        }
        
        void printlist(){
            curr = head;
            while (curr->next != NULL){
                if (curr != head){
                    std::cout << curr->element;
                }
                curr = curr->next;
                }
            std::cout << '\n';
            }
        int tamanho(){
            return cnt;
        }
    
        void eraselist(){
            curr = head = tail = new No();
            cnt = 0;
        }

};

int main(){
    char a;
    Lista lista;
    int cursor = 0;
    bool append = true;
    int tamanho = 0;
    int tamanho_total = 0;
    while(scanf("%c", &a) != EOF){
        if(a == '['){
            append = false;
        } else if(a == ']'){
            append = true;
        } else{
            if (append) {
                lista.append(a);
                tamanho++;
            }else{
                lista.addcursor(cursor, a);
                cursor++;
                tamanho++;
            }
        }
        if (a == '\n'){
            cursor = 0;
            lista.printlist();
            lista.eraselist();
        }
        //if(a == '*'){break;}
    }
    lista.printlist();
    return 0;
}
