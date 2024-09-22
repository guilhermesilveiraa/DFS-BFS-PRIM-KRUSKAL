#include "stdio.h"
#include "stdlib.h"
#include "prim.h"
#include "limits.h"

// Função auxiliar para encontrar o vértice com a menor chave
// que ainda não está incluído na árvore
int extraiMin(int chave[], short naArvore[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (naArvore[v] == 0 && chave[v] < min) {
            min = chave[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void imprimeAGM(int pai[], int chave[], int numVertices) {
    printf("Vértice %d:", 0);  // Começa pelo vértice inicial
    for (int i = 1; i < numVertices; i++) {
        // Imprime o pai do vértice i, seguido do vértice i e o peso
        printf(" -> Vértice %d (Peso %d)", i, chave[i]);
        
        // Se ainda há mais arestas a serem impressas, pula para a linha seguinte e imprime o próximo vértice
        if (i + 1 < numVertices) {
            printf("\nVértice %d:", i);
        }
    }
    printf("\n");  // Finaliza a impressão
}

void prim(Grafo *grafo, int verticeInicial) {
    int numVertices = grafo->NumVertices;
    
    int chave[numVertices];
    short naArvore[numVertices];
    int pai[numVertices];
    
    for (int i = 0; i < numVertices; i++) {
        chave[i] = INT_MAX;
        naArvore[i] = 0;
        pai[i] = -1;
    }
    
    chave[verticeInicial] = 0;
    
    for (int i = 0; i < numVertices - 1; i++) {
        int u = extraiMin(chave, naArvore, numVertices);
        naArvore[u] = 1;
        
        Apontador adjacente = primeiroListaAdj(&u, grafo);
        short fimLista = 0;
        while (!fimLista) {
            int v;
            Peso peso;
            proxAdj(&u, grafo, &v, &peso, &adjacente, &fimLista);
            
            if (naArvore[v] == 0 && peso < chave[v]) {
                chave[v] = peso;
                pai[v] = u;
            }
        }
    }
    
    // Chama a função modificada para imprimir a MST formatada
    printf("Executando Prim...\n");
    printf("Iniciando do vértice %d...\n", verticeInicial);
    printf("Arestas da árvore geradora mínima:\n");
    imprimeAGM(pai, chave, numVertices);
}
