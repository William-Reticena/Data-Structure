#include <stdio.h>
#include <time.h>
#include "ab.h"
#include "arn.h"
#include "sort.h"

int main(void){
    clock_t t;
    int n = 500000;
    /*
    int *vABB1 = randomVector(n, n*10, 10);
    int *vABB2 = randomVector(n, n*10, 20);
    int *vABB3 = randomVector(n, n*10, 30);
    int *vABB4 = randomVector(n, n*10, 40);
    int *vABB5 = randomVector(n, n*10, 50);
    int *vABB6 = randomVector(n, n*10, 60);
    int *vABB7 = randomVector(n, n*10, 70);
    int *vABB8 = randomVector(n, n*10, 80);
    int *vABB9 = randomVector(n, n*10, 90);
    int *vABB10 = randomVector(n, n*10, 100);
    // */
    // quickSort(vABB, 0, n-1);

    //----------------------------------------
    // /*
    int *vARN1 = randomVector(n, n*10, 0);
    int *vARN2 = randomVector(n, n*10, 0);
    int *vARN3 = randomVector(n, n*10, 0);
    int *vARN4 = randomVector(n, n*10, 0);
    int *vARN5 = randomVector(n, n*10, 0);
    int *vARN6 = randomVector(n, n*10, 0);
    int *vARN7 = randomVector(n, n*10, 0);
    int *vARN8 = randomVector(n, n*10, 0);
    int *vARN9 = randomVector(n, n*10, 0);
    int *vARN10 = randomVector(n, n*10, 0);
    // */
    // quickSort(vARN, 0, n-1);

    t = clock();
    /*
    AB_Sort(vABB1, n);
    AB_Sort(vABB2, n);
    AB_Sort(vABB3, n);
    AB_Sort(vABB4, n);
    AB_Sort(vABB5, n);
    AB_Sort(vABB6, n);
    AB_Sort(vABB7, n);
    AB_Sort(vABB8, n);
    AB_Sort(vABB9, n);
    AB_Sort(vABB10, n);
    // */
    //-----------------------------
    // /*
    ARN_Sort(vARN1, n);
    ARN_Sort(vARN2, n);
    ARN_Sort(vARN3, n);
    ARN_Sort(vARN4, n);
    ARN_Sort(vARN5, n);
    ARN_Sort(vARN6, n);
    ARN_Sort(vARN7, n);
    ARN_Sort(vARN8, n);
    ARN_Sort(vARN9, n);
    ARN_Sort(vARN10, n);
    // */
    //-----------------------------
    t = clock() - t;

    printf("AB_Sort demorou %.5f segundos!\n", ((float)t)/CLOCKS_PER_SEC);

    return 0;
}
