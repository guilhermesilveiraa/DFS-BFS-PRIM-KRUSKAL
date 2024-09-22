#define MAXTAM 1000

typedef int Tap;
typedef int Tch;

typedef struct
{
    Tch chave;
}TipoItem;

typedef struct
{
    TipoItem Item[MAXTAM];
    Tap frente, tras;
}TipoFila;

void filaVazia(TipoFila *fila);
int vazia(TipoFila fila);
void enfileira(TipoItem x, TipoFila *fila);
void desinfileira(TipoFila *fila, TipoItem *item);
void ImprimeFila(TipoFila fila);

