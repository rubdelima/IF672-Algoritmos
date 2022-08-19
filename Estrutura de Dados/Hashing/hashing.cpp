#include<iostream>
#include<cstdio>
#include <string>

using namespace std;

template<typename T>

class No {
    public:
        T element;
        No<T> *next;

        No(const T& elemento, No* nextno = NULL) {
            element = elemento;
            next = nextno;
        }

        No(No* nextno = NULL){
            next = nextno;
        }
};

template<typename T>

class Lista {
    private:
        No<T> *head; // Cabeça ou inicio do ponteiro
        No<T> *tail; // Cauda/ fim do ponteiro
        No<T> *curr;// Cursor, onde o ponteiro está atualmente
        int listam;
public:
        Lista(){ 
            curr = tail = head = new No<T>;
            listam = 0;
        }

        void insert(const T& element){
            curr->next = new No<T>(element, curr->next);
            if (tail == curr){
                tail = curr->next;
            }
            listam++;
        }
        void insert_ini(){
            curr = head;
            }
        void insert_end(){
            curr = tail;
        }
        void next(){ if (curr != tail) curr = curr->next; }

        void printlist(){
            curr = head;
            while (curr != NULL){
                if (curr != head){
                    cout << curr->element;
                }
                curr = curr->next;
                }
            cout << '\n';
        }
        void eraselist(){ 
            while(head != NULL){
                curr = head;
                head = head->next;
                delete curr;
            }
            curr = head = tail = new No<T>;
            listam = 0;
        }
        void removeitem(const T& element_exc){
            curr = head;
            No<T>* aux; 
            while (curr != NULL){
                if (curr->next->element == element_exc){
                    aux = curr->next;
                    curr->next = curr->next->next;
                    delete aux;
                    listam--;
                }
                curr = curr->next;
            }
        }
        bool inlist(const T& item){
            curr = head;
            while (curr != NULL){
                if (curr->element == item){
                    return true;
                }
            }
            return false;
        }

};


template<typename T>

class HashNode{
    public:
        Lista<T> element;
        HashNode * next;
        int key;

        HashNode(const Lista<T>& elemento, int chave, HashNode* nexthash = NULL){
                element = elemento;
                next = nexthash;
                key = chave;

        }

        HashNode(int chave, HashNode* nexthash = NULL){
            next = nexthash;
            key = chave;
        }
    private:
        void inserthash(int elemento){
            element.insert_end();
            element.insert(elemento);
        }
        void removehash(int elemento){
            element.removeitem(elemento);
        }
        void errasehash(){
            element.eraselist();
        }
        void printhash(){
            cout << key << ":";
            element.printlist();
        }
};

template<typename T>

class HashTable{
    public:
        Lista<T> lista_keys;
        HashNode<T> * head;
        HashNode<T> * tail;
        HashNode<T> * curr;
        int tamanho;
    private:
        void inserthash(int chave, T element){
            if (lista_keys.inlist(chave)){
                printf("Está na lista");
            } else{
                lista_keys.insert(new HashNode<T>(element, chave));
            }
        }





};
        

        


int main(){

    Lista<int> lista;
    lista.insert(1);
    lista.printlist();
    Lista<char> lista_char;
    lista_char.insert('r');
    lista_char.printlist();
    Lista<string> lista_str;
    lista_str.insert("Ola meu nome é Carlos\n\nSalve");
    lista_str.printlist();


    

    return 0;
}