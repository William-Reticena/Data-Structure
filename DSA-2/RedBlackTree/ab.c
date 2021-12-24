#include "ab.h"
#include <stdlib.h>
#include <stdio.h>

int* randomVector(int n, int max, int seed) {
    int* v = (int*) malloc(sizeof(int) * n);
    srand(seed);

    for (int i=0; i<n; i++)
        v[i] = rand() % (max+1);
    
    return v;
}

void printVector(int* v, int n) {
    int i;

    for (i=0; i<n-1; i++)
        printf("%d, ", v[i]);
    
    printf("%d\n", v[i]);
}

AB* maior(AB** A) {
    if ((*A)->dir != NULL) return maior(&(*A)->dir);

    AB* aux = *A;
    if ((*A)->esq != NULL) *A = (*A)->esq;

    else *A = NULL;

    return aux;
}

AB* AB_Criar(int dado, AB* e, AB* d){
    AB* n;
    
    n = malloc(sizeof(AB));
    n->dado = dado;
    n->esq = e;
    n->dir = d;

    return n;
}

void AB_Destruir(AB* A){
    if(A == NULL)
        return;
    AB_Destruir(A->esq);
    AB_Destruir(A->dir);
    free(A);
}

void AB_Inserir(AB** A, int dado) {
    if ((*A) == NULL) {
        *A = AB_Criar(dado, NULL, NULL);
        return;

    } else {
        if (dado < (*A)->dado) AB_Inserir(&(*A)->esq, dado);
        
        else AB_Inserir(&(*A)->dir, dado);
    }
}

void AB_EmOrdem(AB *A, int *v, int *index) {
    if (A == NULL) return;
    // int x = index;

    AB_EmOrdem(A->esq, v, index);
    v[*index] = A->dado;
    *index += 1;
    AB_EmOrdem(A->dir, v, index);
}

void AB_Imprimir(AB* A) {
    if (A == NULL) return;


    AB_Imprimir(A->esq);
    printf("%d\n", A->dado);
    AB_Imprimir(A->dir);
}

AB* AB_Buscar(AB* A, int dado) {
    if (A == NULL) return NULL;

    if (A->dado == dado) return A;

    if (dado < A->dado) return AB_Buscar(A->esq, dado);

    return AB_Buscar(A->dir, dado);
}

void AB_Remover(AB** A, int dado) {
    if (*A == NULL) return;

    if ((*A)->dado > dado) {
        AB_Remover(&(*A)->esq, dado);

    } else {
        if ((*A)->dado < dado)
            AB_Remover(&(*A)->dir, dado);

        else {
            AB* aux = *A;

            if (((*A)->esq == NULL) && ((*A)->dir == NULL)) {
                AB_Destruir(*A);
                *A = NULL;

            } else {
                if ((*A)->esq == NULL) {
                    *A = (*A)->dir;
                    aux->dir = NULL;
                    AB_Destruir(aux);
                    aux = NULL;

                } else {
                    if ((*A)->dir == NULL) {
                        *A = (*A)->esq;
                        aux->esq = NULL;
                        AB_Destruir(aux);
                        aux = NULL;

                    } else {
                        aux = maior(&(*A)->esq);
                        aux->esq = (*A)->esq;
                        aux->dir = (*A)->dir;
                        (*A)->dir = NULL;
                        (*A)->esq = NULL;
                        AB_Destruir(*A);
                        *A = aux;
                        aux = NULL;
                    }
                }
            }
        }
    }   
}

void AB_Sort(int *v, int n) {
    int index = 0;
    v = randomVector(n, 10*n, 5);

    //CRIA UMA ABB A
    AB *A = AB_Criar(v[0], NULL, NULL);

    // printVector(v, n);

    //INSERE O VETOR NA ABB
    for (int i=1; i<n; i++)
        AB_Inserir(&A, v[i]);

    // printf("\n");
    // AB_Imprimir(A);

    //INSERE A EM V
    AB_EmOrdem(A, v, &index);
    // printf("%d", AB_EmOrdem(A));
    // printVector(v, n);

    //DESTROI A
    AB_Destruir(A);
}