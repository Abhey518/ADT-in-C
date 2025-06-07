#include <stdio.h>
#include <stdlib.h>

typedef int stackEntry;

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

void Pop(stackEntry *item, Stack *s) {

    if (!IsStackEmpty(s)) {

        Node *np = s -> top;
        *item = np -> entry;
        s->top = s -> top -> next;
        free(np);
        s -> no_ele--;
    } else {

        printf("Stack is empty! \n");
        exit(1);
    }
}

void displayStack (const Stack *s) {

    Node *current = s -> top;
    printf("Stack (top to bottom): ");

    while (current != NULL) {

        printf("%d " , current -> entry);
        current = current -> next;
    }
    printf(" \n");
}

void destroyStack (Stack *s) {

    Node *np;
    while ( s -> top != NULL) {

        np = s -> top;
        s -> top = s -> top -> next;
        free(np);
    }
    s -> no_ele = 0;
    s -> full = FALSE;
}


int main() {

    Stack myStack;
    stackEntry item;

    CreateStack(&myStack);

    push(10, &myStack);
    push(20, &myStack);
    push(30, &myStack);

    displayStack(&myStack);

    Pop(&item, &myStack);
    printf("Popped: %d \n", item);

    displayStack(&myStack);
    destroyStack(&myStack);

    //displayStack(&myStack); does not display anything since we destroyed the stack.

    return 0;
}

