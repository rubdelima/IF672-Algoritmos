#include<iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;  

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
/*
        ~Dictionary(){
            delete H;
            delete I;
            int *s = &size;
            int *c = &cnt;
            s = NULL;
            c = NULL;
        }
*/
        bool isVoid(int chave){
            if (I[chave%size] == 0){
                return true;
            } else{
                return false;
            }
        }


        void insert(string tex){
            int chave = hashconv(tex);
            int *hashmap = new int[19];
            hashmap[0] = chave;
            for (int i = 1; i <19; i++){
                hashmap[i] = chave + i*i + 23 + i;
            }
            for (int i = 0; i < 19; i++){
                if (isVoid(hashmap[i]%size) && H[chave%size] != tex){
                    I[chave%size] = 1;
                    H[chave%size] = tex;
                    cnt++;
                    break;
                }
            }
        }

        void remove(string tex){
            int chave = hashconv(tex);
            int *hashmap = new int[19];
            hashmap[0] = chave;
            for (int i = 1; i <19; i++){
                hashmap[i] = chave + i*i + 23 + i;
            }
            for (int i = 1; i < 19; i++){
                if ((isVoid(hashmap[i] == false) && H[chave%size] == tex)){
                    I[chave%size] = 0;
                     string *p = &H[chave%size];
                     delete p;
                    cnt--;
                    break;
                }
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
        int hashconv(string letter){
            int soma = 0;
            int tamanho = letter.length() +1;
            for (int i = 1; i < tamanho; i++){
                char x = letter.at(i-1);
                soma = soma +int(x) * i;
            }
            int hash = (soma*19) % 101;
            return hash;
            }

        
};

int main(){

    int cases;
    cin >> cases;
    for (int i=0; i < cases; i++){
        int operations;
        cin >> operations;
        Dictionary dic = Dictionary(101);
        for (int j=0; j < operations; j++){
            string input;
            cin >> input;
            string command = "";
            string object = "";
            for (int k=0; k < input.length(); k++){
                if (k < 4){
                    command = command + input[k];
                } else{
                    object = object + input[k];
                }
            }
            if (command == "ADD:"){
                dic.insert(object);
            } else if (command == "DEL:"){
                dic.remove(object);
            }
                
            }
            dic.showtable();
            /*
            Dictionary *d = &dic;
            d = NULL;
            */
        }
    return 0;
}
