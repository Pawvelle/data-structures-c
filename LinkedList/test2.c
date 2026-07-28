/*
 * 题目：
 *
 * 已知两个单链表 A 和 B，链表中每个结点包含数据域 data
 * 和指针域 link。由于链表的存储结构特点，两个链表可能
 * 在某个结点之后共享相同的结点，即两个链表存在公共结点。
 *
 * 例如：
 *
 *      A: a -> b -> c
 *                 \
 *                  d -> e
 *
 *      B: x -> y
 *              \
 *               d -> e
 *
 * 其中 d、e 结点为两个链表的公共结点。
 *
 * 设计一个算法，找出两个单链表的第一个公共结点。
 *
 * 要求：
 *
 * 1. 实现一种基于链表长度差的算法：
 *    先分别求两个链表的长度，使较长链表的指针先移动
 *    若干步，使两个指针处于同一起点，然后同步向后遍历，
 *    找到第一个地址相同的结点。
 *
 * 2. 实现一种基于双指针交替遍历的算法：
 *    两个指针分别从两个链表头结点开始遍历，当一个指针
 *    到达链表尾部时，使其转向另一个链表继续遍历，最终
 *    两个指针将在第一个公共结点相遇。
 *
 * 3. 编写测试程序，建立两个存在公共结点的单链表，并输出
 *    找到的第一个公共结点的数据。
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

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

Node *
get_tail(Node *L) {
    Node *p = L;

    while (p->link != NULL)
        p = p->link;

    return p;
}

Node *
insertTailWithElemType(Node *tail, ElemType e) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    tail->link = p;

    return p;
}

Node *
insertTailWithList(Node *tail, Node *node) {
    tail->link = node->link;

    return node;
}

int
get_len(Node *list) {
    int len = 0;
    Node *p = list->link;

    while (p != NULL) {
        len++;
        p = p->link;
    }

    return len;
}

Node *
FindCommon1(Node *str1, Node *str2) {
    Node *p = str1->link;
    Node *q = str2->link;

    int m = get_len(str1);
    int n = get_len(str2);

    if (m > n) {
        for (int i = 0; i < m - n; i++)
            p = p->link;
    } else {
        for (int i = 0; i < n - m; i++)
            q = q->link;
    }

    while (p != q) {
        p = p->link;
        q = q->link;
    }

    return p;
}

Node *
FindCommon2(Node *str1, Node *str2) {
    Node *p = str1->link;
    Node *q = str2->link;

    while (p != q) {
        if (p->link == NULL)
            p = str2->link;
        else
            p = p->link;

        if (q->link == NULL)
            q = str1->link;
        else
            q = q->link;
    }

    return p;
}

void
listNode(Node *L) {
    Node *p = L->link;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->link;
    }
    printf("\n");
}

int
main(void) {
    Node *str1 = initNode();
    Node *str2 = initNode();
    Node *str = initNode();

    Node *p;
    p = get_tail(str1);
    p = insertTailWithElemType(p, 'l');
    p = insertTailWithElemType(p, 'o');
    p = insertTailWithElemType(p, 'a');
    p = insertTailWithElemType(p, 'd');

    p = get_tail(str2);
    p = insertTailWithElemType(p, 'b');
    p = insertTailWithElemType(p, 'e');

    p = get_tail(str);
    p = insertTailWithElemType(p, 'i');
    p = insertTailWithElemType(p, 'n');
    p = insertTailWithElemType(p, 'g');

    insertTailWithList(get_tail(str1), str);
    insertTailWithList(get_tail(str2), str);

    listNode(str1);
    listNode(str2);

    p = FindCommon1(str1, str2);
    printf("%c\n", p->data);

    return 0;
}