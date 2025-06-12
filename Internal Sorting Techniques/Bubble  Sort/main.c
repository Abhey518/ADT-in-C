#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 5

int main() {

    int i,j,k;
    int L[MAXLIST];

    //input values to the list
    L[0] = 100;
    L[1] = 23;
    L[2] = 7;
    L[3] = 45;
    L[4] = 70;

    //print the initial list (without sorting)
    printf("\nList without sorting: ");
    for (i = 0; i < MAXLIST; i++) {
        printf("%d ", L[i]);
    }

    //Use bubble sort
    for (i = 0; i < MAXLIST - 1; i++) {
        for (j = 0; j < MAXLIST - 1 - i; j++) {
            if (L[j+1] < L[j]) {
                k = L[j];
                L[j] = L[j+1];
                L[j+1] = k;

            }
        }
    }

    //output
    printf("\n\nBubble Sorted List: ");
    for (i = 0; i < MAXLIST; i++) {
        printf("%d ", L[i]);
    }
    printf("\n");
    return 0;
}
