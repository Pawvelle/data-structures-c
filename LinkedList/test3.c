#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

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

int
get_max(Node *L) {
    int max = 0;
    Node *p = L->next;

    while (p != NULL) {
        if (abs(p->data) > max)
            max = abs(p->data);
        p = p->next;
    }

    return max;
}

void
removeNode(Node *L, int len) {
    Node *p = L;
    int index;
    int arr[len + 1];

    for (int i = 0; i < len + 1; i++)
        arr[i] = 0;

    while (p->next != NULL) {
        Node *q = p->next;
        index = abs(q->data);

        if (arr[index] == 0) {
            arr[index] = 1;
            p = p->next;
        } else {
            p->next = q->next;
            free(q);
        }
    }
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

int
main(void) {
    Node *list = initList();
    insertHead(list, 15);
    insertHead(list, -7);
    insertHead(list, -15);
    insertHead(list, -15);
    insertHead(list, 21);
    listNode(list);

    removeNode(list, get_max(list));
    listNode(list);

    return 0;
}