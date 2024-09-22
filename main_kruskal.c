#include "stdio.h"
#include "stdlib.h"
#include "tipos/grafo.h"
#include "dfsbfsprimkruskal/kruskal.h"
#include "stdbool.h"

int main() {
    // Criação do grafo
    Grafo grafo;
    grafo.NumVertices = 5;  // Definindo um grafo com 5 vértices
    grafoVazio(&grafo);     // Inicializa as listas de adjacência

    // Adicionando arestas (v1, v2, peso)
    ValorVertice v1, v2;
    Peso peso;

    v1 = 0; v2 = 1; peso = 10; insereAresta(&v1, &v2, &peso, &grafo);
    v1 = 0; v2 = 2; peso = 6; insereAresta(&v1, &v2, &peso, &grafo);
    v1 = 1; v2 = 2; peso = 5; insereAresta(&v1, &v2, &peso, &grafo);
    v1 = 1; v2 = 3; peso = 15; insereAresta(&v1, &v2, &peso, &grafo);
    v1 = 2; v2 = 3; peso = 4; insereAresta(&v1, &v2, &peso, &grafo);
    v1 = 3; v2 = 4; peso = 8; insereAresta(&v1, &v2, &peso, &grafo);
    v1 = 2; v2 = 4; peso = 2; insereAresta(&v1, &v2, &peso, &grafo);

    // Imprimindo o grafo
    printf("Grafo:\n");
    imprimeGrafo(&grafo);

    // Executando o algoritmo de Kruskal
    kruskal(&grafo);

    // Liberar memória do grafo
    liberaGrafo(&grafo);

    return 0;
}
