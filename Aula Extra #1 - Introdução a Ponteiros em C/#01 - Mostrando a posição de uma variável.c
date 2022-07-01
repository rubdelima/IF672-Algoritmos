#include<stdio.h>

int main(){
    int a = 4;
    printf("O valor de a é = %d\n", a);
    printf("O ponteiro de a é = %p\n", &a);
    int *P;
    P = &a;
    printf("O endereço de a é = %d\n", P);
    printf("O endereço de de P é de P = %d\n", &P);
    printf("O valor de a é = %d\n", *P);
    *P = 8;
    printf("O valor de a é = %d\n", a); 
    return 0;
}