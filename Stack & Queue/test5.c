#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType *data;
    int front;
    int rear;
} Queue;

Queue *
initQueue() {
    Queue *Q = malloc(sizeof(Queue));
    Q->data = malloc(sizeof(ElemType) * MAXSIZE);
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int
isEmpty(Queue *Q) {
    if (Q->rear == Q->front) {
        printf("空的\n");
        return 1;
    }

    return 0;
}

int
dequeue(Queue *Q, ElemType *e) {
    if (Q->rear == Q->front) {
        printf("空的\n");
        return 0;
    }

    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

int
equeue(Queue *Q, ElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front) {
        printf("满了\n");
        return 0;
    }

    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int
getHead(Queue *Q, ElemType *e) {
    if (Q->front == Q->rear) {
        printf("空的\n");
        return 0;
    }

    *e = Q->data[Q->front];
    return 1;
}

int
main(void) {
    Queue *q = initQueue();

    equeue(q, 10);
    equeue(q, 20);
    equeue(q, 30);
    equeue(q, 40);
    equeue(q, 50);

    ElemType e;
    dequeue(q, &e);
    printf("%d\n", e);
    dequeue(q, &e);
    printf("%d\n", e);
    getHead(q, &e);
    printf("%d\n", e);

    return 0;
}