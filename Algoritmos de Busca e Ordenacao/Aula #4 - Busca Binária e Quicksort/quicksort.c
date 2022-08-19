#include<stdio.h>

void print_array(int array[],int tam_array){
    for (int i=0;i<tam_array;i++){
        printf("%d ",array[i]);
    }
}

void quicksort(int array[],int tam){
    int i, j, group, swap;

    // Parada recursividade
    if (tam < 2){return;}else{
        group = array[tam/2];
    }

    // Loop
    for (i =0, j = tam-1;;i++, j--){

        //Movimentações dos grupos do vetor
        while(array[i] < group){i++;}
        while(group < array[j]){j--;}

        // Parar o loop
        if (i >= j){break;}else{
            swap = array[i];
            array[i] = array[j];
            array[j] = swap;
        }
    }
    // Recurssões
    quicksort(array, i);
    quicksort(array + i, tam-1);
}

int main(){
    int tam_array = 10;
    int array[10] = {5,12,1,3,6,4,7,8,2,10};
    quicksort(array, tam_array);
    print_array(array, tam_array);
    return 0;
}