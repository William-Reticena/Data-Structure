#include <stdlib.h>

typedef int TipoElemento; 
typedef enum boolean {false=0, true=1} Boolean;

typedef struct NO {
    TipoElemento dado;
    struct NO* prox;
}No;

typedef struct {
    No* topo;
    int qtdeElementos;
} Pilha;

Pilha* pilha_criar() {
    Pilha *p = (Pilha*) malloc(sizeof(TipoElemento));
    p->topo = NULL;  
    p->qtdeElementos = 0;      
                                        
    return p;
}

Boolean pilha_empilhar(Pilha* p, TipoElemento elemento) {
    if (p == NULL)
        return false;

    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    no->prox = p->topo;
    p->topo = no;
    p->qtdeElementos++; 
    
    return true;
}

void pilha_destruir(Pilha* p) {
    free(p);
}

Boolean pilha_desempilhar(Pilha* p, TipoElemento* saida) {
    if (p == NULL)
        return false;

    No* aux = (No*) malloc(sizeof(No));
    aux = p->topo;
    *saida = aux->dado;
    p->topo = aux->prox;
    p->qtdeElementos--;
 
    return true;
}

Boolean pilha_topo(Pilha* p, TipoElemento* saida){
    if (p == NULL)
        return false;

    *saida = p->topo->dado;
    return true;
}

void pilha_imprimir(Pilha* p) {
    No* aux = p->topo;
    while (aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
}

int pilha_tamanho(Pilha* p) {
    return p->qtdeElementos; 
}

Pilha* pilha_clone(Pilha* p) {
    Pilha* aux = (Pilha*) malloc(sizeof(TipoElemento));
    aux = p;

    return aux;
}

Boolean pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor) {
    if (p == NULL)
        return false;

    for (int i=0; i<tamVetor; i++) 
        pilha_empilhar(p, vetor[i]);

    return true;
}

void pilha_inverter(Pilha* p) {
    TipoElemento nada, posicoes = p->qtdeElementos;
    No* aux = p->topo;
    TipoElemento vet[p->qtdeElementos];
    int i = 0;
    
    while (aux != NULL) {
        vet[i] = aux->dado;
        aux = aux->prox;
        i++;
    }
    
    for (i=0; i<posicoes; i++) 
        pilha_desempilhar(p, &nada);

    pilha_empilharTodos(p, vet, posicoes);   
}