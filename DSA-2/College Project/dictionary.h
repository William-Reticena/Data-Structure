#pragma once

typedef struct no {
    char *word;
    struct no *ant;
    struct no *prox;
}No;

typedef struct {
    No* sentinela;
    int qtde;
}Lista;

typedef enum {
    C_VERMELHO,
    C_PRETO
} ARN_COR;

typedef struct ARN{
    struct ARN* esq;
    struct ARN* dir;
    ARN_COR cor;
    char *chave;
    Lista *elementos;
} ARN;

void Criar_Arvore(ARN **A);
char* sortWord(char *word);
void toLower(char *word);
void Lista_Imprimir(Lista* l);
ARN* ARN_Buscar(ARN** A, char *chave);