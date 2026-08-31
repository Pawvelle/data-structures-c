#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *prev, *next;
} Node;

Node *
initList() {
    Node *head = malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

int
insertHead(Node *head, ElemType e) {
    Node *p = malloc(sizeof(Node));
    p->data = e;
    p->prev = head;
    p->next = head->next;

    if (head->next != NULL) {
        head->next->prev = p;
    }

    head->next = p;

    return 1;
}

Node *
get_tail(Node *head) {
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    return p;
}

Node *
insertTail(Node *tail, ElemType e) {
    Node *p = malloc(sizeof(Node));
    p->data = e;
    p->prev = tail;
    tail->next = p;
    p->next = NULL;

    return p;
}

int
insertNode(Node *head, int pos, ElemType e) {
    Node *p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;

        if (p == NULL) {
            return 0;
        }
    }

    Node *q = malloc(sizeof(Node));
    q->data = e;
    q->prev = p;
    q->next = p->next;
    p->next = q;
    p->next->prev = q;

    return 1;
}

int
deleteNode(Node *head, int pos) {
    Node *p = head;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
        if (p == NULL) {
            return 0;
        }
    }

    Node *q = p->next;

    p->next = q->next;
    q->next->prev = p;
    free(q);

    return 0;
}

void
listNode(Node *head) {
    Node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int
main(void) {
    Node *head = initList();
    Node *tail = get_tail(head);
    tail = insertTail(tail, 1);
    tail = insertTail(tail, 2);
    tail = insertTail(tail, 3);
    tail = insertTail(tail, 4);

    insertNode(head, 3, 8);
    listNode(head);

    deleteNode(head, 3);
    listNode(head);

    return 0;
}
