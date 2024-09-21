#include "stdio.h"
#include "stdlib.h"
#include "../tipos/grafo.h"
#include "../tipos/fila.h"
#include "dfs.h"
#include "stdbool.h"

// Função auxiliar que visita os vértices adjacentes de um vértice u
void visitaDfs(ValorVertice u, Grafo *grafo, ValorTempo* tempo, ValorTempo* d, ValorTempo* t, Cor* cor, short* antecessor) {
    short fimListaAdj = 0;
    Peso peso;
    Apontador aux;
    ValorVertice v;
    
    // Marca o vértice u como visitado (cinza) e atualiza o tempo de descoberta
    cor[u] = CINZA;
    (*tempo)++;
    d[u] = (*tempo);
    printf("Visitando vértice %2d - Tempo de descoberta: %2d [CINZA]\n", u, d[u]);

    // Obtém o primeiro adjacente do vértice u
    aux = primeiroListaAdj(&u, grafo);
    
    // Percorre os adjacentes de u
    while (aux != NULL) {
        proxAdj(&u, grafo, &v, &peso, &aux, &fimListaAdj);
        
        // Se o vértice adjacente v ainda não foi visitado (branco), visita v recursivamente
        if (cor[v] == BRANCO) {
            antecessor[v] = u;
            visitaDfs(v, grafo, tempo, d, t, cor, antecessor);
        }
    }
    
    // Após visitar todos os adjacentes, marca o vértice u como terminado (preto)
    cor[u] = PRETO;
    (*tempo)++;
    t[u] = (*tempo);
    printf("Vértice %2d - Tempo de término: %2d [PRETO]\n", u, t[u]);
}

// Função principal da busca em profundidade (DFS)
void dfs(Grafo *grafo) {
    ValorVertice v;
    ValorTempo tempo = 0;  // Contador de tempo
    ValorTempo d[MAXV+1], t[MAXV+1];  // Vetores de tempos de descoberta e término
    Cor cor[MAXV+1];  // Vetor de cores para marcar o estado de cada vértice
    short antecessor[MAXV+1];  // Vetor de antecessores para guardar a árvore de DFS

    // Inicializa todos os vértices como não visitados (brancos) e sem antecessores
    for (v = 0; v < grafo->NumVertices; v++) {
        cor[v] = BRANCO;
        antecessor[v] = -1;
    }

    // Para cada vértice do grafo, se ainda não foi visitado, inicia a DFS a partir dele
    for (v = 0; v < grafo->NumVertices; v++) {
        if (cor[v] == BRANCO) {
            printf("Iniciando DFS a partir do vértice %d\n", v);
            visitaDfs(v, grafo, &tempo, d, t, cor, antecessor);
        }
    }
}
