#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char stackEntry;

typedef enum {

    FALSE,
    TRUE
} Boolean;

typedef struct node {

    stackEntry entry;
    struct node *next;
} Node;

typedef struct {

    int no_ele;
    Boolean full;
    Node *top;
} Stack;

void CreateStack(Stack *s)
{
	s -> top = NULL;
	s -> no_ele = 0;
	s -> full = FALSE;
}

Boolean  IsStackEmpty(const Stack *s) {

	return (s -> top == NULL);
}

Boolean IsStackFull(const Stack *s) {

	return(s -> full);
}

void push (stackEntry item, Stack *s) {

    Node *np = (Node *) malloc ( sizeof (Node) );
    if (np == NULL) {

        printf("Not Enough Memory! \n");
        s -> full = TRUE;
    } else {

        np -> entry = item;
        np -> next = s -> top;
        s -> top = np;
        s -> no_ele++;
    }
}


void displayStack (const Stack *s) {

    Node * current = s -> top;
    printf("\nReversed String input: ");

    while (current != NULL) {

        printf("%c" , current -> entry);
        current = current -> next;
    }
    printf(" \n");
}


int main() {

    Stack myStack;
    //stackEntry item;

    CreateStack(&myStack);

    int maxlength = 101;

    char input[maxlength];
    printf("--- Maximum size of the string input is %d chars ---\n", maxlength - 1);

    printf("\nEnter the string input: ");
    fgets(input, sizeof(input), stdin);

 // Remove trailing newline (if any)
    input[strcspn(input, "\n")] = '\0';

    // Push each character onto the stack
    for (int i = 0; input[i] != '\0'; i++) {
        push(input[i], &myStack);
    }

    // Display the reversed string
    displayStack(&myStack);

    return 0;
}

