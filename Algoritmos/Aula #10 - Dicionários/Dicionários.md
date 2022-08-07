# Conjuntos
## Conjuntos
Um conjunto na matemática é uma coleção não ordenada de coisas, chamados de elementos do conjunto. A forma de implementação é geralmente feita usando listas ou array, mas também pode ser feita em forma de string.
## Tempo e Espaço
a ideia é pré-processar a entrada do problema, no todo ou em parte, e armazenar as informações adicionais obtidas para acelerar resolvendo o problema depois
O outro tipo de técnica que explora as compensações espaço-tempo simplesmente usa espaço extra para facilitar o acesso mais rápido e/ou mais flexível aos dados. abordagem pré-estruturação. Este nome destaca duas facetas desta variação do trade-off espaço por tempo: algum processamento é feito antes que um problema em questão seja realmente resolvido, mas, ao contrário da variedade de aprimoramento de entrada, lida com acesso
programação dinâmica. Esta estratégia baseia-se em soluções de gravação para subproblemas sobrepostos de um determinado problema em uma tabela da qual uma solução para o problema em questão é então obtido
se a porcentagem de zeros em tais objetos for suficientemente alta, podemos salvar tanto espaço e tempo ignorando zeros na representação e processamento dos objetos. -> compressão de arquivos
não se pode discutir trade-offs espaço-tempo sem mencionar a área extremamente importante de compressão de dados.
## Hashing e Dicionários
Dicionários -> um conjunto com as operações de pesquisa (pesquisa), inserção e exclusão definida em seus elementos. Os elementos deste conjunto pode ser de natureza arbitrária: números, caracteres de algum alfabeto, cadeias de caracteres e assim por diante.
um conjunto com as operações de pesquisa (pesquisa), inserção e exclusão definida em seus elementos. Os elementos deste conjunto pode ser de natureza arbitrária: números, caracteres de algum alfabeto, cadeias de caracteres e assim por diante
Operações com mod.
##### Regras para utilizar o hash
1. A extenção do hash não deve ser excessivamente grande em comparação com o número de chaves, mas deve ser suficiente para não comprometer o tempo de implementação eficiência.
2. Uma função de hash precisa distribuir chaves entre as células da tabela de hash como uniformemente possível
3. Uma função hash deve ser fácil de calcular.
Se escolhermos o tamanho m de uma tabela de hash para ser menor que o número de chaves n, teremos colisões - um fenômeno de duas (ou mais) chaves sendo hash na mesma célula da tabela de hash.
boa função de hash, esta situação acontece muito raramente. Ainda assim, todo esquema de hash deve ter um mecanismo de resolução de colisão.
#### Versões principais de hash
1. hashing aberto (também chamado de encadeamento separado)
2. hash fechado (também chamado de endereçamento aberto).
### Open hashing (encadeamento separado)
No hash aberto, as chaves são armazenadas em listas vinculadas anexadas às células de uma tabela de hash. Cada lista contém todas as chaves com hash para sua célula.
As duas outras operações de dicionário — inserção e exclusão — são quase idêntico à pesquisa. As inserções são normalmente feitas no final de uma lista .
A exclusão é realizada procurando uma chave a ser excluída e, em seguida, removendo ele de sua lista. Portanto, a eficiência dessas operações é idêntica à de pesquisando, e eles são todos (1) no caso médio se o número de chaves n for aproximadamente igual ao tamanho m da tabela de hash.
Exemplo, iagine que queemos encontrar a palavra 'chave' na string 'Eu perdi a minha chave'. Podemos acelerar a busca dividindo keys como por exemplo o tamanho de cada palavra, assim teríamos [1]->'a' ; [2]-> 'Eu'; [5]->'perdi', 'minha', 'chave'. Assim ao invés de procurrar em toda a string, basta procurar na key onde o numero de letras é igual a quantidade pesquisada
### Closed hashing (endereçamento aberto)
No hash fechado, todas as chaves são armazenadas na própria tabela de hash sem o uso de listas encadeadas. (Claro, isso implica que o tamanho da tabela m deve ser pelo menos tão grande quanto o número de chaves n.)
Diferentes estratégias podem ser empregadas para colisão resolução. O mais simples - chamado de sondagem linear - verifica a célula seguinte aquele em que ocorre a colisão. Se essa célula estiver vazia, a nova chave será instalada lá; se a próxima célula já estiver ocupada, a disponibilidade imediata dessa célula sucessor é verificado, e assim por diante.
à medida que a tabela de hash se aproxima de estar cheia, o desempenho da sondagem linear se deteriora por causa de um fenômeno chamado agrupamento.
Um cluster em linear sondagem é uma sequência de células ocupadas contiguamente. À medida que os clusters se tornam maiores, a probabilidade de que um novo elemento seja anexado a um cluster aumenta; Além disso, grandes aglomerados aumentam a probabilidade que dois clusters irão se unir após a inserção de uma nova chave, causando ainda mais agrupamento.
À medida que os clusters se tornam maiores, a probabilidade de que um novo elemento seja anexado a um cluster aumenta; Além disso, grandes aglomerados aumentam a probabilidade que dois clusters irão se unir após a inserção de uma nova chave, causando ainda mais agrupamento.

Com isso foram criados métodos para ajudar na questões de colisões como o hash duplo, porém a análise matemática do hash duplo provou ser bastante difícil. Algum resultados parciais e considerável experiência prática com o método sugerem que com boas funções de hash - primárias e secundárias - o hash duplo é superior para sondagem linear. Mas seu desempenho também se deteriora quando a mesa fica perto de estar cheio.Uma solução natural em tal situação é refazer: o atual tabela é verificada e todas as suas chaves são realocadas em uma tabela maior.