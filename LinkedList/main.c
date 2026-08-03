#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int
main(void) {
    /*
     * 初始化链表
     *
     * 创建一个带头结点的空链表：
     *
     * head -> NULL
     */
    Node *list = initList();

    if (list == NULL) {
        printf("链表初始化失败\n");

        return 0;
    }

    printf("========== 初始化链表 ==========\n");

    listNode(list);

    /*
     * 测试头插法
     *
     * 插入顺序：
     *
     * insertHead(10)
     * insertHead(20)
     * insertHead(30)
     *
     * 结果：
     *
     * head -> 30 -> 20 -> 10
     */
    printf("\n========== 测试头插法 ==========\n");

    insertHead(list, 10);

    insertHead(list, 20);

    insertHead(list, 30);

    printf("头插后的链表：");

    listNode(list);

    /*
     * 测试尾插法
     *
     * 需要先找到当前尾节点
     *
     * 然后不断更新 tail
     */
    printf("\n========== 测试尾插法 ==========\n");

    Node *tail = get_tail(list);

    tail = insertTail(tail, 40);

    tail = insertTail(tail, 50);

    tail = insertTail(tail, 60);

    printf("尾插后的链表：");

    listNode(list);

    /*
     * 测试指定位置插入
     *
     * 在第2个位置插入15
     *
     * 原：
     *
     * 30 -> 20 -> 10 -> 40 -> 50 -> 60
     *
     * 后：
     *
     * 30 -> 15 -> 20 -> 10 -> 40 -> 50 -> 60
     */
    printf("\n========== 测试指定位置插入 ==========\n");

    if (insertNode(list, 2, 15)) {
        printf("插入成功\n");
    } else {
        printf("插入失败\n");
    }

    printf("插入后的链表：");

    listNode(list);

    /*
     * 测试删除
     *
     * 删除第3个元素
     *
     * 当前：
     *
     * 30 -> 15 -> 20 -> 10 -> 40 -> 50 -> 60
     *
     * 删除20
     *
     * 结果：
     *
     * 30 -> 15 -> 10 -> 40 -> 50 -> 60
     */
    printf("\n========== 测试删除节点 ==========\n");

    if (deleteNode(list, 3)) {
        printf("删除成功\n");
    } else {
        printf("删除失败\n");
    }

    printf("删除后的链表：");

    listNode(list);

    /*
     * 测试长度计算
     */
    printf("\n========== 测试链表长度 ==========\n");

    printf("当前链表长度：%d\n", listLength(list));

    /*
     * 测试释放链表
     */
    printf("\n========== 释放链表 ==========\n");

    freeList(list);

    printf("释放后的链表：");

    listNode(list);

    /*
     * 释放头结点
     */
    free(list);

    return 0;
}
