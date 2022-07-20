#include<stdio.h>

int binary_search(int array[], int start, int end, int object){
    int mid = start + (end -start)/2;

    if (start == end && array[mid] != object){
        return -1;
    }

    if (array[mid] == object){
        return mid;
        }else if(array[mid] > object){
            binary_search(array, start, mid-1, object);
        }else if(array[mid] < object){
            binary_search(array, mid+1, end, object);
        }
}

int main(){
    int tam_array;
    scanf("%d", &tam_array);
    int array[tam_array];
    for (int i=0; i<tam_array; i++){
        scanf("%d",&array[i]);
    }
    
    int num_a_procu;
    scanf("%d",&num_a_procu);
    for (int i=0; i<num_a_procu; i++){
        int valor_busc;
        scanf("%d",&valor_busc);
        int position = binary_search(array, 0, tam_array -1 , valor_busc);
        if (position == -1){printf("X\n");}else{
            printf("%d\n",position);
        }

    }
    return 0;
}