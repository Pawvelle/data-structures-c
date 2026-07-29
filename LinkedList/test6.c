/*
 * 题目：重排链表
 *
 * 给定一个带头结点的单链表：
 *
 *     L0 -> L1 -> L2 -> ... -> Ln-1 -> Ln
 *
 * 要求将链表重新排列为：
 *
 *     L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 *
 * 注意：
 * 1. 不能只修改结点中的数据，必须通过修改结点的 next 指针完成重排。
 * 2. 要求尽量使用 O(n) 的时间复杂度和 O(1) 的额外空间复杂度。
 *
 * 例如：
 *
 * 原链表：
 *     1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
 *
 * 重排后：
 *     1 -> 7 -> 2 -> 6 -> 3 -> 5 -> 4
 *
 * 基本思路：
 * 1. 使用快慢指针找到链表的中间位置。
 * 2. 将链表后半部分反转。
 * 3. 将前半部分和反转后的后半部分交替合并。
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

// 初始化链表
Node *
initList() {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    return head;
}

// 寻找链表尾元素
Node *
get_tail(Node *head) {
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    return p;
}

// 尾插法
Node *
insertTail(Node *tail, ElemType e) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    tail->next = p;

    return p;
}

// 对链表元素重新排序
void
reOrderList(Node *head) {
    // 快慢指针寻找中间元素
    Node *fast = head->next;
    Node *slow = head->next;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 三指针反序
    Node *first = NULL;
    Node *second = slow->next;
    Node *third;
    slow->next = NULL; // 断开链表

    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    // 四指针重新排序元素
    Node *p1, *p2, *q1, *q2;
    p1 = head->next;
    q1 = first;

    while (p1 != NULL && q1 != NULL) {
        p2 = p1->next;
        q2 = q1->next;

        p1->next = q1;
        q1->next = p2;

        p1 = p2;
        q1 = q2;
    }
}

// 打印链表
void
listNode(Node *head) {
    Node *p = head;
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
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
    p = insertTail(p, 6);
    p = insertTail(p, 7);
    listNode(list);

    reOrderList(list);
    listNode(list);

    return 0;
}
