#include "../tipos/grafo.h"

typedef unsigned int ValorTempo;

typedef enum {
    BRANCO,
    CINZA,
    PRETO
} Cor;

void visitaDfs(ValorVertice u, Grafo *grafo, ValorTempo* tempo, ValorTempo* d, ValorTempo* t, Cor* cor, short* antecessor);
void dfs(Grafo *grafo);
