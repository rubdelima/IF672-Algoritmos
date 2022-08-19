#include<stdio.h>
#include<math.h>
/*# 2⁵⁰ mod 5 -> a = 2, b = 50, c = 5
def fermart(a,b,c):
    d = (b)%(c-1)
    return (a**d) % c

print(fermart(2,50,5))
*/
int fermart(double a, int b, int c){
    double d = (b)%(c-1);
    double p = pow(a,d) % c;

}
