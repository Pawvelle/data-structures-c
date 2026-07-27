#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

Node *
initList() {
    Node *head = (Node *)malloc(sizeof(Node));

    head->data = 0;
    head->next = NULL;

    return head;
}

int
insertHead(Node *L, ElemType e) {
    Node *p = (Node *)malloc(sizeof(Node));

    if (p == NULL)
        return 0;

    p->data = e;
    p->next = L->next;
    L->next = p;

    return 1;
}

Node *
get_tail(Node *L) {
    Node *p = L->next;

    while (p->next != NULL) {
        p = p->next;
    }

    return p;
}

Node *
insertTail(Node *tail, ElemType e) {
    Node *p = (Node *)malloc(sizeof(Node));

    p->data = e;
    p->next = NULL;
    tail->next = p;

    return p;
}

int
insertNode(Node *L, int pos, ElemType e) {
    Node *p = L;

    for (int i = 0; i < pos - 1; i++) {
        if (p->next == NULL)
            return 0;
        p = p->next;
    }

    Node *q = (Node *)malloc(sizeof(Node));

    if (q == NULL)
        return 0;

    q->data = e;
    q->next = p->next;
    p->next = q;

    return 1;
}

int
deleteNode(Node *L, int pos) {
    Node *p = L;

    for (int i = 0; i < pos - 1; i++) {
        if (p->next == NULL)
            return 0;
        p = p->next;
    }

    if (p->next == NULL) {
        return 0;
    }

    Node *q = p->next;
    p->next = q->next;
    free(q);

    return 1;
}

int
listLength(Node *L) {
    Node *p = L;
    int len = 0;

    while (p != NULL) {
        p = p->next;
        len++;
    }

    return len;
}

void
freeList(Node *L) {
    Node *p = L->next;
    Node *q;

    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    L->next = NULL;
}

void
listNode(Node *L) {
    Node *p = L->next;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}