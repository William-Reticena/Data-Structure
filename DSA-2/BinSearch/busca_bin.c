#include <stdlib.h>
#include <stdio.h>

void printVector(int* v, int n) {
    int i;

    for (i=0; i<n-1; i++)
        printf("%d, ", v[i]);
    
    printf("%d\n", v[i]);
}

void swap(int* v, int i, int j) {
    int aux = v[i];

    v[i] = v[j];
    v[j] = aux;
}

void embaralhar(int *v, int ini, int fim){
    int i, j;
    for(i = fim-1; i > ini; i--){
        j = (rand() % (i + 1));
        j = j <= ini? ini+1 : j;
        swap(v, i, j);
    }
}

int* random_vector_unique_elems(int n, int seed) {
    int* v = (int*) malloc(sizeof(int) * n);
    int aux = seed / 5;

    for (int i=0; i<n; i++) {
        v[i] = seed + 12 / 7;
        seed = aux + v[i];
    }

    embaralhar(v, 0, n-1);

    return v;
}

//SELECTIONSORT
void SelectionSort(int *v, int n, int k) {
    for (int i = 0; i < k; i++) {
		
		int i_menor = i;
		for (int j = i + 1; j < n; j++)
			if (v[j] < v[i_menor])
				i_menor = j;
		
		int aux = v[i];
		v[i] = v[i_menor];
		v[i_menor] = aux;
	}		
}

int SelectionMinK(int *v, int n, int k) {
    SelectionSort(v, n, k);

    if (k > n) return v[0];
    
    return v[k-1];
}

//QUICKSORT
int partition(int* v, int p, int r) {
    int i=0, j=0;
    int x = v[r];

    i = p - 1;

    for (j=p; j<r; j++) {
        if (v[j] <= x) {
            i++;
            swap(v, i, j);
        }
    }

    swap(v, i+1, r);

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

int QuickMinK(int *v, int e, int d, int k) {
    quickSort(v, e, d-1);

    if (k > d) return v[d-1];

    return v[k-1];
}
