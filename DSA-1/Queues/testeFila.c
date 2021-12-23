#include <stdio.h>
// #include "FilaCircular.h"
#include "FilaEncadeada.h"

int main() {
    Fila* f1 = fila_criar();
    int remover, first, v[5] = {6, 33, 4, 8, 32};
    Fila* f2;

    //-----------------------------------------------//
    // fila_destruir(f1);

    //-----------------------------------------------//
    fila_inserir(f1, 1);
    fila_imprimir(f1);
    // fila_inserir(f1, 2);
    // fila_imprimir(f1);
    // fila_inserir(f1, 3);
    // fila_imprimir(f1);
    // fila_inserir(f1, 4);
    // fila_imprimir(f1);

    //-----------------------------------------------//
    // printf("Removendo\n");
    // fila_remover(f1, &remover);
    // printf("Valor removido: %d\n", remover);
    // fila_imprimir(f1);

    //-----------------------------------------------//
    // fila_inserir(f1, 5);
    // fila_inserir(f1, 6);
    // fila_imprimir(f1);

    //-----------------------------------------------//
    // printf("Removendo\n");
    // fila_remover(f1, &remover);
    // printf("Valor removido: %d\n", remover);
    // fila_imprimir(f1);

    //-----------------------------------------------//
    // fila_inserir(f1, 10);
    // fila_imprimir(f1);

    //-----------------------------------------------//
    // fila_primeiro(f1, &first);
    // printf("Primeiro valor da fila \x82: %d\n", first); 

    //-----------------------------------------------//
    // fila_vazia(f1);

    //-----------------------------------------------//
    // int qtde = fila_tamanho(f1);
    // printf("O tamanho da fila \x82: %d\n", qtde);

    //-----------------------------------------------//
    // f2 = fila_clone(f1);
    // fila_imprimir(f2);

    //-----------------------------------------------//
    // fila_inverter(f1);
    // fila_imprimir(f1);

    //-----------------------------------------------//
    // fila_inserirTodos(f1, v, 5);
    // fila_imprimir(f1);
    // return 0;
}