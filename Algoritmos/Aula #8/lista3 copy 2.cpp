#include <iostream>

using namespace std;

// Nó - Representa um elemento da lista

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;
typedef Node *Ptrnode;

/* Operações sobre um nó */
Node *newNode(int n) {
    Node *q;
    q = new Node();
    q->data = n;
    q->next = NULL;
    return q;
}

void freeNode(Node *p) {
    delete(p);
    return;
}

Node *printNode(Node *p) {
    cout << p->data;
}

// Estrutura da Lista

typedef struct {
    string name;
    Node *front;
    Node *rear;
} List;

/* Operações sobre uma Lista */
List *newList(string s) {
    List *p;
    p = new List();
    p->name = s;
    p->front = NULL;
    p->rear = NULL;
    return p;
}

Node *nextNode(Node *p) {
    return p->next;
}

List *clearList(List *p) {
    Node *q, *w;
    q = p->front;
    while (q != NULL) {
        w = nextNode(q);
        freeNode(q);
        q = w;
    }
    p->front = NULL;
    p->rear = NULL;
    return p;
}

void freeList(List *p) {
    // Memória usada por cada nó
    clearList(p);
    // Memória usada pela estrutura
    delete(p);
    return;
}

int emptyList(List *p) {
    if (p->front == NULL)
        return true;
    else
        return false;
}

List *printList(List *p) {
    Node *q;
    cout << endl << p->name;
    if (emptyList(p)) {
        cout << "A lista está vazia!";
        return p;
    }
    q = p->front;
    while (q != NULL) {
        cout << endl;
        printNode(q);
        q = nextNode(q);
    }
    return p;
}

List *insertAtFront(List *p, char n) {
    Node *q;
    q = newNode(n);
    q->next = p->front;
    p->front = q;
    if (p->rear == NULL)
        p->rear = q;
    return p;
}

List *insertAfter(List *p, Node *w, char n) {
    Node *q;
    if (w == NULL || p->front == NULL)
        return insertAtFront(p, n);
    q = newNode(n);
    q->next = w->next;
    w->next = q;
    if (w == p->rear)
        p->rear = q;
    return p;
}

List *insertAtRear(List *p, char n) {
    Node *q;
    q = p->rear;
    return insertAfter(p, q, n);
}

int removeFromFront(List *p) {
    int n;
    Node *q;
    if (emptyList(p)) {
        cout << endl << "Underflow na lista";
        exit(EXIT_FAILURE);
    }
    n = p->front->data;
    q = p->front;
    p->front = p->front->next;
    freeNode(q);
    if (p->front == NULL)
        p->rear = NULL;
    return n;
}

Node *findInList(List *p, int n) {
    Node *q;
    q = p->front;
    while (q != NULL) {
        if (q->data == n)
            break;
        q = nextNode(q);
    }
    // retorna NULL se não for encontrado.
    return q;
}
int main()
{
    List *l1;
    bool append = true;
    int cursor = 1;
    char a;
    while(cin >> a) {
      if (a == '['){
        append = false;
      }
      if (a == ']'){
      append = true;
      }
      if (a == '\n'){
            printList(l1);
            std::cout << '\n';
            freeList(l1);
            List *l1;
            cursor = 1;
      }else if (append && a != ']' && a != '['){
        inserirFim(l1, a);
      }else if (a != ']' && a != '['){
        inserir_posicao(l1, a, cursor);
        cursor++;
      }
    }
    imprimir(l1);
    }
    imprimir(l1);
    std::cout << '\n';
    return 0;
}