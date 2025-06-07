#include <stdio.h>
#include <stdlib.h>


#define MAXSTACK 10

typedef int StackEntry;

typedef struct {

    int top;
    StackEntry entry[MAXSTACK];
} Stack;

typedef enum {

    FALSE,
    TRUE
} Boolean;

void createStack (Stack *s) {

    s -> top = -1;
}

Boolean isStackEmpty (const Stack *s) {

    return ( s -> top == -1);
}

Boolean isStackFull (const Stack *s) {

    return ( s -> top == MAXSTACK - 1 );
}

void push(StackEntry item, Stack *s) {

    if(!isStackFull(s)) {

        s->entry[ ++s -> top]= item;
        printf("Pushed item: %d \n", item);

    } else {

        printf("---Stack is Full !!! ---");
        exit(1); //program exit with an error code 1
    }
}

void pop(StackEntry *item, Stack *s) {

    if(!isStackEmpty(s)) {

        *item = s -> entry[ s -> top--];
        printf("Popped item: %d \n", *item);

    } else {

        printf("---Stack is Empty !!! ---");
        exit(1); //program exit with an error code 1
    }
}

void peek(StackEntry *item,const Stack *s) {

    if(!isStackEmpty(s)) {

        *item = s -> entry[ s -> top ];
        printf("Current top item: %d \n", *item);

    } else {

        printf("---Stack is Empty !!! --- \n");
        exit(1); //program exit with an error code 1
    }
}

void displayStack(const Stack *s) {

    if(isStackEmpty(s)) {

        printf("---Stack is Empty !!! ---");
        return;
    }
    printf("Stack Elements: ");

    for ( int i = s -> top; i >=0; i--) {

        printf("%d ", s -> entry[i]);
    }
    printf("\n");
}



int main(){

    Stack myStack;
    StackEntry item;

    createStack(&myStack);

    push(10,&myStack);
    push(20,&myStack);
    peek(&item,&myStack);
    push(30,&myStack);

    displayStack(&myStack);

    pop(&item,&myStack);
    displayStack(&myStack);

    return 0;
}
