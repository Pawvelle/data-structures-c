/*
 * 题目：
 * 给定一个带头结点的单链表，删除链表的中间节点。
 *
 * 要求：
 * 使用快慢指针方法找到链表的中间节点，并将其删除。
 * 若链表存在两个中间节点，则删除后一个中间节点。
 *
 * 思路：
 * 设置快指针 fast 和慢指针 slow。
 * fast 每次移动两步，slow 每次移动一步。
 * 当 fast 到达链表尾部时，slow 指向待删除节点的前一个节点。
 * 通过修改 slow 的 next 指针跳过待删除节点，并释放该节点空间。
 */

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

Node *
get_tail(Node *L) {
    Node *p = L;
    while (p->next != NULL)
        p = p->next;

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
delMiddleNode(Node *head) {
    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *p = slow->next;
    slow->next = p->next;
    free(p);

    return 1;
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
    Node *p = get_tail(list);
    p = insertTail(p, 1);
    p = insertTail(p, 2);
    p = insertTail(p, 3);
    p = insertTail(p, 4);
    p = insertTail(p, 5);
    listNode(list);

    delMiddleNode(list);
    listNode(list);

    return 0;
}