#include <stdio.h>
#include <stdlib.h>

typedef int listData;

typedef int position;

typedef enum {
    FALSE,
    TRUE
} Boolean;

typedef struct listnode {
    listData entry;
    struct listnode *next;

} listNode;

typedef struct {
    int count;
    Boolean full;
    listNode *head;

} List;

void createList (List *l) {
    l -> count = 0;
    l -> full = FALSE;
    l -> head = NULL;
}

Boolean isListEmpty (const List *l) {
    return(l -> head == NULL);

}

Boolean isListFull (const List *l) {
    return(l -> full);

}

int listSize (const List *l) {
    return(l -> count);

}

listNode *createListNode (listData item) {
    listNode *p = (listNode *) malloc( sizeof(listNode) );

    if (p  == NULL) {
        printf("--- Not enough Memory. List is full ---\n");
        exit(1);

    } else {
        p -> entry = item;
        p -> next = NULL;

    }
    return(p);
}

 //set position
void setPosition (List *l, position p, listNode **current) {

    if ( p < 0 || p > l -> count) { // or we can use listSize(l)
        printf("\n--- Attempt to set a position not in the list ---");
        *current = NULL;

    } else {
        // Start from the head of the list
        listNode *np = l -> head;

        // Traverse until reaching position p
        for (int i = 0; i < p ; i++) { // Stop at (p-1) to get the node BEFORE position p
                np = np -> next;
        }
        *current = np;
    }
}

// Insert at beginning
void insertHead (List *l,listData item) {
    listNode *np = createListNode(item);
    np -> next = l -> head;
    l -> head = np;
    l -> count++;

}

// Insert at any valid position
void insertList (List *l, position p, listData item) {
    listNode *np = NULL;
    listNode *current = NULL;

    if ( p < 0 || p > listSize(l)) { // or we can use l -> count
        printf("\n--- Attempt to insert a position not in the list ---");

    } else {
        np = createListNode(item);
        if (np == NULL) {
            l -> full = TRUE;
            printf("\n--- Not enough Memory. List is full ---");
            return;

        } else if(p == 0) {
            np -> next = l -> head;
            l -> head = np;

        } else {
            setPosition(l, p - 1, &current);
            np -> next  = current -> next;
            current -> next = np;

        }
        l -> count++;
    }
}

void displayList (List *l) {
    if (isListEmpty(l)) {
        printf("\n--- List is empty ---");

    } else {
        printf("\n--- List elements: ");
        listNode *current = l -> head;
        while (current != NULL) {
            printf("%d ", current -> entry);
            current = current -> next;

        }
    }
}


int main() {
    List myList;
    createList(&myList);

    insertHead(&myList, 40);
    insertHead(&myList, 30);
    insertHead(&myList, 10);
    displayList(&myList);

    insertList(&myList, 1, 20);
    displayList(&myList);

    return 0;

}
