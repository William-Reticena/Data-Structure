#include <stdio.h>
#include <time.h>
#include "busca_bin.h"

int main(void) {
    int n = 1000000;
    int v[] = {12, 1, 26, 13, 7, 19, 6, 22, 30, 29};
    int *random = random_vector_unique_elems(n, 42);

    // printVector(random, n);
    clock_t t;

    t = clock();
    // int output1 = SelectionMinK(random, n, n/2); 
    // printf("%d\n", output1);

    int output2 = QuickMinK(random, 0, n, n/2); //expected output: 12
    printf("%d\n", output2);
    t = clock() - t;

    printf("Demorou %.5f segundos!\n", ((float)t)/CLOCKS_PER_SEC);

    return 0;
}