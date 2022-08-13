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
