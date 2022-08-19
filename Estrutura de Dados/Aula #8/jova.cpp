#include <iostream>
#include<string>
using namespace std;

class Node {
    public:
        char Letra;
        Node *Next; };

class List {
    private:
        Node* Head;
        Node* tail;
        Node* curr;
        
    public:
        void create_list(){
            Node *NewNode = new Node;
            NewNode->Next = NULL;
            curr = tail = Head = NewNode;    
        }
        void insert(char letter){
            Node *NewNode = new Node;
            NewNode->Letra = letter;
            NewNode->Next = curr->Next;
            curr->Next = NewNode;
            if (tail == curr){
                tail = curr->Next;
            }
        }
        void MoveToStart(){
            curr = Head;
        }
        void next(){
            
            curr = curr->Next;
            
        }
        void MovetoEnd (){
            curr = tail;
        }
        void print(){
            while (Head != NULL)
            {   
                cout << Head->Letra;
                Head = Head->Next;
            }
            cout<<endl;
            
   
        }
    };

char letra;
string entrada;
List frase;

int main()
{   
    while(cin >> entrada){
    int tamanho = entrada.length();

    frase.create_list();   
    for ( int i = 0; i < tamanho; i++){
    
        letra = entrada[i];
        
        if (letra == '[')
        {  
            frase.MoveToStart();
        }
        else if (letra == ']'){
            
            frase.MovetoEnd();
        }
        else {
            frase.insert(letra);
            frase.next();
            
        }
    }
    frase.print();
    }
return 0;
}