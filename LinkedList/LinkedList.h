#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

/* 初始化链表 */
Node *
initList(void);

/* 头插法 */
int
insertHead(Node *L, ElemType e);

/* 获取尾节点 */
Node *
get_tail(Node *L);

/* 尾插法 */
Node *
insertTail(Node *tail, ElemType e);

/* 指定位置插入 */
int
insertNode(Node *L, int pos, ElemType e);

/* 删除指定位置节点 */
int
deleteNode(Node *L, int pos);

/* 获取链表长度 */
int
listLength(Node *L);

/* 释放链表 */
void
freeList(Node *L);

/* 遍历链表 */
void
listNode(Node *L);

#endif