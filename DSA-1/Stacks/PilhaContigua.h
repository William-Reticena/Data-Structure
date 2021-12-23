#include <stdlib.h>

typedef int TipoElemento; 
typedef enum boolean {false=0, true=1} Boolean;


typedef struct {
    TipoElemento* vetor;
    int tamVetor;
    int qtde;
} Pilha;

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(TipoElemento));
    p->vetor = (TipoElemento*) calloc(4, sizeof(TipoElemento));
    p->tamVetor = 4;  
    p->qtde = 0;      
                                        
    return p;
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento) {
    if (p == NULL)
        return false;

    p->vetor[p->qtde++] = elemento;
    
    return true;
}

void pilha_destruir(Pilha* p) {
    free(p);
}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida) {
    if (p == NULL)
        return false;
        
    p->vetor[p->qtde] = 0;
    *saida = p->vetor[--p->qtde];
    return true;
}

Boolean pilha_topo(Pilha* p, TipoElemento* saida){
    if (p == NULL)
        return false;

    *saida = p->vetor[p->qtde];
    return true;
}

void pilha_imprimir(Pilha* p) {
     
    for (int i=0; i<p->qtde; i++)
        printf("[%d]: %d\n", i, p->vetor[i]);
}

int pilha_tamanho(Pilha* p) {
    return p->qtde; 
}

Pilha* pilha_clone(Pilha* p) {
    Pilha* aux = (Pilha*) malloc(sizeof(TipoElemento));
    aux->vetor = p->vetor;
    aux->tamVetor = p->tamVetor;  
    aux->qtde = p->qtde;   

    return aux;
}

void pilha_inverter(Pilha* p) {
    for (int i=0; i<(p->qtde/2); i++) {
        TipoElemento aux = p->vetor[i];
        p->vetor[i] = p->vetor[p->qtde - i -1];
        p->vetor[p->qtde - i -1] = aux;
    }
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor) {
    for (int i=0; i<tamVetor; i++) {
        p->vetor[i] = vetor[i];
        p->qtde++;
    }
}