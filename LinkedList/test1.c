#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *link;
} Node;

Node *
initNode() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->link = NULL;

    return head;
}

int
insertHead(Node *L, ElemType e) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        return 0;

    p->data = e;
    p->link = L->link;
    L->link = p;

    return 1;
}

int
FindKth(Node *list, int k) {
    Node *fast = list->link;
    Node *slow = list->link;

    for (int i = 0; i < k; i++) {
        if (fast == NULL)
            return 0;

        fast = fast->link;
    }

    while (fast != NULL) {
        fast = fast->link;
        slow = slow->link;
    }

    printf("%d\n", slow->data);
    return 1;
}

int
main(void) {
    Node *list = initNode();
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    insertHead(list, 40);
    insertHead(list, 50);
    insertHead(list, 60);
    insertHead(list, 70);
    insertHead(list, 80);
    insertHead(list, 90);

    FindKth(list, 3);

    return 0;
}
