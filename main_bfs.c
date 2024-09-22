#include "dfsbfsprimkruskal/bfs.h"
#include "stdio.h"
#include "stdlib.h"
#include "tipos/grafo.h"
#include "tipos/fila.h"
#include "stdbool.h"




Grafo* inicializaGrafo() {
    Grafo *grafo = malloc(sizeof(Grafo));
    grafo->NumVertices = 7; // Exemplo com 7 vértices
    grafo->numArestas = 0;

    // Inicializa a lista de adjacências ou matriz de adjacência aqui
    // Supondo que exista uma função de inicialização em "grafo.h"

    // Exemplo: Adiciona algumas arestas no grafo
    int v1 = 0, v2 = 1, peso1 = 10;
    insereAresta(&v1, &v2, &peso1, grafo);

    v1 = 0; v2 = 2; int peso2 = 20;
    insereAresta(&v1, &v2, &peso2, grafo);

    v1 = 1; v2 = 3; int peso3 = 40;
    insereAresta(&v1, &v2, &peso3, grafo);

    v1 = 2; v2 = 4; int peso4 = 50;
    insereAresta(&v1, &v2, &peso4, grafo);

    v1 = 5; v2 = 6; int peso5 = 60;
    insereAresta(&v1, &v2, &peso5, grafo);

    v1 = 3; v2 = 5; int peso6 = 70;
    insereAresta(&v1, &v2, &peso6, grafo);

    return grafo;
}

int main() {
    Grafo *grafo = inicializaGrafo(); // Inicializa o grafo com 5 vértices e algumas arestas

    printf("Imprimindo Grafo G...\n");
    imprimeGrafo(grafo);
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
    printf("Executando BFS...\n");
    bfs(grafo); // Chama a função de DFS para realizar a busca em profundidade

    // Libera a memória alocada para o grafo
    // Supondo que exista uma função de desalocação no grafo.h
    liberaGrafo(grafo);

    return 0;
}

