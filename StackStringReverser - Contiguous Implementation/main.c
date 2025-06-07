#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char stackEntry;

#define MAXSTACK 51

typedef struct {

    int top;
    stackEntry entry[MAXSTACK];
}Stack;

void createStack (Stack *s) {
    s -> top = -1;
}

#define TRUE 1
#define FALSE 0

int isStackEmpty (const Stack *s) {
    return(s -> top == -1);
}

int isStackFull (const Stack *s) {
    return(s -> top == MAXSTACK - 1);
}

void push (Stack *s, stackEntry item) {
    if (isStackFull(s)) {
        printf("--- Stack is full. String input is too long ---");
        exit(1);
    } else
        s -> entry[++(s -> top)] = item;
}

/*
stackEntry pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("--- Stack is empty ---\n");
        exit(1);
    } else {
        return s->entry[(s->top)--];
    }
}
*/


void displayStack (const Stack *s) {
    if (isStackEmpty(s)) {
        printf("\n--- Stack is empty ---");
        return;
    }

    printf("\nReverse String:");
    for (int i = s -> top; i >= 0; i--)
        printf("%c", s -> entry[i]);
    printf("\n");
}

int main() {

    Stack myStack;

    createStack(&myStack);

    char input[MAXSTACK];
    printf("--- Maximum size of the string input is %d chars ---\n", MAXSTACK - 1);

    printf("\nEnter the string input: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline (if any)
    input[strcspn(input, "\n")] = '\0';

    // Push each character onto the stack
    for (int i = 0; input[i] != '\0'; i++) {
        push(&myStack, input[i]);
    }

    // Display the reversed string
    displayStack(&myStack);

    return 0;
}







