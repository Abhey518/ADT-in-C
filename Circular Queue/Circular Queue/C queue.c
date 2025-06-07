#include <stdio.h>
#include <stdlib.h>

// Define an Queue
#define MAXQUEUE 20

typedef int QueueElement;

typedef struct queue {
    QueueElement items [MAXQUEUE];
    int front;
    int rear;
    int count;
} Queue;

// Create an Queue
void CreateQueue (Queue *q) {
    q -> count = 0;
    q -> front = 0;
    q -> rear = -1;
}

#define TRUE 1
#define FALSE 0

// A function for checking the empty Queue
int IsQueueEmpty (const Queue *q) {

    return (q -> count == 0);
}

// A function for checking the full Queue
int IsQueueFull (const Queue *q) {

    return (q -> count == MAXQUEUE);
}

// Append an item to a Queue
void Append(Queue *q, QueueElement x) {
    if (IsQueueFull(q)) {
        printf("Queue Full\n");
        exit(1);

    } else {
        q -> rear = (q -> rear + 1) % MAXQUEUE;
        q -> items [(q -> rear)] = x;
        q -> count++;
    }
}

// Serve/Remove an item from a Queue
void Serve(Queue *q, QueueElement *x) {
    if (IsQueueEmpty(q)) {
        printf("Queue is empty, underflow\n");
        exit(1);

    } else {
        *x = q -> items[(q -> front)];
        q -> front = (q -> front+1) % MAXQUEUE;
        q -> count--;
        printf("Served item: %d\n", *x);
    }
}

// Size of the Queue
int QueueSize (const Queue *q) {
    return (q -> count);
}

// Display the Queue
void displayQueue(const Queue *q) {

    if(IsQueueEmpty(q)) {
        printf("Queue is empty, underflow\n");
        return;
    }
    printf("Queue Elements: ");

    for ( int i = q -> front; i <= q -> rear; i++) {
        printf("%d ", q -> items[i]);
    }
    printf("\n");
}

int main () {

    Queue myQueue;
    QueueElement item;

    CreateQueue(&myQueue);

    Append(&myQueue, 10);
    Append(&myQueue, 5);
    Append(&myQueue, 6);
    Append(&myQueue, 8);
    Append(&myQueue, 9);

    displayQueue(&myQueue);

    Serve(&myQueue, &item);
    Serve(&myQueue, &item);

    displayQueue(&myQueue);

    printf("Item count: %d", QueueSize(&myQueue));
}

