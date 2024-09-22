#include "../tipos/grafo.h"


typedef enum {
    BRANCO,
    CINZA,
    PRETO
} Cor;

void visitaBfs(ValorVertice u, Grafo *grafo, int *dist, Cor *cor, int *antecessor);
void bfs(Grafo *grafo);