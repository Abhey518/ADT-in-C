#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 5

int main() {

    int i,j,k;
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

    //Use insertion sort
    for (i = 1; i < MAXLIST; i++) {
        j = i - 1;
        while (j >= 0) {
            if (L[j+1] < L[j]) {
                k = L[j];
                L[j] = L[j+1];
                L[j+1] = k;

            }
            j--;
        }
    }

    //output
    printf("\n\nInsertion Sorted List: ");
    for (i = 0; i < MAXLIST; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
    return 0;
}
