#include<stdio.h>
#include<stdlib.h>

void merge(int vetor[], int ini_p1, int fim_p1, int ini_p2, int fim_p2){ //função para integrar
    // vetor auxiliar com alocação dinâmica
    int *vet_temp;
    vet_temp = (int*)malloc(((fim_p1 - ini_p1) + (fim_p2 - ini_p2))*sizeof(int));

    // contadores
    int i, j, k;
    i = ini_p1;
    j = ini_p2;
    k = 0;
    
    // Vamos iniciar a brincadeira hehe
    while (i <= fim_p1 && j <= fim_p2){
        if (vetor[i] < vetor[j]){
            vet_temp[k++] = vetor[i++];
        }else{vet_temp[k++] = vetor[j++];}
    }
    // Colocar elementos restantes da primeira parte
    while (i <= fim_p1){
        vet_temp[k++] = vetor[i++];
    }
    // Colocar elementos restantes da segunda parte
    while (j <= fim_p2){
        vet_temp[k++] = vetor[j++];
    }
    // Por os elementos ordenados no vetor inicial
    for (i = ini_p1, j = 0; i <= fim_p2; i++, j++){
        vetor[i] = vet_temp[j];
    }
    free(vet_temp);
    *vet_temp = NULL;
}

void mergesort(int vetor[], int inicio, int fim){ //função para dividir
    if (inicio < fim){
        // meio do vetor
        int meio = (inicio + fim)/2;

        // recurssões
        mergesort(vetor, inicio, meio); // Inicio ae o meio
        mergesort(vetor, meio +1, fim); // Meio até o fim

        // Reunião
        merge(vetor, inicio, meio, meio+1, fim); //

    }
}


int main(){
    // entrada da quantidade de casos
    int numero_de_casos;
    scanf("%d",&numero_de_casos);

    // Laço com a quantidade de casos
    for (int caso=0; caso<numero_de_casos; caso++) {
        // identificar tamanho do array
        int tam_array;
        scanf("%d" ,&tam_array);
        int array[tam_array];

        // laco para instrir os valores no array
        for (int j=0; j<tam_array; j++){
            scanf("%d" ,&array[j]);}

        // função do mergesort
        mergesort(array, 0, tam_array-1);

        // laço para imrimir o array
        for (int i=0; i < tam_array; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        
    }

    return 0;
}