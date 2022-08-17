//Não Funciona
#include<iostream>
#include <cstring>
using namespace std;

class HashNode{
    private:
        int key;
        string text;
    public:
        HashNode(int chave, string texto){
            key = chave;
            text = texto;
        }
        string showstring(){
            return text;
        }




};

class HashTable{
    private:
        int *lista_elementos;
        HashNode *lista_hashnodes;
        int tamanho_max;
        int tamanho_atual;

    public:
        HashTable(int tamanho_max){
            tamanho_max = tamanho_max;
            tamanho_atual = 0;
            lista_elementos = new int(tamanho_max);
            lista_hashnodes = new HashNode(tamanho_max,"123456789012345");
        }
        int hashFn(int key){
            return key +1;
        }

        bool isVoid(int key){
            if (lista_elementos[key] == 1){
                return false;
            } else{
                return true;
            }
        }
        void insert(int key, string texto){
            if (isVoid(key)){
                lista_elementos[key] = 1;
                lista_hashnodes[key] = HashNode(key, texto);
                tamanho_atual = tamanho_atual + 1;
            }else{
                insert(hashFn(key), texto);
            }
        }
        void remove(int key){
            if (isVoid(key)==false){
                lista_elementos[key] = 0;
                //lista_hashnodes[key] = NULL;
                tamanho_atual = tamanho_atual -1;
        }
        }
        void printtable(){
            cout<<tamanho_atual<<endl;
            for (int i=0; i<tamanho_max; i++){
                if (lista_elementos[i]==1){
                    cout<< i<<":";
                    cout << lista_hashnodes[i].showstring() << endl;
                }
            }
        }

};


int main(){
    cout << "PORKS" << endl;
    HashTable tabela = HashTable(101);
    cout << "PORKS" << endl;
    tabela.insert(5,"PORKS");
    cout << "PORKS" << endl;
    tabela.insert(4, "Solid");
    tabela.printtable();
    cout << "PORKS" << endl;

    return 0;
}




/*
34:Dabrowski
46:Polski
63:marsz
76:ziemii
96:z
*/
/*
void convertToASCII(string letter){
    int soma = 0;
    int tam = letter.length();
    for (int i = 0; i < letter.length(); i++)
    {
        char x = letter.at(i);
        cout << int(x) << endl;
        soma = soma +int(x);
    }
    int hash = (soma*19*tam) % 101;
    cout << hash << endl;
    cout << tam<<endl;
}

int main()
{
    string plainText;
    cout << "Enter text to convert to ASCII: ";
    cin >> plainText;
    convertToASCII(plainText);
    return 0;
}
*/