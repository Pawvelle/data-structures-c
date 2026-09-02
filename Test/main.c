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

Node *
insertTail(Node *tail, ElemType e) {
    Node *p = malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    tail->next = p;

    return p;
}

Node *
removeElements(Node *head, ElemType val) {
    Node *p = head;

    while (p->next != NULL) {
        if (p->next->data == val) {
            Node *q = p->next;
            p->next = q->next;

            free(q);
        } else {
            p = p->next;
        }
    }

    return head;
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
    Node *head = initNode();

    Node *p = get_tail(head);
    p = insertTail(p, 7);
    p = insertTail(p, 7);
    p = insertTail(p, 7);
    p = insertTail(p, 7);
  /*   p = insertTail(p, 4);
    p = insertTail(p, 5);
    p = insertTail(p, 6); */

    removeElements(head, 7);
    listNode(head);

    return 0;
}