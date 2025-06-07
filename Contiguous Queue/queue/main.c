#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 20

typedef int QueueElement;

typedef struct queue {
    QueueElement items [MAXQUEUE];
    int front;
    int rear;
    int count;
} Queue;
