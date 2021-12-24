#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* randomVector(int n, int max, int seed) {
    int* v = (int*) malloc(sizeof(int) * n);
    srand(seed);

    for (int i=0; i<n; i++)
        v[i] = rand() % (max+1);
    
    return v;
}

void printVector(int* v, int n) {
    int i;

    for (i=0; i<n-1; i++)
        printf("%d, ", v[i]);
    
    printf("%d\n", v[i]);
}

void troca(int* v, int i, int j) {
    int aux = v[i];

    v[i] = v[j];
    v[j] = aux;
}


//QUICKSORT DO VÍDEO
//------------------------------------------------------------
int partition(int* v, int p, int r) {
    int i=0, j=0;
    int x = v[r];

    i = p - 1;

    for (j=p; j<r; j++) {
        if (v[j] <= x) {
            i++;
            troca(v, i, j);
        }
    }

    troca(v, i+1, r);

    return i+1;
}

void quickSort(int* v, int e, int d) {
    int q;	
    if (e < d) {
        q = partition(v, e, d);
        quickSort(v, e, q-1);
        quickSort(v, q+1, d);
    }
}

//QUICKSORT RANDOMIZADO
//------------------------------------------------------------
int partitionRandom(int* v, int p, int r) {
    int x, i, j;
    srand(time(NULL));
    int aux = p + (rand() % (r - p));

    troca(v, aux, r);
    
    x = v[r];
    i = p - 1;

    for (j=p; j<r; j++) {
        if (v[j] <= x) {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);

    return i+1;
}

void quickSortRadom(int* v, int e, int d) {
    int q;

    if (e < d) {
        q = partitionRandom(v, e, d);
        quickSortRadom(v, e, q-1);
        quickSortRadom(v, q+1, d);
    }
}

//QUICKSORT MEDIAN
//------------------------------------------------------------
void medianOfThree(int* v, int p, int r){
    int center = (p + r) / 2;

    if (v[p] > v[center])
        troca(v, p, center);

    if (v[p] > v[r])
        troca(v, p, r);

    if (v[center] > v[r])
        troca(v, center, r);
    troca(v, center, r);
}

int partitionMedianOfThree(int* v, int p, int r) {
    int i, j;
    int x = v[r];

    i = p - 1;

    for (j=p; j<r; j++) {
        if (v[j] <= x) {
            i++;
            troca(v, i, j);
        }
    }

    troca(v, i+1, r);

    return i+1;
}

void quickSortMedianOfThree(int* v, int e, int d) {
    int q;	
    if (e < d) {
        medianOfThree(v, e, d);

        q = partitionMedianOfThree(v, e, d);
        quickSortMedianOfThree(v, e, q-1);
        quickSortMedianOfThree(v, q+1, d);
    }
}
