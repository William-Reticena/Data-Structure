#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    // int vetorVideo[] = {10, 8, 6, 12, 13, 3, 15, 4, 11, 7};
    clock_t t;
    int n = 50000;
    int vetorVideo[] = {1, 2, 3, 4, 5};
    int* v = randomVector(n, n*10, 42);

    //QUICKSORT DO VÍDEO
    //------------------------------------------------------------
    // /*
    // printVector(v, n);
    // quickSort(v, 0, n-1);

    t = clock();
    quickSort(vetorVideo, 0, 5-1);
    // quickSort(v, 0, n-1);
    t = clock() - t;

    printf("O quickSort demorou %.5f segundos!\n", ((float)t)/CLOCKS_PER_SEC);

    // printVector(v, n);
    printVector(vetorVideo, 5);
    // */

    //QUICKSORT RANDOMIZADO
    //------------------------------------------------------------
    /*
    // printVector(v, n);
    quickSortRadom(v, 0, n-1);

    t = clock();
    quickSortRadom(v, 0, n-1);
    t = clock() - t;

    printf("O quickSortRandom demorou %.5f segundos!\n", ((float)t)/CLOCKS_PER_SEC);

    // printVector(v, n);
    // */

    //QUICKSORT MEDIAN
    //------------------------------------------------------------
    /*
    // printVector(v, n);
    quickSortMedianOfThree(v, 0, n-1);

    t = clock();
    quickSortMedianOfThree(v, 0, n-1);
    t = clock() - t;

    printf("O quickSortMedianOfThree demorou %.5f segundos!\n", ((float)t)/CLOCKS_PER_SEC);

    // printVector(v, n);
    // */
    return 0;
}