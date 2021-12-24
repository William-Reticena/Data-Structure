#ifndef __AB_H__
#define __AB_H__

typedef struct AB{
    struct AB *esq;
    struct AB *dir;
    int dado;
} AB;

int* randomVector(int n, int max, int seed);
void printVector(int* v, int n);
AB* AB_Criar(int dado, AB* e, AB* d);
void AB_Destruir(AB* A);
void AB_Inserir(AB** A, int dado);
void AB_Imprimir(AB* A);
void AB_EmOrdem(AB *A, int *v, int *index);
AB* AB_Buscar(AB* A, int dado);
void AB_Remover(AB** A, int dado);
void AB_Sort(int *v, int n);

#endif