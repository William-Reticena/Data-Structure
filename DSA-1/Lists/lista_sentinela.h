#include <stdlib.h>
#include <string.h>

typedef int TipoElemento;
typedef enum boolean {false=0, true=1} Boolean;

typedef struct no {
    TipoElemento dado;
    struct no* ant;
    struct no* prox;
}No;

typedef struct {
    No* sentinela;
    int qtde;
}Lista;

char* itoad(int value, char* str) {
        char temp;
        int i =0;
        while (value > 0) {
            int digito = value % 10;

            str[i] = digito + '0';
            value /= 10;
            i++;

        }
    i = 0;
    int j = strlen(str) - 1;

   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
    return str;
}

No* retornaEndereco(Lista* l, int posicao){
    No* addres = l->sentinela;
    for (int i=0; i<=posicao; i++) {
        addres = addres->prox;
    }

    return addres;
}

Lista* lista_criar() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l->sentinela = (No*) malloc(sizeof(No));
    l->sentinela->ant = l->sentinela;
    l->sentinela->prox = l->sentinela;
    l->qtde = 0;

    return l;
}

void lista_destruir(Lista* l) {
    free(l->sentinela);
    free(l);
}

Boolean lista_inserirFim(Lista* l, TipoElemento elemento) {
    if (l == NULL) return false;

    No* aux = (No*) malloc(sizeof(No));
    No* n;

    aux->dado = elemento;
    
    if (l->qtde <= 0) {
        l->sentinela->prox = aux;
        aux->ant = l->sentinela;
    } else {
        aux->ant = l->sentinela->ant;
        n->prox = aux;
    }

    aux->prox = l->sentinela;
    l->sentinela->ant = aux;
    l->qtde++;
    n = aux;

    return true;
}

void lista_imprimir(Lista* l) {
    No* aux = l->sentinela;
    int i = 0;
    printf("[");
    
    while (aux->prox != l->sentinela) {
        printf("%d", aux->prox->dado);
        aux = aux->prox;
        i++;

        if (i < l->qtde)
            printf(", ");
    }
    printf("]\n");
}

int lista_tamanho(Lista* l) {
    return l->qtde;
}

Boolean lista_inserir(Lista* l, TipoElemento elemento, int posicao) {
    if (l == NULL) return false;

    No* aux = (No*) malloc(sizeof(No));
    No* address;

    if (l->qtde == 0)
        lista_inserirFim(l, elemento);
    else if (posicao > l->qtde) {
        aux->ant = l->sentinela->ant;
        aux->prox = l->sentinela;
        l->sentinela->ant->prox = aux;
        l->sentinela->ant = aux;
    } else {
        address = retornaEndereco(l, posicao);
        aux->prox = address;
        aux->ant = address->ant;
        address->ant->prox = aux;
        address->ant = aux;
    }
    aux->dado = elemento;
    l->qtde++;

    return true;
}

Boolean lista_removerPosicao(Lista* l, int posicao, TipoElemento* endereco) {
    if (l == NULL || posicao > l->qtde-1 || l->qtde == 0 || posicao < 0) return false;

    No* address = retornaEndereco(l, posicao);

    if (posicao == 0) {
        l->sentinela->prox = address->prox;
        address->prox->ant = l->sentinela;
    } else if (posicao == l->qtde-1) {
        l->sentinela->ant = address->ant;
        address->ant->prox = l->sentinela;
    } else {
        address->ant->prox = address->prox;
        address->prox->ant = address->ant;
    }
    
    *endereco = address->dado;
    l->qtde--;
    free(address);

    return true;
}

int lista_removerElemento(Lista* l, TipoElemento elemento) {
    No* aux = l->sentinela->prox;
    int cont = 0, x;

    while (aux->dado != elemento) {
        if (cont > l->qtde) return -1;

        aux = aux->prox;
        cont++;
    }
    lista_removerPosicao(l, cont, &x);

    return cont;
}

Boolean lista_substituir(Lista* l, int posicao, TipoElemento novoElemento) {
    if (l == NULL || posicao > l->qtde) return false;

    No* address = retornaEndereco(l, posicao);

    address->dado = novoElemento;
    
    return true;
}

int lista_posicao(Lista* l, TipoElemento elemento) {
    No* aux = l->sentinela->prox; 
    int cont = 0;

    while (aux->dado != elemento) {
        if (cont > l->qtde) return -1;

        aux = aux->prox;
        cont++;
    }

    return cont;
}

Boolean lista_buscar(Lista* l, int posicao, TipoElemento* endereco) {
    if (l == NULL || posicao > l->qtde) return false;

    No* address = retornaEndereco(l, posicao);

    *endereco = address->dado;

    return true;
}

Boolean lista_contem(Lista* l, TipoElemento elemento) {
    if (l == NULL) return false;

    No* aux = l->sentinela->prox;
    int cont = 0;

    while (aux->dado != elemento) {
        if (cont > l->qtde) return false;

        aux = aux->prox;
        cont++;
    }    

    return true;
}

Boolean lista_toString(Lista* l, char* enderecoString) {
    if (l == NULL) return false;

    No* aux = l->sentinela;
    char str[20];


    while (aux->prox != l->sentinela) {
        itoad(aux->dado, str);   
        aux = aux->prox;
    }

    *enderecoString = *str;

    return true;
}