#include <stdio.h> 

int gcd(int a, int b){
    int r;
    if (b == 0){return a;}
    r = a % b;
    a = b;
    b = r;
    return gcd(a, b);
}

int main(){
    int i, j, k;
    i =32;
    j = 28;
    k = gcd(i, j);
    printf("O MDC de a é = %d\n", k);
    return 0;
}