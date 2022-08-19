#include<iostream>
#include<cstdio>
using namespace std;

class Node {
    public:
        char element;
        Node *next;

        Node(const char& elementVal, Node* nextNode = NULL) {
            element = elementVal;
            next = nextNode;
        }

        Node(Node* nextNode = NULL){
            next = nextNode;
        }
};

class LList {
    private:
        Node* head;
        Node* tail;
        Node* cursor;
        int listSize;
public:
        LList(){ 
            cursor = tail = head = new Node;
            listSize = 0;
        }
        
        void clear(){ 
            while(head != NULL){
                cursor = head;
                head = head->next;
                delete cursor;
            }
            cursor = head = tail = new Node;
            listSize = 0;
        }
        void insert(const char& element){
            cursor->next = new Node(element, cursor->next);
            if (tail == cursor){
                tail = cursor->next;
            }
            listSize++;
        }

        void append(const char& element){
            tail = tail->next = new Node(element, NULL);
            listSize++;
        }

        void moveToStart(){ cursor = head; }
        void moveToEnd(){ cursor = tail; }
        void next(){ if (cursor != tail) cursor = cursor->next; }

        void printList(){
            cursor = head;
            while (cursor != NULL){
                if (cursor != head){
                    cout << cursor->element;
                }
                cursor = cursor->next;
                }
            cout << '\n';
        }

};

int main(){
    char a;
    LList lista;
    while(scanf("%ch",&a) != EOF){      
            if(a == '['){
                lista.moveToStart();
            } else if (a == ']'){
                lista.moveToEnd();
            } else if (a == '\n'){
                lista.printList();
                lista.clear();
            }else {
                lista.insert(a);
                lista.next();
            }
        
        }
        lista.printList();
    return 0;
}

