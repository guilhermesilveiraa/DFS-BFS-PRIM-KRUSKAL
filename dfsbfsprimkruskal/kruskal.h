#include "../tipos/grafo.h"

//Estrutura Aresta para armazenar cada aresta com seus vértices e peso.
typedef struct {
    ValorVertice vertice1;
    ValorVertice vertice2;
    Peso peso;
} Aresta;

//Estrutura de UnionFind
typedef struct {
    int *pai;
    int *rank;
    int numVerticess;
} UnionFind;

void kruskal(Grafo *grafo);
void unionSets(UnionFind *uf, int v1, int v2);
UnionFind* criaUnionFind(int numVerticex);
int comparaArestas(const void *a, const void *b);
int find(UnionFind *uf, int v);