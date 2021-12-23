#include <stdlib.h>

typedef enum boolean {false=0, true=1} Boolean;
typedef int TipoElemento;

typedef struct {
    TipoElemento* vetor;
    int tam;
    int inicio;
    int fim;
    int qtde;
} Fila;

Fila* fila_criar() {
    Fila* f = (Fila*) malloc(sizeof(TipoElemento));
    f->vetor = (TipoElemento*) calloc(5, sizeof(TipoElemento));
    f->tam = 5;
    f->inicio = 0;
    f->fim = 0;
    f->qtde = 0;

    return f;
}

void fila_destruir(Fila* f) {
    free(f);
}

Boolean fila_inserir(Fila* f, TipoElemento elemento) {
    if(f == NULL) return false;

    // printf("inicio\tfim\n%d\t%d\n",f->inicio, f->fim);

    if (f->fim == f->tam)
        f->fim = 0;

    // printf("fim: %d\n", f->fim);

    f->vetor[f->fim++] = elemento;
    f->qtde++;
    printf("[0]: %d\n\n", f->vetor[0]);

    if(f->inicio > f->fim) {
        for(int i=f->inicio; i>f->fim; i--)
            printf("[%d]: %d\t", i, f->vetor[i]);
        printf("qtde: %d\n", f->qtde);
        printf("\n\n");
    } else
        for(int i=f->inicio; i<f->fim; i++)
            printf("[%d]: %d\t", i, f->vetor[i]);
        printf("qtde: %d\n", f->qtde);
        
    return true;
}

Boolean fila_remover(Fila* f, TipoElemento* saida) {
    if (f == NULL) return false;
    
    *saida = f->vetor[f->inicio++];
    f->qtde--;

    // printf("qtde: %d\n", f->qtde); 
    return true;
}

Boolean fila_primeiro(Fila* f, TipoElemento* saida) {
    if (f == NULL) return false;

    *saida = f->vetor[f->inicio];

    return true;
}

Boolean fila_vazia(Fila* f) {
    if (f->qtde != 0) return false;
    else return true;
}

int fila_tamanho(Fila* f) {
    return f->qtde;
}

void fila_imprimir(Fila* f) {

    int i = f->inicio;
    printf("[");

    // while (i != f->fim) {
    for (i; i<f->fim; i++) {
        printf("%d", f->vetor[i]);
        // i++;

        if (i <= f->fim-2)
            printf(", ");    
        
    }
    printf("]\n");
}

Fila* fila_clone(Fila* f) {
    Fila* fAux = (Fila*) malloc(sizeof(TipoElemento));
    fAux = f;

    return fAux;
}

void fila_inverter(Fila* f) {
    for (int i=0; i<(f->qtde/2); i++) {
        TipoElemento aux = f->vetor[i];
        f->vetor[i] = f->vetor[f->qtde - i -1];
        f->vetor[f->qtde - i -1] = aux;
    }
}

Boolean fila_inserirTodos(Fila* f, TipoElemento* vetor, int tamVetor) {
    for (int i=0; i<tamVetor; i++) {
        f->vetor[i] = vetor[i];
        f->qtde++;
    }
}