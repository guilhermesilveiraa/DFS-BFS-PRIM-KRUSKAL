#include "stdio.h"
#include "stdlib.h"
#include "grafo.h"

// Função para inicializar uma lista como vazia
void listaVazia(Lista *lista) {
    lista->primeiro = NULL;  // O primeiro elemento é NULL, indicando que a lista está vazia
    lista->ultimo = NULL;    // O último elemento também é NULL
}

// Função para inserir um novo item (vértice e peso) no final de uma lista de adjacência
void insereLista(Item item, Lista *lista) {
    // Aloca uma nova célula para armazenar o item
    Apontador novaCelula = (Apontador) malloc(sizeof(Celula));

    // Verifica se a alocação foi bem-sucedida
    if (novaCelula == NULL) {
        printf("Erro de alocação de memória\n");
        return;
    }

    // Preenche os dados da nova célula
    novaCelula->item = item;  // Armazena o item (vértice adjacente e peso)
    novaCelula->prox = NULL;  // Próxima célula é NULL, pois será a última

    // Verifica se a lista está vazia
    if (lista->primeiro == NULL) {
        // Se estiver vazia, o primeiro e o último apontam para a nova célula
        lista->primeiro = novaCelula;
        lista->ultimo = novaCelula;
    } else {
        // Se não estiver vazia, insere a nova célula no final
        lista->ultimo->prox = novaCelula;  // O último elemento aponta para a nova célula
        lista->ultimo = novaCelula;        // Atualiza o ponteiro "ultimo"
    }
}

// Função para remover um item de uma lista de adjacência
void retiraLista(Apontador p, Lista *lista, Item *item) {
    Apontador q;

    // Verifica se há algo para remover (se p ou p->prox for NULL, não há remoção possível)
    if (p == NULL || p->prox == NULL) {
        printf("Erro: posição inválida para remoção\n");
        return;
    }

    // Aponta para a célula que será removida
    q = p->prox;

    // Atualiza o ponteiro para "pular" a célula q
    p->prox = q->prox;

    // Se a célula removida for a última, atualiza o ponteiro "ultimo"
    if (q == lista->ultimo) {
        lista->ultimo = p;
    }

    // Armazena o item removido (se for necessário)
    *item = q->item;

    // Libera a memória da célula removida
    free(q);
}

// Função para inicializar o grafo, deixando todas as listas de adjacência vazias
void grafoVazio(Grafo *grafo) {
    long i;
    // Para cada vértice, inicializa a lista de adjacência correspondente
    for (i = 0; i < grafo->NumVertices; i++) {
        listaVazia(&grafo->adj[i]);
    }
}

// Função para inserir uma aresta no grafo (vértice v1 para v2 com peso p)
void insereAresta(ValorVertice *v1, ValorVertice *v2, Peso *p, Grafo *grafo) {
    Item x;
    x.vertice = *v2;  // Vértice de destino da aresta
    x.peso = *p;      // Peso da aresta
    insereLista(x, &grafo->adj[*v1]);  // Insere na lista de adjacência do vértice v1
}

// Função para verificar se existe uma aresta entre v1 e v2 no grafo
short existeAresta(ValorVertice v1, ValorVertice v2, Grafo *grafo) {
    Apontador aux;
    short encontrouAresta = 0;  // Inicialmente, assume que a aresta não existe
    aux = grafo->adj[v1].primeiro;  // Começa a busca no primeiro elemento da lista de v1
    while (aux != NULL && encontrouAresta == 0) {
        if (v2 == aux->item.vertice) {  // Se encontrar o vértice v2, a aresta existe
            encontrouAresta = 1;
        }
        aux = aux->prox;  // Avança para a próxima célula da lista
    }
    return encontrouAresta;
}

// Função para verificar se a lista de adjacência de um vértice está vazia
short listaAdjVazia(ValorVertice *vertice, Grafo *grafo) {
    // Retorna verdadeiro se o primeiro e o último elemento forem o mesmo, ou seja, a lista está vazia
    return (grafo->adj[*vertice].primeiro == NULL);
}

// Função para obter o primeiro elemento da lista de adjacência de um vértice
Apontador primeiroListaAdj(ValorVertice *vertice, Grafo *grafo) {
    // Retorna o ponteiro para o primeiro elemento da lista
    return (grafo->adj[*vertice].primeiro);
}

// Função para obter o próximo adjacente na lista de um vértice
void proxAdj(ValorVertice *vertice, Grafo *grafo, ValorVertice *adj, Peso *peso, Apontador *prox, short *fimListaAdj) {
    if (*prox != NULL) {
        *adj = (*prox)->item.vertice;  // Atualiza o vértice adjacente
        *peso = (*prox)->item.peso;    // Atualiza o peso da aresta
        *prox = (*prox)->prox;          // Avança para o próximo elemento da lista
        if (*prox == NULL) {
            *fimListaAdj = 1;          // Se não houver próximo, define o fim da lista
        }
    } else {
        *fimListaAdj = 1;              // Se o prox já é NULL, define o fim da lista
    }
}

// Função para remover uma aresta do grafo entre v1 e v2
void RetiraAresta(ValorVertice *v1, ValorVertice *v2, Peso *peso, Grafo *grafo) {
    Apontador auxAnterior, aux;
    short encontrouAresta = 0;  // Inicialmente, assume que a aresta não foi encontrada
    Item x;
    auxAnterior = grafo->adj[*v1].primeiro;  // Começa pelo primeiro elemento da lista de v1
    aux = grafo->adj[*v1].primeiro->prox;    // Avança para o próximo elemento

    // Percorre a lista de adjacência para encontrar a aresta
    while (aux != NULL && encontrouAresta == 0) {
        if (*v2 == aux->item.vertice) {  // Se encontrar a aresta
            retiraLista(auxAnterior, &grafo->adj[*v1], &x);  // Remove a aresta
            grafo->numArestas--;  // Decrementa o número de arestas no grafo
            encontrouAresta = 1;  // Marca que a aresta foi encontrada
        }
        auxAnterior = aux;
        aux = aux->prox;
    }
}

// Função para liberar a memória alocada para o grafo
void liberaGrafo(Grafo *grafo) {
    Apontador auxAnterior, aux;
    long i;
    for (i = 0; i < grafo->NumVertices; i++) {  // Para cada lista de adjacência
        aux = grafo->adj[i].primeiro;  // Começa pelo primeiro
        while (aux != NULL) {
            auxAnterior = aux;
            aux = aux->prox;
            free(auxAnterior);  // Libera a célula atual
        }
    }
    grafo->NumVertices = 0;  // Reseta o número de vértices do grafo
}

// Função para imprimir o grafo, mostrando os vértices adjacentes e seus pesos
void imprimeGrafo(Grafo *grafo) {
    Apontador aux;
    for (int i = 0; i < grafo->NumVertices; i++) {  // Para cada vértice no grafo
        printf("Vértice %d: ", i);  // Imprime o vértice atual
        aux = grafo->adj[i].primeiro;  // Começa pelo primeiro vértice adjacente
        while (aux != NULL) {  // Percorre todos os adjacentes
            printf(" -> Vértice %d (Peso %d)", aux->item.vertice, aux->item.peso);  // Imprime o vértice adjacente e o peso da aresta
            aux = aux->prox;  // Avança para o próximo adjacente
        }
        printf("\n");  // Pula para a próxima linha para o próximo vértice
    }
}
