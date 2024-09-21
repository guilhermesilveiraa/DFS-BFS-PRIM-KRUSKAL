#ifndef GRAFO_H  // Verifica se o cabeçalho já foi incluído
#define GRAFO_H  // Define a macro para evitar inclusões múltiplas

// Definições do número máximo de vértices e arestas no grafo
#define MAXV 1000
#define MAXA 4500

// Tipos de dados para representar um vértice e o peso de uma aresta
typedef int ValorVertice;
typedef int Peso;

// Estrutura que representa um item (vértice adjacente e peso)
typedef struct Item {
    ValorVertice vertice;  // Vértice adjacente
    Peso peso;             // Peso da aresta
} Item;

// Estrutura que representa uma célula de uma lista encadeada
typedef struct Celula *Apontador;

typedef struct Celula {
    Item item;             // Item armazenado na célula
    Apontador prox;        // Ponteiro para a próxima célula
} Celula;

// Estrutura que representa uma lista encadeada (lista de adjacência)
typedef struct Lista {
    Apontador primeiro, ultimo;  // Ponteiros para o primeiro e último elemento da lista
} Lista;

// Estrutura que representa um grafo com listas de adjacência
typedef struct Grafo {
    Lista adj[MAXV+1];      // Lista de adjacência para cada vértice
    ValorVertice NumVertices;  // Número de vértices no grafo
    short numArestas;         // Número de arestas no grafo
} Grafo;

// Declaração de funções públicas que serão utilizadas pelos programas que incluírem essa biblioteca

void listaVazia(Lista *lista);
void insereLista(Item item, Lista *lista);
void retiraLista(Apontador p, Lista *lista, Item *item);
void grafoVazio(Grafo *grafo);
void insereAresta(ValorVertice *v1, ValorVertice *v2, Peso *p, Grafo *grafo);
short existeAresta(ValorVertice v1, ValorVertice v2, Grafo *grafo);
short listaAdjVazia(ValorVertice *vertice, Grafo *grafo);
Apontador primeiroListaAdj(ValorVertice *vertice, Grafo *grafo);
void proxAdj(ValorVertice *vertice, Grafo *grafo, ValorVertice *adj, Peso *peso, Apontador *prox, short *fimListaAdj);
void RetiraAresta(ValorVertice *v1, ValorVertice *v2, Peso *peso, Grafo *grafo);
void liberaGrafo(Grafo *grafo);
void imprimeGrafo(Grafo *grafo);

#endif  
