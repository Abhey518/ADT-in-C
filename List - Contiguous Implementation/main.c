#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 10
#define EMPTY 0
#define FULL MAXLIST

typedef char listData;

typedef int position;

typedef enum {
    FALSE, TRUE
} Boolean;

typedef struct {
    listData entry[MAXLIST];
    int count;

} List;

//Create list function
void createList (List *l) {
    l -> count = 0;

}

//check empty function
Boolean isListEmpty (const List *l) {
    return(l -> count == EMPTY);

}

//check full function
Boolean isListFull (const List *l) {
    return(l -> count == FULL);

}

//check the size of the list
int listSize (const List *l) {
    return(l -> count);

}

//insert data into the list from the end
void insertLast (List *l, listData item) {
    if (isListFull(l)) {
        printf("--- Not enough memory. List is full ---");
        exit(1);

    } else {
        l -> entry[l -> count++] = item;

    }
}

//insert data into any position within the list
void insertList (List *l, position p,listData item) {
    if (isListFull(l)) {
        printf("--- Not enough memory. List is full ---");
        exit(1);

    } else if (p < 0 || p > listSize(l)) {
        printf("--- Attempt to insert data into a position not in the list ---");

    } else {
        for (int i = listSize(l) - 1; i >= p; i--) {
            l -> entry[i + 1] = l -> entry[i];

        }
        l -> entry[p] = item;
        l -> count++;
    }
}

//delete data from any valid position
void deleteList (List *l, position p, listData *item) {
    if (isListEmpty(l)) {
        printf("--- Attempt to delete an entry from an empty list ---");
        exit(1);

    } else if (p < 0 || p > listSize(l)) {
        printf("--- Attempt to delete data into a position not in the list ---");

    } else {
        for (int i = p; i <= listSize(l)-1;i++) {
            l -> entry[i] = l -> entry[i + 1];

        }
        * item = l -> entry[p];
        l -> count--;
    }
}

//retrieve the data from the list
void retrieveList (const List *l, position p, listData *item) {
    if (isListEmpty(l)) {
        printf("--- Attempt to retrieve an entry from an empty list ---");
        exit(1);

    } else if (p < 0 || p > listSize(l)) {
        printf("--- Attempt to retrieve data into a position not in the list ---");
        exit(1);

    } else
        *item = l -> entry[p];

    printf("\n--- Retrieved item from the position %d of the list: %c", p, *item);

}

//Replace the data from the list
void replaceList (List *l, position p, listData item) {
    if (isListEmpty(l)) {
        printf("--- Attempt to replace an entry in an empty list ---");
        exit(1);

    } else if (p < 0 || p > listSize(l)) {
        printf("--- Attempt to replace an entry in a position not in the list ---");
        exit(1);

    } else
        l -> entry[p] = item;

    printf("\n--- Replaced item in the position %d of the list: %c", p, item);

}

//Travel the list
void traverseList (const List *l) {
    printf("\n--- List Elements: ");
    for (int i = 0; i <= listSize(l)-1;i++ ) {
        printf("%c ",l -> entry[i]);

    }
}

int main () {

    List myList;
    listData item;

    createList(&myList);
    insertLast(&myList, 'A');
    insertLast(&myList, 'B');
    insertLast(&myList, 'C');
    insertLast(&myList, 'D');
    insertLast(&myList, 'F');
    insertLast(&myList, 'G');

    traverseList(&myList);

    insertList(&myList,4,'E');

    traverseList(&myList);

    deleteList(&myList, 5, &item);

    traverseList(&myList);

    retrieveList(&myList,1,&item);

    replaceList(&myList,1,'A');

    traverseList(&myList);

}
