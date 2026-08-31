#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

Node *
initNode() {
    Node *head = malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;

    return head;
}

Node *
get_tail(Node *head) {
    Node *p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    return p;
}

int
get_length(Node *head) {
    int n = 0;
    Node *p = head;

    while (p->next != NULL) {
        p = p->next;
        n++;
    }

    return n;
}

Node *
insertTail(Node *tail, ElemType e) {
    Node *p = malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    tail->next = p;

    return p;
}

Node *
rotateRight(Node *head, int k) {
    int n = get_length(head);

    if (n == 0 || k % n == 0)
        return head;

    int t = 0;
    Node *p = head;
    Node *q = p;

    while (p->next != NULL) {
        if (t == n - (k % n)) {
            q = p;
        }

        p = p->next;
        t++;
    }

    Node *tail = get_tail(head);
    tail->next = head->next;

    head->next = q->next;
    q->next = NULL;

    return head;
}

void
listNode(Node *head) {
    Node *p = head->next;

    while (p != NULL) {
        printf("%d", p->data);
        p = p->next;
    }

    printf("\n");
}

int
main(void) {
    Node *head = initNode();

    Node *p = get_tail(head);
    p = insertTail(p, 1);
    p = insertTail(p, 2);
    p = insertTail(p, 3);
    p = insertTail(p, 4);
    p = insertTail(p, 5);

    rotateRight(head, 6);
    listNode(head);

    return 0;
}
