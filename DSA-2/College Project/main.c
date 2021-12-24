#include <stdio.h>
#include "dictionary.h"   

int main(int argc, char **argv) {
    ARN *A = NULL;
    ARN *aux;

    toLower(*(argv+1));

    sortWord(*(argv+1));
    
    Criar_Arvore(&A);

    aux = ARN_Buscar(&A, *(argv+1));

    Lista_Imprimir(aux->elementos);

    return 0;
}