/*
 * 题目：
 *
 * 已知一个带头结点的单链表 L，设计一个算法找出链表中
 * 倒数第 k 个结点，并输出该结点的数据。
 *
 * 例如：
 *
 * 链表：
 *
 * head -> 10 -> 20 -> 30 -> 40 -> 50
 *
 * 若 k = 2，则倒数第 2 个结点为：
 *
 * 40
 *
 * 要求：
 *
 * 1. 不能通过遍历链表多次求解，要求算法时间复杂度为 O(n)。
 *
 * 2. 使用双指针方法：
 *
 *    设置两个指针 fast 和 slow，使 fast 指针先向后移动 k 个结点，
 *    然后两个指针同时向后移动。
 *
 *    当 fast 指针到达链表尾部时，slow 指针所指向的结点即为
 *    链表的倒数第 k 个结点。
 *
 * 3. 编写测试程序，创建一个单链表，并验证算法正确性。
 *
 */
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
