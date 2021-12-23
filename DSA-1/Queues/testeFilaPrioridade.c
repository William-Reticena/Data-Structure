#include <stdio.h>
#include "filaPrioridadeHeap.h"

int main() {
    FilaPrioridade* f1 = filaP_criar();
    FilaPrioridade* f2;
    int r, tamanho;
    int v[6] = {2, 4, 8, 3, 5, 9};
    
    //---------------------------------------------//
    // filaP_destruir(f1);

    //---------------------------------------------//
    filaP_inserir(f1, 8);
    // // filaP_imprimir(f1);
    filaP_inserir(f1, 10);
    // // filaP_imprimir(f1);
    filaP_inserir(f1, 11);
    // // filaP_imprimir(f1);
    filaP_inserir(f1, 5);
    // // filaP_imprimir(f1);
    filaP_inserir(f1, 13);
    // // filaP_imprimir(f1);
    filaP_inserir(f1, 4);
    filaP_imprimir(f1);

    //---------------------------------------------//
    // filaP_remover(f1, &r);
    filaP_remover(f1, &r);
    // filaP_remover(f1, &r);
    // filaP_remover(f1, &r);
    // filaP_remover(f1, &r);
    // filaP_remover(f1, &r);
    // filaP_remover(f1, &r);
    // printf("Elemento %d removido\n", r);
    filaP_imprimir(f1);

    //---------------------------------------------//

    //---------------------------------------------//
    // int t = filaP_vazia(f1);
    // printf("t %d\n", t);

    //---------------------------------------------//
    // f2 = filaP_clone(f1);
    // filaP_imprimir(f2);
    // filaP_imprimir(f2);

    tamanho = filaP_tamanho(f1);
    printf("O tamanho \x82: %d\n", tamanho);
    // filaP_imprimir(f1);

    //---------------------------------------------//
    // filaP_inserirTodos(f1, v, 6);
}