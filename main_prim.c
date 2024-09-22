#include "stdio.h"
#include "stdlib.h"
#include "tipos/grafo.h"
#include "dfsbfsprimkruskal/prim.h"
#include "stdbool.h"

Grafo* inicializaGrafo() {
    Grafo *grafo = malloc(sizeof(Grafo));
    grafo->NumVertices = 5; // Exemplo com 5 vértices
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

    v1 = 2; v2 = 3; int peso5 = 10;
    insereAresta(&v1, &v2,&peso5, grafo);

    v1 = 4; v2 = 0; int peso6 = 60;
    insereAresta(&v1, &v2,&peso6, grafo);


    return grafo;
}

int main() {
    Grafo *grafo = inicializaGrafo(); // Inicializa o grafo com 5 vértices e algumas arestas

    printf("Imprimindo Grafo G...\n");
    imprimeGrafo(grafo);
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");    
    prim(grafo,2); // Chama a função de Prim para gerar a árvore geradora mínima

    // Libera a memória alocada para o grafo
    // Supondo que exista uma função de desalocação no grafo.h
    liberaGrafo(grafo);

    return 0;
}