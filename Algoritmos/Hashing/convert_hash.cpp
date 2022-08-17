#include <iostream>
#include <string>
using namespace std;
/*
34:Dabrowski
46:Polski
63:marsz
76:ziemii
96:z
*/

/*
Hash(key)=h(key) mod 101, where
h(key)=19 *(ASCII(a1)*1+...+ASCII(an)*n).
*/

int hashconv(string letter){
    int soma = 0;
    for (int i = 1; i < letter.length()+1; i++){
        char x = letter.at(i-1);
        soma = soma +int(x) * i;
    }
    int hash = (soma*19) % 101;
    return hash;
}

int main(){
    while (1){
        string plainText;
        cin >> plainText;
        if(plainText != "Sair"){
            int conv = hashconv(plainText);
            cout << conv <<":"<<plainText<< endl;}else{break;}
            }

    return 0;
}