# Árvores de Pesquisa
O que ganhamos com tal transformação em comparação com a simples implementação de um dicionário por, digamos, um array? Ganhamos na eficiência do tempo de busca, inserção e exclusão, que estão todos em (log n), mas apenas na média caso. No pior caso, essas operações estão em (n) porque a árvore pode degenerar em um severamente desequilibrado com sua altura igual a n − 1.

## Tipos de arbodagens de implementação:
### Simplificação de Instâncias
Auto-equilibrio
Uma árvore AVL requer a diferença entre as alturas das subárvores esquerda e direita de cada nó nunca excedem 1.
A árvore red-black tolera que a altura de uma subárvore seja duas vezes maior que a outra subárvore do mesmo nó. Se uma inserção ou exclusão de um novo nó cria uma árvore com um requisito de saldo violado, a árvore é reestruturada por um de uma família de transformações especiais chamadas rotações que restauram a equilíbrio necessário.
### Mudança de representação
permitir mais de um elemento em um nó de uma árvore de busca
Eles diferem no número de elementos admissíveis em um único nó de uma árvore de busca, mas todos são perfeitamente equilibrada.

## AVL Trees
Uma árvore AVL é uma árvore binária de busca na qual o fator de equilíbrio de cada nó, que é definido como a diferença entre as alturas do nó subárvores esquerda e direita, é 0 ou +1 ou −1.
### Tipos de Rotação
#### 1 tipo
O primeiro tipo de rotação é chamado de rotação única à direita ou rotação R
R simples em sua forma mais geral Formato. Observe que esta rotação é realizada após a inserção de uma nova chave no subárvore esquerda do filho esquerdo de uma árvore cuja raiz tinha o saldo de +1 antes do inserção.
A rotação simétrica única à esquerda, ou rotação L, é a imagem espelhada do rotação R única. É executado após uma nova chave ser inserida na subárvore direita do filho direito de uma árvore cuja raiz tinha o saldo de -1 antes da inserção.
#### 2 tipo
O segundo tipo de rotação é chamado de dupla rotação esquerda-direita (LRrotation).
uma combinação de duas rotações: realizamos a rotação L da subárvore esquerda da raiz r seguida pela rotação R da nova árvore enraizada em r
As desigualdades implicam imediatamente que as operações de busca e inserção são (log n) no pior caso.

pesquisar em uma árvore AVL requer, em média, quase o mesmo número de comparações que pesquisar em uma matriz ordenada por busca binária.
A operação de exclusão de chave em uma árvore AVL é consideravelmente mais difícil do que a inserção, mas felizmente acaba por estar na mesma classe de eficiência que inserção