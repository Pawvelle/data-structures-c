/*
 * 题目：
 *
 * 已知一个带头结点的单链表 L，其中每个结点存储一个整数。
 * 设链表中结点个数为 n，且所有结点数据元素的绝对值均不超过 n。
 *
 * 请设计一个算法，删除链表中绝对值相同的重复结点，使得每个
 * 绝对值对应的元素在链表中只保留一个。
 *
 * 例如：
 *
 * 原链表：
 *
 * head -> 21 -> -15 -> 7 -> -21 -> 15 -> 7
 *
 * 其中：
 *
 * |21| = |-21|
 * |15| = |-15|
 * |7| = |-7|
 *
 * 因此删除重复结点后：
 *
 * head -> 21 -> -15 -> 7
 *
 * （保留每个绝对值第一次出现的结点）
 *
 *
 * 要求：
 *
 * 1. 利用辅助数组记录已经出现过的绝对值。
 *
 * 2. 遍历链表时：
 *    - 如果当前结点的绝对值没有出现过，则保留该结点；
 *    - 如果当前结点的绝对值已经出现，则删除该结点。
 *
 * 3. 算法要求时间复杂度为 O(n)，空间复杂度为 O(n)。
 *
 * 4. 编写测试程序，建立单链表并验证删除重复结点算法。
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