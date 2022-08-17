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
        Lista<T> *element;
        HashNode<T> *next_hash;
        int key;

        int key;
        HashNode(int chave, const T& elemento, HashNode* nextno = NULL) {
            element = elemento;
            next_hash = nextno;
            key = chave;
        }

        HashNode(int chave, No* nextno = NULL){
            next_hash = nextno;
            key = chave;
        }
    private:

        addhash(const T& item){
            element.insert(item);
        }
        removehash(const T& item){
            element.removeitem(item);
        }
};

template<typename T>

class HashTable{
    private:
        HashNode<T> *prim;
        HashNode<T> *ulti; 
        HashNode<T> *atual;

    public:
        Lista(){ 
            atual = ulti = prim = new HashNode<T>;
        }

        void insert(const T& element){
            atual->next_hash = new HashNode<T>(element, atual->next_hash);
            if (ulti == atual){
                ulti = atual->next_hash;
            }
}
};