#include <stdio.h>
#include <stdlib.h>

typedef int QueueElement;

typedef struct node {
    QueueElement entry;
    struct node *next;

} QueueNode;

typedef enum {
    FALSE,
    TRUE

} Boolean;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    Boolean full;
    int count;

} Queue;

void createQueue (Queue *q) {
    q -> count = 0;
    q -> front = NULL;
    q -> rear = NULL;
    q -> full = FALSE;

}

Boolean isQueueEmpty (const Queue *q) {
    return (q -> front == NULL && q -> rear == NULL);

}

Boolean isQueueFull (const Queue *q) {
        return (q -> full);

}

void appendQueue (Queue *q, QueueElement item) {
    QueueNode *np = (QueueNode *) malloc (sizeof (QueueNode));

    if (np == NULL) {
        printf("--- Not enough memory. Queue is full ---\n");
        q -> full = TRUE;

    } else {
        np -> entry = item;
        np -> next = NULL;

        if (isQueueEmpty(q)) {
            q -> front = np;
            q -> rear = np;

        } else {
            q -> rear -> next = np;
            q -> rear = np;

        }
        printf("Enqueue item: %d\n", item);
        q -> count++;

    }
}

void serveQueue (Queue *q, QueueElement *item) {
    if (isQueueEmpty(q)) {
        printf("--- Queue is empty. No element to serve ---\n");
        exit(1);

    } else {
        * item = q -> front -> entry;
        QueueNode *np = q -> front;
        q-> front = q -> front -> next;
        q -> count--;
        printf("Dequeue item: %d\n", *item);

        if (q -> front == NULL)
            q -> rear = NULL;

        free(np);

    }
}

void displayQueue (const Queue *q) {
    if(isQueueEmpty(q)) {
        printf("\n--- Queue is empty ---\n");
        return;

    } else  {

        printf("\nQueue Elements: ");

        QueueNode *current = q -> front;
        while (current != NULL) {
            printf("%d " , current -> entry);
            current = current -> next;

        }
        printf(" \n");
    }
}

int main () {

    Queue myQueue;
    QueueElement item;

    createQueue(&myQueue);

    printf("--- Append elements to the Queue(Enqueue) ---\n");
    appendQueue(&myQueue, 10);
    appendQueue(&myQueue, 20);
    appendQueue(&myQueue, 30);
    appendQueue(&myQueue, 40);
    appendQueue(&myQueue, 50);

    displayQueue(&myQueue);

    printf("\n--- Serve elements from the Queue(Dequeue) ---\n");
    serveQueue(&myQueue, &item);
    serveQueue(&myQueue, &item);

    displayQueue(&myQueue);

    return 0;
}



