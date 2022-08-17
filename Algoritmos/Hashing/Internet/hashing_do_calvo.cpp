#include<iostream>
using namespace std;  
/*
Operações:
clear, insert, remove, getKeys, find, size

## Hash function:

# para inteiros:
h(K) = K mod M

# para string:
int hashfn(string k, int M){
    soma = 0;
    for (int i = 0; i < k.length(); i++){
        soma = soma + k[i]
    }
    return abs(soma)%M;
}


### Colisões

## Open hashing
-> linked list <-
# Pseudo codigo

template <typename E>
class Dictionary{
    private:
        int tam; //tamanho da hashtable
        int cnt; // numero de elementos no dicionario
        int[] H; // array de listas
        int *h = hashfn(elemento, M); //
    public:
        Dictionary(int size, int chave){
            tam = size;
            cnt = 0;
            H = new List[size];
            for (int i = 0; i < size; i++){
                H[i] = Lista();
            }
            h* = chave;
        }

        void insert(Key& key, E element){
            if (find(k)== NULL){
                pos = key;

            }
        }
};

*/

class Dictionary{
    private:
        int size;
        int cnt;
        string *H;
        int *I;
    public:

        Dictionary(int tam){
            size = tam;
            H = new string[tam];
            I = new int[tam];
            for(int i = 0; i < tam; i++){
                I[i] = 0;
            }
            cnt = 0;
        }
        ~Dictionary(){
            delete H;
            delete I;
            size = NULL;
            cnt = NULL;

        }

        int hashfn(int elemento){
            return elemento +1;
        }


        bool isVoid(int chave){
            if (I[chave%size] == 0){
                return true;
            } else{
                return false;
            }
        }

        void insert(int chave, string tex){
            if (isVoid(chave)){
                I[chave%size] = 1;
                H[chave%size] = tex;
                cnt++;
            } else{
                insert(hashfn(chave), tex);
            }
        }

        void remove(int chave){
            if (isVoid(chave) == false){
                I[chave%size] = 0;
                string *p = &H[chave%size];
                delete p;
                cnt--;
            }
        }

        void showtable(){
            cout<< cnt << endl;
            for (int i=0; i<size; i++){
                if (I[i] == 1){
                    cout << i << ":" << H[i] << endl;
                }
            }
        }
        
};

int main(){
    Dictionary dic = Dictionary(101);
    dic.insert(1, "namespaces");
    dic.insert(2, "namespaces");
    dic.insert(2, "namespaces");
    dic.remove(2);
    dic.showtable();

    return 0;
}