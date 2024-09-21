#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void filaVazia(TipoFila *fila){
    fila->frente = 1;
    fila->tras = fila->frente;
}

int vazia(TipoFila fila){
    return (fila.frente == fila.tras);
}

void enfileira(TipoItem x, TipoFila *fila){
    if(fila->tras % 1000000 + 1 == fila->frente){
        printf("Erro[001] : A fila está cheia!!!\n");
    }
    else{
        fila->Item[fila->tras-1] = x;
        fila->tras = fila->tras % (1000000 + 1);
    }
}

void desinfileira(TipoFila *fila, TipoItem *item){
    if(vazia(*fila)){
        printf("Erro[002]: A fila está vazia\n");
    }
    else{
        *item = fila->Item[fila->frente - 1];
        fila->frente = fila->frente % (1000000 + 1);
    }

}