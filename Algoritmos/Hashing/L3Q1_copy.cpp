#include<iostream>
using namespace std; 

class Node{
    public:
        bool ocup = false;
        int value;
        string name;

    Node(){
        ocup = false;
    }
    void insert(int key, string texto){
        name = texto;
        value = key;
        ocup = true;
    }
    void remove(int key, string texto){
        string *aux = &name;
        aux = NULL;
        ocup = false;
        int *pont_val = &value;
        delete pont_val;

    }
};

class Dictionary{
    private:
        int size;
        int cnt;
        Node *nos;
    public:
        Dictionary(int tam){
            size = tam;
            nos = new Node[101];
            for(int i = 0; i < tam; i++){
                nos[i].ocup = false;
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

        void insert(string tex){
            int chave = hashconv(tex);
            int *hashmap = new int[19];
            hashmap[0] = chave;
            for (int i = 1; i <19; i++){
                hashmap[i] = chave + i*i + 23 + i;
            }
            for (int i = 0; i < 19; i++){
                if (nos[chave].ocup== false && nos[chave%size].name != tex){
                    nos[chave%size].insert(chave%size, tex);
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
                if (nos[chave].ocup== true && nos[chave%size].name == tex){
                    nos[chave%size].remove(chave%size, tex);
                    cnt--;
                    break;
                }
            }
        }

        void showtable(){
            cout<< cnt << endl;
            for (int i=0; i<size; i++){
                if (nos[i].ocup){
                    cout << i << ":" << nos[i].name << endl;
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
