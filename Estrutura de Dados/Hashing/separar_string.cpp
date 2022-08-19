#include <iostream>
using namespace std;

int main(){
    string texto;
    cin >> texto;
    string novo_texto = "";
    for(int i = 0; i < texto.size(); i++){
        cout << texto[i] << endl;
        novo_texto = novo_texto + texto[i];
    }
    cout << novo_texto << endl;

    return 0;
}