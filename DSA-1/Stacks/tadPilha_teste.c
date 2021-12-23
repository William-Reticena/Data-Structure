#include <stdio.h>
#include "PilhaEncadeada.h"

int main() {
    Pilha* p1 = pilha_criar();
    Pilha* p2;
    int vetor[4] = {5, 14, 18, 28};
    int elemento;

    
    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 30);
    pilha_empilhar(p1, 40);

    // pilha_destruir(p1);

    pilha_imprimir(p1);
    // pilha_desempilhar(p1, &elemento);
    // printf("O elemento removido da posic\xc6o [%d]: %d\n", p1->qtdeElementos, elemento);

    // pilha_desempilhar(p1, &elemento);
    // printf("O elemento removido da posic\xc6o [%d]: %d\n", p1->qtdeElementos, elemento);

    // pilha_desempilhar(p1, &elemento);
    // printf("O elemento removido da posic\xc6o [%d]: %d\n", p1->qtdeElementos, elemento);

    // pilha_desempilhar(p1, &elemento);
    // printf("O elemento removido da posic\xc6o [%d]: %d\n", p1->qtdeElementos, elemento);

    // pilha_imprimir(p1);
    
    // pilha_topo(p1, &elemento);
    // printf("O elemento do topo \x82: %d\n", elemento);
    
    // int retorno = pilha_tamanho(p1);
    // printf("A pilha tem tamanho %d\n", retorno);
    
    // p2 = pilha_clone(p1);
    
    // printf("\nclone p2:\n");
    // pilha_imprimir(p2);
    
    printf("\nteste\n");
    pilha_inverter(p1);
    
    pilha_imprimir(p1);  
    
    // printf("\nEmpilhar: todos\n");
    // pilha_empilharTodos(p1, vetor, 4);
    // pilha_imprimir(p1);
    return 0;
}