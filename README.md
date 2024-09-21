# Repositório para estudos em grafos

Este repositório tem por objetivo firmar meus conhecimentos na matéria de grafos. Estou estudando pelo livro Projeto de Algoritmos do Nívio Ziviani.

## DFS 

A busca em profundidade (depth-first search) é um algoritmo para caminhar no grafo cuja estratégia é a de buscar, sempre que possível, o mais profundo no grafo. As arestas são exploradas a partir do vértice v mais recentemente descoberto que ainda possui arestas não exploradas saindo dele. Quando todas as arestas adjacentes à v tiverem sido exploradas então a busca anda para trás (backtrack) para explorar vértices que saem do vértice do qual v foi descoberto. ***O processo continua até que todos os vértices alcançáveis a partir do vértice original sejam descobertos***. [Ziviani]

O algoritmo é base para verificação de grafos acíclicos, ordenação topológica e componentes fortemente conectados.

A complexidade total do DFS é de O(|v| + |a|) isto é porque durante a execução do DFS, cada vértice é visitado uma única vez e, para cada vértice, são exploradas todas as suas arestas adjacentes. Assim, o tempo gasto é proporcional à soma do número de vértices e do número de arestas no grafo.

#### Exemplo de DFS

Imprimindo Grafo G...
Vértice 0:  -> Vértice 1 (Peso 10) -> Vértice 2 (Peso 20)
Vértice 1:  -> Vértice 3 (Peso 40)
Vértice 2:  -> Vértice 4 (Peso 50)
Vértice 3: 
Vértice 4: 

-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
Executando DFS...
Iniciando DFS a partir do vértice 0
Visitando vértice  0 - Tempo de descoberta:  1 [CINZA]
Visitando vértice  1 - Tempo de descoberta:  2 [CINZA]
Visitando vértice  3 - Tempo de descoberta:  3 [CINZA]
Vértice  3 - Tempo de término:  4 [PRETO]
Vértice  1 - Tempo de término:  5 [PRETO]
Visitando vértice  2 - Tempo de descoberta:  6 [CINZA]
Visitando vértice  4 - Tempo de descoberta:  7 [CINZA]
Vértice  4 - Tempo de término:  8 [PRETO]
Vértice  2 - Tempo de término:  9 [PRETO]
Vértice  0 - Tempo de término: 10 [PRETO]


