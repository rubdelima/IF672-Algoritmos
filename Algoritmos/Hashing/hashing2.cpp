#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef struct node{
    int key;
    struct node* next;
}Node;

typedef struct {
    Node * inicio;
    int tamanho;
}Lista;

void iniciarLista(Lista * l){
    l->inicio = NULL;
    l->tamanho = 0;
}

void inisertLista(Lista * l, int valor){
    
    
}