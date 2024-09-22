#include "stdio.h"
#include "stdlib.h"
#include "kruskal.h"

int comparaArestas(const void *a, const void *b) {
    Aresta *aresta1 = (Aresta *)a;
    Aresta *aresta2 = (Aresta *)b;
    return aresta1->peso - aresta2->peso;
}

UnionFind* criaUnionFind(int numVerticex) {
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));
    if (uf == NULL) {
        fprintf(stderr, "Erro ao alocar memória para Union-Find.\n");
        exit(1);
    }

    uf->numVerticess = numVerticex; // Adicione isso para inicializar numVertices
    uf->pai = (int *)malloc(numVerticex * sizeof(int));
    uf->rank = (int *)malloc(numVerticex * sizeof(int));

    if (uf->pai == NULL || uf->rank == NULL) {
        fprintf(stderr, "Erro ao alocar memória para pai ou rank.\n");
        exit(1);
    }

    for (int i = 0; i < numVerticex; i++) {
        uf->pai[i] = i;
        uf->rank[i] = 0;
    }
    return uf;
}


int find(UnionFind *uf, int v) {
    if (uf->pai[v] != v) {
        uf->pai[v] = find(uf, uf->pai[v]); // Compressão de caminho
    }
    return uf->pai[v];
}

void unionSets(UnionFind *uf, int v1, int v2) {
    int root1 = find(uf, v1);
    int root2 = find(uf, v2);
    if (root1 != root2) {
        if (uf->rank[root1] < uf->rank[root2]) {
            uf->pai[root1] = root2;
        } else if (uf->rank[root1] > uf->rank[root2]) {
            uf->pai[root2] = root1;
        } else {
            uf->pai[root2] = root1;
            uf->rank[root1]++;
        }
    }
}

void kruskal(Grafo *grafo) {
    int numArestas = 0;
    Aresta *arestas = malloc(grafo->numArestas * sizeof(Aresta));
    if (arestas == NULL) {
        fprintf(stderr, "Erro ao alocar memória para as arestas.\n");
        exit(1);
    }

    // Preencher o array de arestas
    for (ValorVertice v1 = 0; v1 < grafo->NumVertices; v1++) {
        Apontador adj = grafo->adj[v1].primeiro;
        while (adj != NULL) {
            if (v1 < adj->item.vertice) { // Para evitar duplicação
                arestas[numArestas].vertice1 = v1;
                arestas[numArestas].vertice2 = adj->item.vertice;
                arestas[numArestas].peso = adj->item.peso;
                numArestas++;
            }
            adj = adj->prox;
        }
    }

    // Ordenar arestas por peso
    qsort(arestas, numArestas, sizeof(Aresta), comparaArestas);

    // Inicializar o Union-Find
    UnionFind *uf = criaUnionFind(grafo->NumVertices);
    Lista resultado;
    listaVazia(&resultado); // Inicializa a lista para as arestas da MST

    // Processar as arestas
    for (int i = 0; i < numArestas; i++) {
        Aresta aresta = arestas[i];
        if (find(uf, aresta.vertice1) != find(uf, aresta.vertice2)) {
            Item item;
            item.vertice = aresta.vertice2; // Aresta vai de vertice1 a vertice2
            item.peso = aresta.peso;
            insereLista(item, &resultado); // Adiciona à MST
            unionSets(uf, aresta.vertice1, aresta.vertice2);
        }
    }

    // Imprimir as arestas da MST
    printf("Arestas da árvore geradora mínima:\n");
    Apontador aux = resultado.primeiro;
    while (aux != NULL) {
        printf("Vértice %d -> Vértice %d (Peso %d)\n", aux->item.vertice, aux->item.vertice, aux->item.peso);
        aux = aux->prox;
    }
}
