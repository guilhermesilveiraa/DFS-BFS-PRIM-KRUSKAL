#include <stdio.h>
#include "fila.h"

// Função para inicializar a fila
void filaVazia(TipoFila *fila){
    fila->frente = 1;
    fila->tras = 1;
}

// Função para verificar se a fila está vazia
int vazia(TipoFila fila){
    return (fila.frente == fila.tras);
}

// Função para enfileirar um item
void enfileira(TipoItem x, TipoFila *fila){
    if ((fila->tras % MAXTAM) + 1 == fila->frente){
        printf("Erro[001] : A fila está cheia!!!\n");
    } else {
        fila->Item[fila->tras - 1] = x;
        printf("Enfileirando item na posição %d, valor: %d\n", fila->tras, x.chave); // Debug
        fila->tras = (fila->tras % MAXTAM) + 1;
    }
}

// Função para desenfileirar um item
void desinfileira(TipoFila *fila, TipoItem *item){
    if (vazia(*fila)){
        printf("Erro[002]: A fila está vazia\n");
    } else {
        *item = fila->Item[fila->frente - 1];
        printf("Desenfileirando item da posição %d, valor: %d\n", fila->frente, item->chave); // Debug
        fila->frente = (fila->frente % MAXTAM) + 1;
    }
}

// Função para imprimir a fila
void ImprimeFila(TipoFila fila) {
    if (vazia(fila)) {
        printf("Fila está vazia.\n");
        return;
    }

    int i = fila.frente;

    printf("Fila: [ ");
    while (i != fila.tras) {
        printf("%d ", fila.Item[i - 1].chave);
        i = (i % MAXTAM) + 1;
    }
    printf("]\n");
}
