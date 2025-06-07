#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 10

typedef int stackEntry;

typedef struct {
    int top;
    stackEntry entry [MAXLENGTH];
}stack;

void createStack(stack *s) {
    s -> top = -1;
}

typedef enum {
    FALSE,
    TRUE
} Boolean;

Boolean isStackEmpty(const stack *s) {
    return(s -> top == -1);
}

Boolean isStackFull(const stack *s) {
    return(s -> top == MAXLENGTH - 1);
}

void push(stackEntry item,stack *s) {
    if (isStackFull(s)) {
        printf("Stack is full!");
        exit(1);

    } else {
        s -> entry[++s -> top] = item;
    }
}

void pop(stackEntry *item, stack *s) {
    if (isStackEmpty(s)) {
            printf("Stack is empty");
            exit(1);

    } else {
        *item = s -> entry[s -> top--];
    }



}

void peek(stackEntry *item,const stack *s) {
    if (isStackEmpty(s)) {
            printf("Stack is empty");
            exit(1);

    } else {
        *item = s -> entry[s -> top];
        printf("Current top item: %d \n", *item);
    }
}



int main() {

    stack myStack;
    createStack(&myStack);
    stackEntry item;
    int new;

    printf("Enter the stack element: ");
    scanf("%d", new);

    push(new, &myStack);
    peek(&item,&myStack);
}

