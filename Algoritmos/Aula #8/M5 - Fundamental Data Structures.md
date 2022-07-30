estrutura pode ser definida como um esquema particular de organização de itens de dados relacionados.
## Linear Data Structures
As mais importantes estruturas de dados lineares sõ o array e a lista linkada.
Um array (unidimensional) é uma sequencia de n iten do mesmo tipo que são armazenados proximos na memória, e são acessados indicando a posição que ele está na lista, de um numero variando entre 0 de n-1 ou 1 e n.
Arrays são usados para implementar uma variedade de outras estruturas de dados. Proeminente entre eles está a string, uma sequência de caracteres de um alfabeto terminado por um caractere especial indicando o final da string.

ma lista encadeada é uma sequência de zero ou mais elementos chamados nós, cada um contendo dois tipos de informações: alguns dados e um ou mais links chamados ponteiros para outros nós da lista encadeada.

## Tipos de Data
Por exemplo, o tipo booleano consiste no valores verdadeiro e falso. Os inteiros também formam um tipo. Um inteiro é um simples type porque seus valores não contêm subpartes. Um registro de conta bancária normalmente contêm várias informações, como nome, endereço, número da conta e saldo da conta. Esse registro é um exemplo de um tipo agregado ou composto modelo
Lista. O tipo de dados de lista pode, portanto, ser implementado usando uma lista encadeada ou uma matriz. Mesmo o termo “array” é ambíguo, pois pode se referir a um tipo de dados ou uma implementação. “Array” é comumente usado em programação de computadores para significa um bloco contíguo de locais de memória, onde cada local de memória armazena um item de dados de comprimento fixo
No entanto, array também pode significar um tipo de dados lógico composto por um (tipicamente homogêneo) coleção de itens de dados, com cada item de dados identificado por um índice número.
Um tipo de dados abstrato (ADT) é a realização de um tipo de dados como um software componente. A interface do ADT é definida em termos de um tipo e um conjunto de operações desse tipo. O comportamento de cada operação é determinado por suas entradas e saídas
como C++, um ADT e sua implementação juntos formam uma classe.
O termo “estrutura de dados” geralmente se refere a dados armazenados na memória principal de um computador. O termo relacionado estrutura de arquivo geralmente se refere à organização de dados em armazenamento periférico, como uma unidade de disco ou CD.
Os tipos de dados têm uma forma lógica e física. A definição dos dados tipo em termos de um ADT é sua forma lógica. A implementação do tipo de dados como uma estrutura de dados é sua forma física.
## Listas, Pilhas e Filas
### Listas
Definimos uma lista como uma sequência finita e ordenada de itens de dados conhecidos como elementos. Todos os elementos da lista têm o mesmo tipo de dados. As operações definidas como parte da lista ADT não depende do tipo de dados elementar.
Uma lista é dita vazia quando não contém elementos. O número de elementos atualmente armazenado é chamado de comprimento da lista. O início da lista é chamado de cabeça, o final da lista é chamado de cauda.
Devemos ser capazes de inserir e remover elementos de qualquer lugar na lista. Devemos ser capazes de obter acesso ao valor de qualquer elemento, seja para lê-lo ou alterá-lo. Devemos ser capazes de criar e limpar (ou reinicializar) listas.
Devemos ser capazes de inserir e remover elementos de qualquer lugar na lista. Devemos ser capazes de obter acesso ao valor de qualquer elemento, seja para lê-lo ou alterá-lo. Devemos ser capazes de criar e limpar (ou reinicializar) listas
#### Array-Based List Implementation
