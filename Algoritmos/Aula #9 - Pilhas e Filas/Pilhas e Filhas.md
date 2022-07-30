## Pilhas
### “Last-In, First-Out”
A pilha é uma estrutura semelhante a uma lista na qual os elementos podem ser inseridos ou removidos de apenas uma extremidade. Embora esa restriçao a torne menos inflexível que as listas, em alguns casos é mais vantajoso.
### Pilhas com Arrays
A implementação de pilha baseada em array é essencialmente uma versão simplificada do lista baseada em array. A única decisão de projeto importante a ser tomada é qual lado a matriz deve representar o topo da pilha. Uma escolha é fazer com que o topo seja na posição 0 na matriz, assum todas as adições e remoções ficariam na primeira posição, porém isso é périmo pois teá que mover todos os outros itens do array.
### Pilhas Ligadas
A implementação da pilha vinculada é bastante simples e melhor, comparando com a por array pois os elementos são inseridos e removidos apenas do cabeça da lista, ou seja não precisa mover todos os itens da lista.
O método push first modifica o próximo campo do link recém-criado nó para apontar para o topo da pilha e, em seguida, define o topo para apontar para o novo link nó.
método pop também é bastante simples. A variável temp armazena o valor dos nós superiores, enquanto ltemp se liga ao nó superior à medida que é removido da pilha.
A pilha é atualizado definindo top para apontar para o próximo link na pilha. O antigo nó superior é em seguida, retornado ao free store (ou freelist), e o valor do elemento é retornado.
### Pilhas Ligadas x Pilhas com Arrays
Em questão de implementação, ambas gastam basicamente o mesmo tempo. Na questão do espaço, a pilha ligada leva desvantegem pois a com array precisa ser definida com um tamalho eter´que ter aquele mesmo tamanho, a lista vazia ou não.
Quando várias pilhas devem ser implementadas, é possível aproveitar o crescimento unidirecional da pilha baseada em array. Isso pode ser feito usando um único array para armazenar duas pilhas.
### Implementando a Recurssão
O aplicativo em um computador que mais usa as pilhas (as vezes nem de forma visível) é a subrotina, que é normalmente implementada por colocando as informações necessárias sobre a sub-rotina (incluindo o endereço de retorno, parâmetros e variáveis locais em uma pilha. Esta informação é chamada de **ativação registro.**
Cada retorno de um sub-rotina retira o registro de ativação superior da pilha.
Como um registro de ativação deve ser criado e colocado na pilha para cada chamada de sub-rotina, fazer chamadas de sub-rotina é uma operação relativamente cara. Embora a recursão seja frequentemente usada para tornar a implementação fácil e clara, às vezes você pode querer eliminar a sobrecarga imposta pelas chamadas de função recursivas.
Em alguns casos, a recursão pode ser facilmente substituído por iteração. Uma forma iterativa da função fatorial é mais simples e mais rápida, mas nem sempre é possível substituir a recursão com iteração.
lgoritmos recursivos se prestam à implementação eficiente com uma pilha.
# Filas
la é uma estrutura semelhante a uma lista que fornece acesso restrito a seus elementos.
Elementos de fila só podem ser inseridos na parte de trás (chamado de enfileiramento operação) e removido da frente (chamado de operação de desenfileiramento) .
Assim, as filas liberam seus elementos por ordem de chegada. Contadores usam filas muito antes da existência dos computadores “First-In, First-Out"
### Filas baseadas em arrays
operações de enfileiramento exigirão (n) tempo, porque os n elementos atualmente em a fila deve ser deslocada uma posição na matriz. Se em vez disso, escolhemos o elemento traseiro da fila para estar na posição n 􀀀 1, então uma operação de enfileiramento é equivalente a uma operação de acréscimo em uma lista. Isso requer apenas (1) tempo. Mas agora, uma operação de desenfileiramento requer (n) tempo, porque todos os elementos devem ser deslocado para baixo em uma posição para manter a propriedade de que o restante n 􀀀 1 os elementos da fila residem nas primeiras n 􀀀 1 posições da matriz.
Uma implementação muito mais eficiente pode ser obtida relaxando o requisito que todos os elementos da fila devem estar nas primeiras n posições do array. Ainda exigiremos que a fila seja armazenada em posições de array contíguas, mas o conteúdo da fila terá permissão para se deslocar dentro da matriz, conforme ilustrado pela Figura 4.24. Agora, as operações de enfileiramento e desenfileiramento podem ser executado em (1) tempo porque nenhum outro elemento na fila precisa ser movido. Porém essa implementação tem um problema, pos se retiramos um  item da lista iremos criar um vazio na parte da lista, para solucionar ta problemas, pdemos implementar um list circular, utiizando o operador MOD (% em C++), o qual será n mod M (M -> tamanho do array)![[Pilhas.pptx]]