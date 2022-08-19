#include <stdio.h>  

int main(){
    int a;
    int *p;
    p = &a; // &a = address of a
    printf("address of a == %d\n", p); // address of a and value of p
    printf("value of address a == %d\n", *p); //
    a = 10;
    printf("address of a == %d\n", p); // address of a and value of p
    printf("value of address a == %d\n", *p); //
    return 0;
}