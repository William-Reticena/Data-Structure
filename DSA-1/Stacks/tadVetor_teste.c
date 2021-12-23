#include <stdio.h>
#include "PilhaContigua.h"

int main() {
    Pilha* p1 = pilha_criar();
    Pilha* p2;
    int vetor[4] = {5, 12, 14, 28};

    
    // pilha_empilhar(p1, 10);
    // pilha_empilhar(p1, 20);
    // pilha_empilhar(p1, 30);
    // pilha_empilhar(p1, 40);

    // pilha_destruir(p1);

    int elemento;
    // pilha_desempilhar(p1, &elemento);

    // printf("O elemento removido da posicao [%d]: %d\n", p1->qtde, elemento);
    // pilha_empilhar(p1, 88);
    
    // pilha_topo(p1, &elemento);
    
    // printf("O elemento do topo é: %d\n", elemento);
    
    printf("pilha p1:\n");
    pilha_imprimir(p1);
    
    // int retorno = pilha_tamanho(p1);
    // printf("O Vetor tem tamanho %d\n", retorno);

    p2 = pilha_clone(p1);

    printf("\nclone p2:\n");
    pilha_imprimir(p2);

    // pilha_desempilhar(p1, &elemento);

    printf("\npilha p1:\n");
    pilha_imprimir(p1);

    
    // printf("\nteste\n");
    // pilha_inverter(p1);
    
    // printf("\nvetor invertido\n");
    // pilha_imprimir(p1);
    
    pilha_empilharTodos(p1, vetor, 4);

    printf("\nEmpilhar todos\n");
    pilha_imprimir(p1);

}