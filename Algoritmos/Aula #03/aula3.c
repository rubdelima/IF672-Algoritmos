#include <stdio.h>

int merge(int lis1[], int tam_lista1, int list2[], int tam_lista2){
    int contador1 = 0;
    int contador2= 0;
    int tam_array = tam_lista1 + tam_lista2;
    int lista_aux[tam_array];
    int cont_array = 0;
    while (1){

        if (contador1 == tam_lista1){
            while (1){
                lista_aux[cont_array] = list2[contador2];
                contador2 = contador2 + 1;
                cont_array = cont_array + 1;
                if (contador2 == tam_lista2){
                    return lista_aux;
                    }
                }
            }
                
        if (contador2 == tam_lista2){
            while (1){
                lista_aux[cont_array] = lis1[contador1];
                contador1 = contador1 + 1;
                cont_array = cont_array + 1;
                if (contador1 == tam_lista1){
                    return lista_aux;
                    }
                }
            }
                
        if (lis1[contador1] < list2[contador2]){
                lista_aux[cont_array] = lis1[contador1];
                contador1 = contador1 + 1;
                cont_array = cont_array + 1;
            }
        else{
            lista_aux[cont_array] = list2[contador2];
            contador2 = contador2 + 1;
            cont_array = cont_array + 1;
            }
    }
}







void print_array(int array[], int tam_array){
    for (int i = 0; i < tam_array; i++){
        printf("%d ", array[i]);
    }
}


int main(){
    int numero_de_casos;
    scanf("%d",&numero_de_casos);
    for (int caso=0; caso<numero_de_casos; caso++) {
        int tam_array;
        scanf("%d" ,&tam_array);
        int array[tam_array];
        for (int j=0; j<tam_array; j++){
            scanf("%d" ,&array[j]);
        }

    }
    
    return 0;
}