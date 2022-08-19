#include <stdio.h> 

int gcd(int a, int b){
    int r;
    int aux;
    if (b > a){
        aux = a;
        a = b;
        b = aux;
    }
    if (b == 0){return a;}
    r = a % b;
    a = b;
    b = r;
    return gcd(a, b);
}

int main(){
    int i, j, k;
    i =32;
    j = 36;
    k = gcd(i, j);
    printf("O MDC de a é = %d\n", k);
    return 0;
}