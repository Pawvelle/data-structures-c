/*
 * 题目：
 *
 * 已知一个带头结点的单链表 L，设计一个算法将链表中的所有
 * 结点进行逆置，使原链表的第一个数据结点变为最后一个数据结点，
 * 最后一个数据结点变为第一个数据结点。
 *
 * 例如：
 *
 * 原链表：
 *
 * head -> 1 -> 2 -> 3 -> 4 -> 5
 *
 * 逆置后：
 *
 * head -> 5 -> 4 -> 3 -> 2 -> 1
 *
 *
 * 要求：
 *
 * 1. 使用链表指针操作完成逆置，不允许重新申请所有数据结点。
 *
 * 2. 使用三个指针 first、second、third 实现链表反转：
 *
 *    - third 用于保存 second 的后继结点，防止修改指针后丢失后续链表；
 *    - second 指向当前需要反转的结点；
 *    - first 指向已经完成反转的链表部分。
 *
 * 3. 算法时间复杂度要求为 O(n)，空间复杂度为 O(1)。
 *
 * 4. 编写测试程序，建立单链表并输出逆置前后的结果。
 *
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
reverseList(Node *head) {
    Node *first = NULL;
    Node *second = head->next;
    Node *third;

    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    head->next = first;

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
    insertHead(list, 10);
    insertHead(list, 9);
    insertHead(list, 8);
    insertHead(list, 7);
    insertHead(list, 6);
    insertHead(list, 5);
    insertHead(list, 4);
    insertHead(list, 3);
    insertHead(list, 2);
    insertHead(list, 1);
    listNode(list);

    list = reverseList(list);
    listNode(list);
}