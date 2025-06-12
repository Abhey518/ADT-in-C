#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 5

int main() {

    int i,j,k,min;
    int L[MAXLIST];

    //input values to the list
    L[0] = 100;
    L[1] = 23;
    L[2] = 45;
    L[3] = 7;
    L[4] = 70;

    //print the initial list (without sorting)
    printf("\nList without sorting: ");
    for (i = 0; i < MAXLIST; i++) {
        printf("%d ", L[i]);
    }

    //Use selection sort
    for (i = 0; i < MAXLIST-1; i++) {
        min = i;
        for (j=i+1; j < MAXLIST;j++) {
            if (L[j] < L[min]) {
                min = j;
            }
        }
        k = L[i];
        L[i] = L[min];
        L[min] = k;

    }


    //output
    printf("\n\nSelection Sorted List: ");
    for (i = 0; i < MAXLIST; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
    return 0;
}
