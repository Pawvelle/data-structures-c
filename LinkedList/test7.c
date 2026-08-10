/*
 * 题目：判断单链表是否有环，并查找环的入口节点
 *
 * 问题描述：
 * 给定一个单链表，判断该链表中是否存在环。
 *
 * 若链表存在环：
 * 1. 判断链表有环；
 * 2. 找出环的入口节点，并返回该节点。
 *
 * 若链表不存在环：
 * 返回 NULL。
 *
 * 要求：
 * 使用快慢指针（Floyd 判圈算法）实现，
 * 时间复杂度为 O(n)，空间复杂度为 O(1)。
 *
 * 示例：
 *
 * head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
 *                  ^                        |
 *                  |________________________|
 *
 * 该链表存在环，环的入口节点为 3。
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
get_tail(Node *head) {
    Node *p = head;
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
isCycle(Node *head) {
    Node *slow = head;
    Node *fast = head;

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
    Node *head = initList();
    Node *p = get_tail(head);
    p = insertTail(p, 1);
    p = insertTail(p, 2);
    p = insertTail(p, 3);
    Node *q = p;
    p = insertTail(p, 4);
    p = insertTail(p, 5);
    p = insertTail(p, 6);
    p = insertTail(p, 7);
    p = insertTail(p, 8);
    p->next = q;

    printf("%d\n", isCycle(head));
    printf("%d\n", findBegin(head)->data);

    return 0;
}
