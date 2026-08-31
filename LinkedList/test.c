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
    tail->next = p;
    p->data = e;
    p->next = NULL;

    return p;
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
isCircle(Node *head) {
    Node *slow = head->next;
    Node *fast = head->next->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

Node *
findBegin(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int
main(void) {
    Node *head = initNode();
    Node *p = get_tail(head);
    p = insertTail(p, 1);
    p = insertTail(p, 2);
    p = insertTail(p, 3);
    Node *q = p;
    p = insertTail(p, 4);
    p = insertTail(p, 5);
    p = insertTail(p, 6);
    p->next = q;

    if (isCircle(head)) {
        printf("有环\n");
        printf("%d\n", findBegin(head)->data);
    } else {
        printf("无环");
    }

    return 0;
}
