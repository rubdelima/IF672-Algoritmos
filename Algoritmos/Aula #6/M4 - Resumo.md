# Fundamentos da Análise de Eficiência de Algoritmos
Dois principais focos: tempo de duação e espaço na memória
A eficiência não pode ser estudada em termos quantitativos
## The Analysis Framework
##### Capítulo 2 (41-49)
**Time efficiency**, also called time complexity, indicates how fast an algorithm in question runs. 
**Space efficiency**, also called space complexity, refers to the amount of memory units required by the algorithm in addition to the space needed for its input and output.
### Mensurando o tamanho de uma entrada
Temos a demora de coisas triviais como a ordenação de um array longo, multiplicação de um matriz larga, mas como poderiamos medir de forma unca todas essas possibilidades? É um pouco incerto, pois por exemplo em uma multiplicação da matrizes, poderiamos colocar omo nivel de dificuldade o tamanhpoa da matriz, mas também temos que levar em consideração que há uma outra matri que irá aumentar a dificuldade.
Mas em geral utilizamos para medir o tamanho pelo número de bits (b) em uma representação binária de 'n', desta forma: b = L log2 (n) | + 1.
#### Unidades para medir o tempo de execução
Nós podemos utilizar apenas o tempo padrão que usamos como segundos ou nano segundos, mas tal forma teriamos problemas devidos a dependência da velocidade de um determinado computador, da qualidade de um programa que implementa o algoritmo e do compilador usado na geração do código de máquina e a dificuldade de cronometrar o tempo real de execução do programa. Então podemos contar quantas vezes a operação que cada um dos algoritmos é executada, porém essa maneira é excessivamente muito difícil.
A velocidade de um algoritmo também depende de sua opraçõ, exemplo, paraa a ordenação de uma lista usamos uma chave para realiza uma comparação, em outros casos como operações matemáticas temos o tempo de cada operaçõa, a mais demorada é a de divisão, seguida por multiplicação, adição e subtração (podemos considerar os dois ultimos como um só).
Assim, a estrutura estabelecida para a análise da eficiência de tempo de um algoritmo
sugere medi-lo contando o número de vezes que o algoritmo operação básica é executada em entradas de tamanho n.
Seja cop o tempo de execução de um algoritmo
operação básica em um computador particular, e seja C(n) o número de
vezes esta operação precisa ser executada para este algoritmo. Então podemos estimar o tempo de execução T(n) de um programa implementando este algoritmo naquele computador
pela fórmula T(n) ~~ copC(n).
A estrutura de análise de eficiência ignora constantes e concentra-se na ordem de crescimento da contagem para dentro de uma constante múltiplo para entradas de tamanho grande.
#### Ordem de Crescimento
uando temos que calcular, por exemplo, o
máximo divisor comum de dois números pequenos, não está imediatamente claro como o algoritmo de Euclides muito mais eficiente é comparado aos outros dois algoritmos discutido na Seção 1.1 ou mesmo por que devemos nos preocupar com qual deles é mais rápido e por quanto. É somente quando temos que encontrar o máximo divisor comum de dois grandes números que a diferença na eficiência do algoritmo se torna clara e importante.
Algoritmos que requerem um número exponencial de operações são práticos para resolver apenas problemas de tamanhos muito pequenos.
#### Pior Caso, Melhor Caso e Eficiência do Maximo de Casos
Existem muitos algoritmos que não dependem apenas do tamanho da entrada, mas também da especificidade da etrada, exemplo, há casos que o melhor caso de algoritmo de brute force é melhor que um algoritmo de conqueer and conquiste, .(o qual na maioria dos casos seria o opsto), porém no pior caso possivel um elemento como o de busca binária seria mais rapido que o de busca sequencial. Ou seja, no pior caso, a busca binária é mais rápida, porém no melhor caso, a busca sequencial será a mais rápida.
O caso médio nós para fazer isso envolve dividir todas as instâncias de tamanho n em várias classes de modo que para cada instância do class o número de vezes que a operação básica do algoritmo é executada é a mesma.

## Notas Assintóticas e Classes Básicas de Eficiência
##### Capitulo 2 (52-58)
Para comparar e classificar esses pedidosde crescimento e a eficiência, os cientistas da computação usam três notações: O (big oh), (big omega) e (teta grande).
#### Introdução Informal
##### Função O
Dizemos que um cerno numero se ele pertencer a uma quantidae menor q a função suporta, ex 500n +1 £ O(n²), n² £ O(n²), mas 0.0000n³ \£ O(n²).
##### Função  Ω
epresenta o conjunto de todas as funções com maior ou mesma ordem de crescimento que g(n) (para dentro de um múltiplo constante, como n vai para o infinito). Por exemplo, n3 ∈ (n2), mas 100n \£ Ω(n²).
###### Função  (<->)
Se um caso se encontra nessa funçao se tiver a mesma ordem
### Propriedades Úteis para as notações assíntóticas
t1(n) + t2(n) ∈ O(max{g1(n), g2(n)}).
Por exemplo, podemos verificar se um array tem elementos iguais da seguinte forma algoritmo de duas partes: primeiro, ordenar o array aplicando algum algoritmo de ordenação conhecido; segundo, escaneie a matriz classificada para verificar a igualdade de seus elementos consecutivos. Se, por
Por exemplo, um algoritmo de ordenação usado na primeira parte não faz mais do que 1/2 n(n − 1) comparações (e, portanto, está em O(n2)), enquanto a segunda parte não faz mais do que n − 1 comparações (e, portanto, está em O(n)), a eficiência de todo o algoritmo estará em O(max{n2, n}) = O(n2).
#### Usando Limites para comparar ordens de crescimento
lim t(n)/g(n)
x -> (inf)
0 implies that t (n) has a smaller order of growth than g(n),
c implies that t (n) has the same order of growth as g(n),
∞ implies that t (n) has a larger order of growth than g(n).3
##### Aulas Básicas de Eficiência
Nas nem sempre quer dizer que um de ordem menor é mais eficiente, ex em um de 2 grau 106n² e outro n³, o n³ irá superara outro, at´que n seja > 106

## Análise Matemática de Algoritmos Não Recursivos
##### Capítulo 2 (61-66)
Plano Geral para Análise da Eficiência Temporal de Algoritmos Não Recursivos
1. Decida sobre um parâmetro (ou parâmetros) indicando o tamanho de uma entrada.
2. Identifique a operação básica do algoritmo. (Como regra, ele está localizado na parte mais interna
ciclo.)
3. Verifique se o número de vezes que a operação básica é executada depende
apenas no tamanho de uma entrada. Se também depender de alguma propriedade adicional,
as eficiências do pior caso, do caso médio e, se necessário, do melhor caso devem
ser investigados separadamente.
4. Configure uma soma expressando o número de vezes que a operação básica do algoritmo
é executado.4
5. Usando fórmulas padrão e regras de manipulação de soma, encontre uma forma fechada
fórmula para a contagem ou, no mínimo, estabelecer sua ordem de crescimento.

Exemplos
1. Identificar maior elemento num array será de n²
2. Identificar se há repetição de um mesmo numero num array será n(n-1)/2
3. Calculo de uma multiplicação de uma matriz quadrada n(elem da 1)*(eleme da 2)*(numero de multip) -> n³
4. while n > 1 do
count ←count + 1
n←n/2
tem log2(n)

## Análise Matemáticas de Algoritmos Recursivos
##### Capitulo 2 (70-73)
ex em uma funcao fatorial fazemos F(n) = F(n-1)
Plano Geral para Análise da Eficiência Temporal de Algoritmos Recursivos
1. Decida sobre um parâmetro (ou parâmetros) indicando o tamanho de uma entrada.
2. Identifique a operação básica do algoritmo.
3. Verifique se o número de vezes que a operação básica é executada pode variar
em diferentes entradas do mesmo tamanho; se puder, o pior caso, o caso médio e
eficiências do melhor caso devem ser investigadas separadamente.
4. Estabeleça uma relação de recorrência, com uma condição inicial apropriada, para o
número de vezes que a operação básica é executada.
5. Resolva a recorrência ou, pelo menos, verifique a ordem de crescimento de sua solução.

##  Anáise Empírica de Algoritmos
##### Capitulo 2 (84-89)
Plano Geral para a Análise Empírica do Algoritmo de Eficiência Temporal
1. Entenda o objetivo do experimento.
2. Decidir sobre a métrica de eficiência M a ser medida e a unidade de medida
(uma contagem de operação versus uma unidade de tempo).
3. Decida sobre as características da amostra de entrada (seu intervalo, tamanho e assim por diante).
4. Prepare um programa implementando o algoritmo (ou algoritmos) para a experimentação.
5. Gere uma amostra de insumos.
6. Execute o algoritmo (ou algoritmos) nas entradas da amostra e registre os dados
observado.
7. Analise os dados obtidos.
medir o teo, alterar a dificuldade

Por outro lado, a forma de um gráfico de dispersão também pode ajudar a determinar
a provável classe de eficiência do algoritmo. Para um algoritmo logarítmico, o gráfico de dispersão
terá uma forma côncava (Figura 2.7a); esse fato o distingue
todas as outras classes básicas de eficiência. Para um algoritmo linear, os pontos tenderão
agregar em torno de uma linha reta ou, mais geralmente, estar contido entre
duas linhas retas (Figura 2.7b). Gráficos de dispersão de funções em (n lg n) e (n2)
terão uma forma convexa (Figura 2.7c), dificultando sua diferenciação
## Visualização de Algoritmos
##### Capitulo 2 (91-95)
Usada para educação e pesquisa
Existem duas variações principais de visualização de algoritmos:
Visualização de algoritmo estático
Visualização dinâmica de algoritmo, também chamada de animação de algoritmo
A visualização de algoritmo estático mostra o progresso de um algoritmo através de uma série
de imagens fixas. A animação do algoritmo, por outro lado, mostra uma
apresentação semelhante a um filme das operações de um algoritmo.
Sorting Out Sorting - Video famoso
representações por bara ou scatterplot
## Brute Force
##### Capitulo 3 (97-98)
A força bruta pode ser descrita da seguinte forma:
A força bruta é uma abordagem direta para resolver um problema, geralmente
diretamente baseado no enunciado do problema e nas definições dos conceitos
envolvidos.
A “força” implícita na definição da estratégia é a de um computador e
não a do intelecto. "Apenas faça!"