#include <stdio.h>
#include <stdlib.h>
#include "arn.h"
#include "ab.h"

ARN* ARN_Criar(int chave, int valor){
    ARN* novo;

    novo = malloc(sizeof(struct ARN));

    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

static void rot_esq(ARN** A){
    ARN* h;
    ARN* x;
    h = *A;
    x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static void rot_dir(ARN** A){
    ARN* h;
    ARN* x;
    h = *A;
    x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static inline int eh_vermelho(ARN* A){
    if(A == NULL)
        return 0;

    return A->cor == C_VERMELHO ? 1 : 0;
}

static void inverter_cores(ARN* h){
    h->cor = C_VERMELHO;
    h->esq->cor = C_PRETO;
    h->dir->cor = C_PRETO;
}

void ARN_Imprimir(ARN* A, int nivel, char lado){
    int i;
    for(i = 0; i < nivel; i++){
        printf("--> ");
    }
    if(A == NULL){
        printf("(%c) NONE\n", lado);
    }
    else{
        printf("(%c) %d [%s]\n", lado, A->valor, A->cor == C_VERMELHO ? "V" : "P");
        ARN_Imprimir(A->esq, nivel+1, 'e');
        ARN_Imprimir(A->dir, nivel+1, 'd');
    }
}

void ARN_Inserir_R(ARN** A, int chave, int valor) {
    if ((*A) == NULL) {
        *A = ARN_Criar(chave, valor);
        return;
    }

    if (chave < (*A)->chave) {
        ARN_Inserir_R(&(*A)->esq, chave, valor);
    }

    if (chave > (*A)->chave) {
        ARN_Inserir_R(&(*A)->dir, chave, valor);
    }

    if (eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq)) {
        rot_esq(A);
    }

    if (eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq)) {
        rot_dir(A);
    }

    if (eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir)) {
        inverter_cores(*A);
    }
}

void ARN_Inserir(ARN** A, int chave, int valor) {
    ARN_Inserir_R(A, chave, valor);
    (*A)->cor = C_PRETO;
}

void ARN_EmOrdem(ARN *A, int *v, int *index) {
    if (A == NULL) return;

    ARN_EmOrdem(A->esq, v, index);
    v[*index] = A->valor;
    *index += 1;
    ARN_EmOrdem(A->dir, v, index);
}

void ARN_Destruir(ARN* A){
    if(A == NULL)
        return;
    ARN_Destruir(A->esq);
    ARN_Destruir(A->dir);
    free(A);
}

void ARN_Sort(int *v, int n) {
    int index = 0;

    //CRIA UMA ARN A
    ARN *A = ARN_Criar(0, v[0]);

    // printVector(v, n);

    // INSERE O VETOR NA ARN
    for (int i=1; i<n; i++)
        ARN_Inserir(&A, i, v[i]);

    // printf("\n");
    ARN_Imprimir(A, 0, 'r');

    //INSERE A EM V
    ARN_EmOrdem(A, v, &index);
    // printVector(v, n);

    //DESTROI A
    // ARN_Destruir(A);
}