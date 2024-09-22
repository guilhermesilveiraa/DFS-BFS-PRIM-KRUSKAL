# Repositório para estudos em grafos ⚪->⚪->⚪

Este repositório tem por objetivo firmar meus conhecimentos na matéria de grafos. Estou estudando pelo livro Projeto de Algoritmos do Nívio Ziviani.

## DFS ⛏️

A busca em profundidade (depth-first search) é um algoritmo para caminhar no grafo cuja estratégia é a de buscar, sempre que possível, o mais profundo no grafo. As arestas são exploradas a partir do vértice v mais recentemente descoberto que ainda possui arestas não exploradas saindo dele. Quando todas as arestas adjacentes à v tiverem sido exploradas então a busca anda para trás (backtrack) para explorar vértices que saem do vértice do qual v foi descoberto. ***O processo continua até que todos os vértices alcançáveis a partir do vértice original sejam descobertos***. [Ziviani]

O algoritmo é base para verificação de grafos acíclicos, ordenação topológica e componentes fortemente conectados.

A complexidade total do DFS é de O(|v| + |a|) isto é porque durante a execução do DFS, cada vértice é visitado uma única vez e, para cada vértice, são exploradas todas as suas arestas adjacentes. Assim, o tempo gasto é proporcional à soma do número de vértices e do número de arestas no grafo.

### Pseudo-código

        DFS(Grafo G, Vértice v):
        Marque v como visitado
        Para cada vizinho u de v:
                Se u não foi visitado:
                DFS(G, u)


#### Exemplo de DFS (saida main_dfs.c) 

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

## BFS 📏

A busca em largura é assim chamada porque ela expande a fronteira entre os vértices descobertos e não descobertos uniformemente por meio da largura da fronteira. O algoritmo é base para o algoritmo de Prim e Djkistra. Dado um grafo G(V,A) e um vértice origem u, a busca em largura explora sistematicamente as arestas de G com o objetivo de descobrir todos os vértices que são alcançáveis a partir de u. Para acompanhar o progresso do algoritmo cada vértice é colorido de branco, cinza ou preto. Todos os vértices são inicializados brancos, podem posteriormente se tornarem cinzas e finalmente pretos. Quando um vértice é descoberto pela primeira vez durante a busca ele se torna cinza.

**Se (*u*,*v*) pertencem A e o vértice u é preto, então o vértice v tem de ser cinza ou preto, o que significa que todos os vértices adjacentes a vertices pretos já foram descobertos. Vértices cinzas podem ter alguns vértices adjacentes brancos, e eles representam a fronteira entre vértices descobertos e não descobertos.** [Ziviani]

O procedimento de busca em largura possui complexidade de tempo total igual a *O(V+A)* porque visita todos os vértices e explora todas as arestas do grafo. Cada vértice é processado uma vez, contribuindo com O(V), e cada aresta é verificada uma vez, somando O(A). Assim, o tempo total é proporcional à soma do número de vértices (V) e arestas (A) no grafo.

### Pseudo-código

        BFS(Grafo G, Vértice v):
        Crie uma fila e adicione v
        Marque v como visitado
        Enquanto a fila não estiver vazia:
                u = Remova o primeiro elemento da fila
                Para cada vizinho w de u:
                Se w não foi visitado:
                        Marque w como visitado
                        Adicione w à fila

### Exemplo de BFS (saida main_bfs.c)

        Imprimindo Grafo G...
        Vértice 0:  -> Vértice 1 (Peso 10) -> Vértice 2 (Peso 20)
        Vértice 1:  -> Vértice 3 (Peso 40)
        Vértice 2:  -> Vértice 4 (Peso 50)
        Vértice 3:  -> Vértice 5 (Peso 70)
        Vértice 4: 
        Vértice 5:  -> Vértice 6 (Peso 60)
        Vértice 6: 

        -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
        Executando BFS...
        
        Enfileirando item na posição 1, valor: 0
        Visita origem  0 cor: cinza

        Fila: [ 0 ]
        Desenfileirando item da posição 1, valor: 0
        Enfileirando item na posição 2, valor: 1
        
        Enfileirando vértice  1 (dist 1)
        Fila: [ 1 ]
        
        Enfileirando item na posição 3, valor: 2
        Enfileirando vértice  2 (dist 1)
        Fila: [ 1 2 ]
        Visita  0 Dist  0 cor: preto

        Fila: [ 1 2 ]
        Desenfileirando item da posição 2, valor: 1
        Enfileirando item na posição 4, valor: 3
        Enfileirando vértice  3 (dist 2)
        Fila: [ 2 3 ]
        Visita  1 Dist  1 cor: preto

        Fila: [ 2 3 ]
        Desenfileirando item da posição 3, valor: 2
        Enfileirando item na posição 5, valor: 4
        Enfileirando vértice  4 (dist 2)
        Fila: [ 3 4 ]
        Visita  2 Dist  1 cor: preto

        Fila: [ 3 4 ]
        Desenfileirando item da posição 4, valor: 3
        Enfileirando item na posição 6, valor: 5
        Enfileirando vértice  5 (dist 3)
        Fila: [ 4 5 ]
        Visita  3 Dist  2 cor: preto

        Fila: [ 4 5 ]
        Desenfileirando item da posição 5, valor: 4
        Visita  4 Dist  2 cor: preto

        Fila: [ 5 ]
        Desenfileirando item da posição 6, valor: 5
        Enfileirando item na posição 7, valor: 6
        Enfileirando vértice  6 (dist 4)
        Fila: [ 6 ]
        Visita  5 Dist  3 cor: preto

        Fila: [ 6 ]
        Desenfileirando item da posição 7, valor: 6
        Visita  6 Dist  4 cor: preto

        Fila está vazia.

## Prim 🌳🤏

O algoritmo de Prim utiliza estratégia gulosa que permite obter a árvore geradoa mínima adicionando-se uma aresta de cada vez. O algoritmo gerencia um subconjunto de *S* arestas. Ele começa com um vértice arbitrário e expande a árvore geradora mínima ao adicionar, em cada etapa, a aresta de menor peso que conecta um vértice dentro da árvore a um vértice fora dela, até que todos os vértices sejam incluídos. A complexidade do algoritmo é O(V2)O(V2) com matrizes de adjacência, ou *O(Elog⁡V)* *O(ElogV)* quando implementado com filas de prioridade e listas de adjacência, onde V é o número de vértices e E o número de arestas.


### Pseudo-código 

        PRIM(Grafo G, Vértice inicial):
        Marque todos os vértices como não visitados
        Defina a árvore geradora mínima vazia
        Adicione o vértice inicial à árvore
        Enquanto todos os vértices não estiverem na árvore:
                Selecione a menor aresta (u, v) onde u está na árvore e v não está
                Adicione v à árvore
                Marque v como visitado

## Exemplo (saída main_prim.c)

        Imprimindo Grafo G...

        Vértice 0:  -> Vértice 1 (Peso 10) -> Vértice 2 (Peso 20)
        
        Vértice 1:  -> Vértice 3 (Peso 40)
        
        Vértice 2:  -> Vértice 4 (Peso 50) -> Vértice 3 (Peso 10)
        
        Vértice 3: 
        
        Vértice 4:  -> Vértice 0 (Peso 60)

        -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
        
        Executando Prim...
        
        Iniciando do vértice 2...
        
        Arestas da árvore geradora mínima:
        
        Vértice 0: -> Vértice 1 (Peso 10)
        
        Vértice 1: -> Vértice 2 (Peso 0)
        
        Vértice 2: -> Vértice 3 (Peso 10)
        
        Vértice 3: -> Vértice 4 (Peso 50)

## Kruskal 🌳🤏

Assim como o algoritmo de Prim, o algoritmo de Kruskal obtém uma árvore geradora mínima. No algoritmo de Kruskal, o conjunto *S* é uma floresta. Ele começa com uma floresta, onde cada vértice é inicialmente considerado uma árvore separada. O algoritmo classifica todas as arestas em ordem crescente de peso e, em seguida, adiciona as arestas de menor peso que não formam ciclos, até que todos os vértices estejam conectados em uma única árvore. Isso é feito com o uso de uma estrutura de união e busca (Union-Find) para verificar se a adição de uma aresta criaria um ciclo. O custo da árvore geradora mínima é a soma dos pesos das arestas que fazem parte da árvore resultante, *O(ElogE)*.

### Pseudo-Código

KRUSKAL(G):

    Inicializar uma floresta F (cada vértice é uma árvore individual)
    Inicializar um conjunto vazio T para armazenar as arestas da árvore geradora mínima
    Ordenar todas as arestas de G por peso crescente
    Para cada aresta (u, v) em ordem crescente de peso:
        Se u e v pertencem a diferentes componentes (árvores):
            Adicionar a aresta (u, v) ao conjunto T
            Unir as árvores que contêm u e v
    Retornar T (as arestas da árvore geradora mínima)

### Exemplo (saida main_kruskal.c) 

