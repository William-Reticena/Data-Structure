#include "ab.h"
#include <stdlib.h>
#include <stdio.h>

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

void AB_Imprimir(AB* A) {
    if (A == NULL) return;

    printf("%d\n", A->dado);

    AB_Imprimir(A->esq);
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