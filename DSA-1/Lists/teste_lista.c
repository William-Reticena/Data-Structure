#include <stdio.h>
#include "lista_sentinela.h"

int main() {
    Lista* lista1 = lista_criar();
    int tam, r;
    char str;
    // lista_destruir(l1);

    //-----------------------------------//
    lista_inserirFim(lista1, 1);
    lista_inserirFim(lista1, 2);
    lista_inserirFim(lista1, 3);
    // lista_inserirFim(lista1, 4);
    // lista_inserirFim(lista1, 5);
    //-----------------------------------//
    lista_imprimir(lista1);
    // tam = lista_tamanho(lista1);
    // printf("Tamanho: %d\n", tam);
    //-----------------------------------//
    // lista_inserir(lista1, 2, 0);
    //-----------------------------------//
    // lista_inserir(lista1, 10, 12);
    // lista_imprimir(lista1);

    tam = lista_tamanho(lista1);
    printf("Tamanho: %d\n", tam);
    //-----------------------------------//
    // lista_removerPosicao(lista1, 5, &r);
    // printf("%s elemento %d foi removido\n", (r == 0) ? "Nenhum" : "O", r);
    // lista_imprimir(lista1);
    //-----------------------------------//
    // r = lista_removerElemento(lista1, 4);
    // printf("Posicao: %d\n", r);
    lista_imprimir(lista1);
    //-----------------------------------//
    // lista_substituir(lista1, 4, 20);
    // lista_imprimir(lista1);
    //-----------------------------------//
    // r = lista_posicao(lista1, 8);
    // printf("O elemento se encontra na posicao: %d", r);
    //-----------------------------------//
    // lista_buscar(lista1, 3, &r);
    // printf("O elemento da posicao referida e: %d", r);
    //-----------------------------------//
    printf("%s\n", (lista_contem(lista1, 4)) ? "sim" : "nao");
    //-----------------------------------//
    lista_toString(lista1, &str);
    printf("%s\n", str);

    return 0;
}