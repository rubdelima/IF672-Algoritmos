#include<iostream>
#include<cstdio>
using namespace std;

class No{
    public:
        char element; // Elemento do nó
        No *next; // Proximo valor do Nó
        // Construtores
        // Construtor que recebe valores
        No (const char& elemento, No *nextval=NULL){
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
        No *curr;// Cursor, onde o ponteiro está atualmente
        No *curr2;

    public:

        Lista(){
            curr2 = head = tail = new No;
        }


        // Utima tentativa...
       void insert(const char& letra){
           curr2->next = new No(letra, curr2->next);
           if (tail == curr2){
               tail = curr2->next;
                }
        }
        void insert_ini(){ 
            curr2 = head;
            }
        void insert_end(){
            curr2 = tail;
        }
        void next(){
            if (curr2 != tail) curr2 = curr2->next;
            }
        
        void printlist(){
            curr2 = head;
            while (curr2 != NULL){
                if (curr2 != head){
                    std::cout << curr2->element;
                }
                curr2 = curr2->next;
                }
            std::cout << '\n';
            }
    
        void eraselist(){
            while(head != NULL){
                curr2 = head;
                head = head->next;
                delete curr2;
            }
            curr2 = head = tail = new No;
        }

};


int main(){
    char a;
    Lista lista;
    while(scanf("%ch",&a) != EOF){      
            if(a == '['){
                lista.insert_ini();
            } else if (a == ']'){
                lista.insert_end();
            } else if (a == '\n'){
                lista.printlist();
                lista.eraselist();
            }else{
                lista.insert(a);
                lista.next();
            }
        
        }
        //lista.printlist();
    return 0;
}
