#include <stdlib.h>


typedef enum boolean {false=0, true=1} Boolean;
typedef int TipoElemento;
typedef struct {
    TipoElemento* vetor;
    int tam;
    int qtde;
} FilaPrioridade;

void filaP_imprimir(FilaPrioridade* f);
Boolean filaP_vazia(FilaPrioridade* f);

int position(TipoElemento aux, FilaPrioridade* f) {
    for (int i=0; i<f->qtde; i++)
        if (f->vetor[i] == aux)
            return i;
}
void verifica_aumenta(FilaPrioridade* f) {
    if (f->qtde >= f->tam) {
        FilaPrioridade* novo = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
        f->tam *= 2;
        novo->vetor = (TipoElemento*) calloc(f->tam, sizeof(TipoElemento));

        for (int i=0; i<f->qtde; i++)
            novo->vetor[i] = f->vetor[i];

        f->vetor = novo->vetor;
    }
}

FilaPrioridade* filaP_criar() {
    FilaPrioridade* f = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    f->vetor = (TipoElemento*) calloc(2, sizeof(TipoElemento));
    f->qtde = 0;
    f->tam = 2;

    return f;
}

void filaP_destruir(FilaPrioridade* f) {
    free(f->vetor);
    free(f);
}

Boolean filaP_inserir(FilaPrioridade* f, TipoElemento elemento) {
    if (f == NULL) return false;

    TipoElemento pai, aux, pos;
    verifica_aumenta(f);

    f->vetor[f->qtde++] = elemento;
    pos = f->qtde-1;
    pai = (pos-1) / 2;

    do {
        if (f->vetor[pos] > f->vetor[pai]) {
            aux = f->vetor[pos];
            f->vetor[pos] = f->vetor[pai];
            f->vetor[pai] = aux;
            pos = position(aux, f);
        }
        
        pai = (pos-1) / 2;

    }while(f->vetor[pos] > f->vetor[pai]);  


    return true;
}

Boolean filaP_remover(FilaPrioridade* f, TipoElemento* saida) {
    if (f == NULL) return false;
    int atual = 0, k, pai;
    TipoElemento aux;
    Boolean x = true;
    *saida = f->vetor[atual];

    f->vetor[atual] = f->vetor[f->qtde-1];
    f->qtde--;
    f->tam--;

    while (x == true) {
        filaP_imprimir(f);
        int filhoE = 2*atual+1;
        int filhoD = 2*atual+2;

        if (filhoE >= f->qtde-1)
            break;
        
        if (f->vetor[atual] < f->vetor[filhoE])
            k = filhoE;
        else if (f->vetor[atual] < f->vetor[filhoD])
            k = filhoD;
        else break;

        aux = f->vetor[atual];
        f->vetor[atual] = f->vetor[k];
        f->vetor[k] = aux;

        atual = position(aux, f);
        pai = (atual-1) / 2;
        
        if (f->vetor[pai] < f->vetor[filhoE]) {
            k = filhoE;
            
            aux = f->vetor[pai];
            f->vetor[pai] = f->vetor[k];
            f->vetor[k] = aux;
        }

        else if (f->vetor[pai] < f->vetor[filhoD]) {
            k = filhoD;

            aux = f->vetor[pai];
            f->vetor[pai] = f->vetor[k];
            f->vetor[k] = aux;
        }
    }
    
    filaP_vazia(f);

    return true;
}

Boolean filaP_vazia(FilaPrioridade* f) {
    if (f == NULL) return false;

    if (f->qtde == 0) return true;
    else return false;
}

int filaP_tamanho(FilaPrioridade* f) {
    return f->qtde;
}

void filaP_imprimir(FilaPrioridade* f) {
    printf("[");
    for (int i=0; i<f->qtde; i++){
        printf("%d", f->vetor[i]);

        if (i < f->qtde-1)
            printf(", ");
    }
    printf("]\x0a");
}

FilaPrioridade* filaP_clone(FilaPrioridade* f) {
    FilaPrioridade* novo = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    novo->vetor = (TipoElemento*) calloc(f->qtde, sizeof(TipoElemento));
    novo->qtde = f->qtde;
    novo->tam = f->tam;

    for (int i=0; i<f->qtde; i++)
        novo->vetor[i] = f->vetor[i];

    return novo;

}

Boolean filaP_inserirTodos(FilaPrioridade* f, TipoElemento* vetor, int tamVetor) {
    if (f == NULL) return false;

    for (int i=0; i<tamVetor; i++)
        filaP_inserir(f, vetor[i]);
}