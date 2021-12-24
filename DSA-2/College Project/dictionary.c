#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

void toLower(char *word) {
    int i = 0;

    while (word[i] != '\0') {
        if (word[i] >= 65 && word[i] <= 90) {
            word[i] += 32;
        }
        i++;
    }
}

void removeNewLine(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == '\n')
            word[i] = '\0';

        i++;
    }
}

char* sortWord(char *word) {
    int i = 0, j;
    char k;
    char aux[25];
    int length = strlen(word);

    while (word[i] != '\0') {
        for (j=i+1; j < length; j++)
            if (word[i] > word[j]) {
                k = word[i];
                word[i] = word[j];
                word[j] = k;
            }
        i++;
    }

    return word;
}

//LISTA ENCADEADA
Lista* Lista_Criar() {
    Lista* l = malloc(sizeof(Lista));
    l->sentinela = malloc(sizeof(No));
    l->sentinela->ant = l->sentinela;
    l->sentinela->prox = l->sentinela;
    l->qtde = 0;

    return l;
}

void Lista_Inserir(Lista *l, char *word) {
    if (l == NULL) return;

    No *aux = malloc(sizeof(No));
    No *n = malloc(sizeof(No));
    aux->word = word;

    if (l->qtde == 0) {
        l->sentinela->prox = aux;
        aux->ant = l->sentinela;
    } else {
        aux->ant = l->sentinela->ant;
    }

    aux->prox = l->sentinela;
    l->sentinela->ant = aux;
    l->qtde++;
}

void Lista_Imprimir(Lista* l) {
    No* aux = l->sentinela->ant;
    int i = 0;
    printf("[");
    
    while (aux != l->sentinela) {
        printf("%s", aux->word);
        aux = aux->ant;
        i++;

        if (i < l->qtde)
            printf(", ");
    }
    printf("]\n");
}

//ARVORE RUBRO NEGRA
ARN* ARN_Buscar(ARN** A, char *chave) {
    if (*A == NULL) return NULL;

    int cmp = strcmp((*A)->chave, chave);

    if (cmp == 0) return *A;

    if (cmp > 0) return ARN_Buscar(&(*A)->dir, chave);

    else return ARN_Buscar(&(*A)->esq, chave);
}

ARN* ARN_Criar(char *chave, char *valor){
    ARN* novo;
    Lista *list = Lista_Criar();
    Lista_Inserir(list, valor);
    novo = malloc(sizeof(struct ARN));

    char *wordAlloc = malloc(sizeof(char) * (strlen(chave)+1));
    strcpy(wordAlloc, chave);

    novo->chave = wordAlloc;
    novo->elementos = list;
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

void ARN_Inserir_R(ARN** A, char *chave, char *valor) { 
    if ((*A) == NULL) {
        *A = ARN_Criar(chave, valor);
        return;
    }

    int cmp = strcmp((*A)->chave, chave);

    if (cmp < 0) {
        ARN_Inserir_R(&(*A)->esq, chave, valor);
    }

    if (cmp > 0) {
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

void ARN_Inserir(ARN** A, char *chave, char *valor) {
    ARN *exist = ARN_Buscar(&(*A), chave);

    if (exist != NULL){   
        Lista_Inserir(exist->elementos, valor);
    }
 
    else ARN_Inserir_R(A, chave, valor);

    (*A)->cor = C_PRETO;
}

//-------------------------------------
void Criar_Arvore(ARN **A) {
    ARN *Arv;
    int len;
    FILE *fp;
    char buffer[30]; 
    char *wordAddress;
    char *orderedWord;

    fp = fopen("br.txt", "r");

    while (!feof(fp)) {
        fgets(buffer, 30, fp);

        removeNewLine(buffer);
        toLower(buffer);
        len = strlen(buffer)+1;

        wordAddress = malloc(sizeof(char) * len);
        strcpy(wordAddress, buffer);

        orderedWord = malloc(sizeof(char) * len);
        strcpy(orderedWord, wordAddress);

        strcpy(orderedWord, sortWord(orderedWord));

        ARN_Inserir(A, orderedWord, wordAddress);
    }

    fclose(fp);
}