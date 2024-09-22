#include "../tipos/grafo.h"
#include "bfs.h"
#include "stdio.h"
#include "stdlib.h"
#include "../tipos/fila.h"

void VisitaBfs(ValorVertice u, Grafo *grafo, int *dist, Cor *cor, int *antecessor) {
    ValorVertice v;
    Apontador aux;
    short fimListaAdj;
    Peso peso;
    TipoItem item; 
    TipoFila fila;

    // Inicializa a fila e marca o vértice inicial como cinza (visitado)
    filaVazia(&fila);
    cor[u] = CINZA;
    dist[u] = 0;

    // Enfileira o vértice inicial
    item.chave = u;
    enfileira(item, &fila);

    printf("Visita origem %2d cor: cinza\n\n", u);
    ImprimeFila(fila);
    getchar();

    // Loop enquanto a fila não estiver vazia
    while (!vazia(fila)) {
        desinfileira(&fila, &item); // Desenfileira o próximo vértice
        u = item.chave;

        if (!listaAdjVazia(&u, grafo)) {
            aux = primeiroListaAdj(&u, grafo);
            fimListaAdj = 0;

            // Percorre todos os adjacentes do vértice u
            while (fimListaAdj == 0) {
                proxAdj(&u, grafo, &v, &peso, &aux, &fimListaAdj);

                // Se o vértice adjacente ainda não foi visitado (cor BRANCO)
                if (cor[v] == BRANCO) {
                    cor[v] = CINZA;
                    dist[v] = dist[u] + 1;
                    antecessor[v] = u;

                    // Enfileira o vértice adjacente
                    item.chave = v;
                    enfileira(item, &fila);

                    printf("Enfileirando vértice %2d (dist %d)\n", v, dist[v]);
                    ImprimeFila(fila); // Debug: imprime o estado da fila
                }
            }
        }

        // Marca o vértice u como completamente processado (cor PRETO)
        cor[u] = PRETO;
        printf("Visita %2d Dist %2d cor: preto\n\n", u, dist[u]);
        ImprimeFila(fila);
        //getchar();
    }
}


// Função principal para executar a busca em largura (BFS) em todo o grafo
void bfs(Grafo *grafo) {
    ValorVertice x;
    int dist[1000 + 1];
    Cor cor[1000 + 1];
    int antecessor[1000 + 1]; 

    // Inicializa os vetores de distância, cor e antecessor
    for (x = 0; x <= grafo->NumVertices - 1; x++) {
        cor[x] = BRANCO; 
        dist[x] = 1000;
        antecessor[x] = -1;
    }

    // Executa BFS a partir de cada vértice que ainda não foi visitado
    for (x = 0; x <= grafo->NumVertices - 1; x++) {
        if (cor[x] == BRANCO) {
            VisitaBfs(x, grafo, dist, cor, antecessor);
        }
    }
}
