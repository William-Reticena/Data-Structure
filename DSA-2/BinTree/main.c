#include <stdio.h>
#include <stdlib.h>
// #include "cstack.h"
// #include "shunting_yard.h"
#include "ab.h"

int main(){
    int vet1[] = {70, 39, 88};                                  //REMOVER 70
    int vet2[] = {10, 4, 20, 6, 2, 3, 5, 7};                    //REMOVER 10, 4, 5
    int vet3[] = {30, 50, 40, 47, 15, 20, 25, 17, 19, 4, 7, 0}; //REMOVER 0, 30, 15, 20

    //PRIMEIRO EXEMPLO
    /*
    AB* v1 = AB_Criar(70, NULL, NULL);

    for (int i=1; i<3; i++) 
        AB_Inserir(&v1, vet1[i]);

    AB_Imprimir(v1);
    printf("\n");
    AB_Remover(&v1, 39);

    AB_Imprimir(v1);
    // */

    //---------------------------------------------
    //SEGUNDO EXEMPLO
    /*
    AB* v2 = AB_Criar(10, NULL, NULL);

    for (int i=1; i<8; i++) 
        AB_Inserir(&v2, vet2[i]);

    AB_Imprimir(v2);
    printf("\n");

    AB_Remover(&v2, 10);
    AB_Imprimir(v2);
    printf("\n");

    AB_Remover(&v2, 4);
    AB_Imprimir(v2);
    printf("\n");

    AB_Remover(&v2, 5);

    AB_Imprimir(v2);
    // */

    //---------------------------------------------
    //TERCEIRO EXEMPLO
    // /*
    AB* v3 = AB_Criar(30, NULL, NULL);

    for (int i=1; i<12; i++) 
        AB_Inserir(&v3, vet3[i]);

    AB_Imprimir(v3);
    printf("\n");

    AB_Remover(&v3, 0);
    AB_Imprimir(v3);
    printf("\n");

    AB_Remover(&v3, 30);
    AB_Imprimir(v3);
    printf("\n");

    AB_Remover(&v3, 15);
    AB_Imprimir(v3);
    printf("\n");

    AB_Remover(&v3, 20);

    AB_Imprimir(v3);
    // */
    //---------------------------------------------
    return 0;
}
