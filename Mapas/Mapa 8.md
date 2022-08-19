# Árvores
Uma árvore é um grafo acíclico conectado. Um grafo que não tem ciclos, mas não é necessariamente conectado é chamado de floresta: cada de seus componentes conectados é uma árvore.
As árvores nós classificamos com a raiz com o vertice principal, e através dele saem os outros vérices até chegar nas folhas, que são vértices com apenas uma conexão.
O  conceito de hierarquia vêm da mesma forma, os vértices (tirando a raiz) possuem sempre um ancestral, que pode ser a raiz ou outro vértice que é caminho dele para a raiz.
Altura de uma árvore é o comprimento do caminho simples mais longo da raiz até uma folha.
### Arvores ordenadas
Uma árvore ordenada é uma árvore enraizada na qual todos os filhos de cada vértices são ordenados. É conveniente supor que em um diagrama de árvore, todos os as crianças são ordenadas da esquerda para a direita.
Uma árvore binária pode ser definida como uma árvore ordenada na qual cada vértice tem não mais do que dois filhos e cada filho é designado como filho esquerdo ou filho filho direito de seu pai; uma árvore binária também pode estar vazia.
#### Árvores Binárias de Busca
Em particular, as árvores de busca binária podem ser generalizadas a tipos mais gerais de árvores de busca chamadas árvores de busca multidirecional.
a eficiência dos algoritmos mais importantes para árvores de busca binária e suas extensões dependem da altura da árvore.
Uma árvore binária geralmente é implementada para fins de computação por uma coleção de nós correspondentes aos vértices da árvore. Cada nó contém algumas informações associado ao vértice (seu nome ou algum valor atribuído a ele) e dois ponteiros para os nós que representam o filho esquerdo e o filho direito do vértice, respectivamente.
## Pesquisa e inserção em uma árvore de busca binária
Para a cada nó todos os elementos na subárvore esquerda são menores e todos os elementos na subárvore subárvore direita. Assim, a cada iteração do algoritmo, o problema de buscar em um árvore de busca binária é reduzida à busca em uma árvore de busca binária menor.
#### Pior caso
No pior caso da busca em árvore binária, a árvore está severamente distorcida. Obviamente, a busca por an−1 em tal árvore requer n comparações, fazendo a eficiência do pior caso da operação de busca cai em (n).
#### Melhor caso
Felizmente, o a eficiência do caso médio acaba sendo em (log n). Com 2 chaves é 2ln n ≈ 1,39 log2 n.
## Percusso de Árvores Binárias e Propriedades Relacionadas
Divide and Conqueer
Uma árvore binária T é definida como um conjunto finito de nós que está vazio ou consiste em uma raiz e duas árvores binárias disjuntas TL e TR chamadas, respectivamente, de subárvore esquerda e direita da raiz.
Função recursiva para saber tamanho da árvore: 
if T = ∅ return −1
else return max{Height(Tlef t ), Height(Tright)} + 1
### Tipos de trajetos
Os algoritmos de divisão e conquista mais importantes para árvores binárias são os algoritmos de divisão e conquista mais importantes para árvores binárias. três percursos clássicos: pré-ordem, inorder e pós-ordem.
Todas as três travessias visitam nós de uma árvore binária recursivamente, ou seja, visitando a raiz da árvore e suas raízes esquerda e subárvores direitas.
**Na travessia de pré-ordem**, a raiz é visitada antes das subárvores esquerda e direita são visitados (nessa ordem).
***No percurso inorder**, a raiz é visitada depois de visitar sua subárvore esquerda, mas antes de visitar a subárvore correta.
***Na travessia pós-ordem***, a raiz é visitada depois de visitar a esquerda e a direita subárvores (nessa ordem).
