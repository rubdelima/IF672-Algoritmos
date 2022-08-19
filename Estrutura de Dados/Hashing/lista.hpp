#ifndef _lista_hpp_
#define _lista_hpp_

#include<iostream>
#include<cstdio>

using namespace std;

template<class T>

class No {
    public:
        T element;
        No *next;

        No(const T& elemento, No* nextno = NULL) {
            element = elemento;
            next = nextno;
        }

        No(No* nextno = NULL){
            next = nextno;
        }
};

template<class T>

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
            curr->next = new No(element, curr->next);
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

};
#endif // !_lista_hpp_