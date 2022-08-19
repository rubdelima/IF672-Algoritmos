#include <bits/stdc++.h>

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
            Node* item = head;
            while(item != NULL){
                cout << item->element;
                item = item->next;
            } 
            cout << "\n";
        }

};

int main(){
    string myText;
    while(cin >> myText){
        char letter;
        LList mainText;      
        for(int i=0; i<=myText.length(); i++){
            letter = myText[i];
            if(letter == '['){
                mainText.moveToStart();
            } else if (letter == ']'){
                mainText.moveToEnd();
            } else {
                mainText.insert(letter);
                mainText.next();
            }
        
        }
        mainText.printList();
    } 
    return 0;
    }

