### Valgrind -> verificar se a utilização de memória e ponteiros não possuem limo

# Ordenção (mergesort)
## Duvida dos alunos:
##### Italo -> Qaundo usar selection/bubble, inserction or merge (quicksort)?
R: Dificilmente usamos esses algoritmos, geralmente é usado o quicksort (Principal) ou o merge sort.
##### Eduardo -> qual pate do inserctions faz que ele seja decrease-and-conquist?
R: Ele é mais de força bruta
##### Tiago -> Dificuldade para entender a lógica do merge
R: É um mais estável. -> Se houver empartes ele sai devido a ordem da entrada -> Ordenação ## Múltipla~ ##
ex: 
Times   Pontos   SG
A       	30      	7
B      	 	20      	12
C       	20			5
mergesort(value=SG) -> mergesort(value=points)
#### O inserction sort x merge sort
merge precisa de uma memória extra do mesmo tamanho da entrada
