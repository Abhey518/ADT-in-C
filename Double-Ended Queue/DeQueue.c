#include <stdio.h>
#include <stdlib.h>

// Define an Queue
#define MAXQUEUE 20

typedef int DqueueElement;

typedef struct dqueue {
    DqueueElement items [MAXQUEUE];
    int front;
    int rear;
    int count;
} Dqueue;

// Create an Queue
void CreateDqueue (Dqueue *q) {
    q -> count = 0;
    q -> front = 0;
    q -> rear = -1;
}

#define TRUE 1
#define FALSE 0

// A function for checking the empty Queue
int IsDqueueEmpty (Dqueue *q) {
    if (q -> rear < q -> front)
        return (TRUE);
    else
        return(FALSE);
}

// A function for checking the full Queue
int IsDqueueFull (Dqueue *q) {
    if (q -> rear == MAXQUEUE - 1)
        return (TRUE);
    else
        return(FALSE);
}

// Append an item to a Queue in rear
void AppendRear (Dqueue *q, DqueueElement x) {
    if (IsDqueueFull(q)) {
        printf("Dequeue Full\n");
        exit(1);

    } else {
        q -> items [++(q -> rear)] = x;
        q -> count++;
    }
}

// Append an item to a Queue in front
void AppendFront (Dqueue *q, DqueueElement x) {
    if (IsDqueueFull(q)) {
        printf("Dequeue Full\n");
        exit(1);

    } else {
        if (IsDqueueEmpty(q)) {
            q -> items [q -> front] = x;
            q -> rear++;

        } else {
            if(q -> front == 0) {
                //need to move elements to the back by one position
                for (int i = q -> rear; i >= q -> front; i--) {
                    q -> items[i+1] = q -> items[i];
                }

                q -> rear++;
                q-> items[q -> front] = x;

            } else
                q -> items[--(q -> front)] = x;
        }
        q -> count++;
    }

}

// Serve/Remove an item from a Queue in front
void ServeFront (Dqueue *q, DqueueElement *x) {
    if (IsDqueueEmpty(q)) {
        printf("Dequeue is empty, underflow\n");
        exit(1);
    }
    *x = q -> items [(q -> front)++];
    q -> count--;
    printf("Served item from front: %d\n", *x);
}

// Serve/Remove an item from a Queue in rear
void ServeRear (Dqueue *q, DqueueElement *x) {
    if (IsDqueueEmpty(q)) {
        printf("Dequeue is empty, underflow\n");
        exit(1);
    }
    *x = q -> items [(q -> rear)--];
    q -> count--;
    printf("Served item from rear: %d\n", *x);
}

// Display the Queue
void displayDqueue(const Dqueue *q) {

    if(IsDqueueEmpty(q)) {
        printf("Queue is empty, underflow\n");
        return;
    }
    printf("Dequeue Elements: ");

    for ( int i = q -> front; i <= q -> rear; i++) {
        printf("%d ", q -> items[i]);
    }
    printf("\n");
}

int main () {

    Dqueue myDqueue;
    DqueueElement item;

    CreateDqueue(&myDqueue);

    AppendRear(&myDqueue, 2);
    AppendRear(&myDqueue, 4);
    AppendRear(&myDqueue, 6);
    AppendRear(&myDqueue, 8);

    AppendFront(&myDqueue, 1);
    AppendFront(&myDqueue, 3);
    AppendFront(&myDqueue, 5);
    AppendFront(&myDqueue, 7);

    displayDqueue(&myDqueue);

    ServeFront(&myDqueue, &item);
    ServeFront(&myDqueue, &item);

    ServeRear(&myDqueue, &item);
    ServeRear(&myDqueue, &item);

    displayDqueue(&myDqueue);

}



