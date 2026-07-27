#include "SeqList.h"
#include <stdio.h>

int
main(void) {
    printf("========== 顺序表测试开始 ==========\n\n");

    // 1. 初始化
    SeqList *list = initList();

    if (list == NULL) {
        printf("初始化失败\n");
        return 0;
    }

    printf("初始化成功，当前长度: %d\n\n", list->length);

    // 2. 添加元素
    printf("----- 测试 appendElem -----\n");

    appendElem(list, 10);
    appendElem(list, 20);
    appendElem(list, 30);
    appendElem(list, 40);

    printf("添加4个元素后:\n");
    listElem(list);

    printf("\n");

    // 3. 插入元素
    printf("----- 测试 insertElem -----\n");

    insertElem(list, 2, 99);

    printf("在第2个位置插入99后:\n");
    listElem(list);

    printf("\n");

    // 4. 查找元素
    printf("----- 测试 findElem -----\n");

    int pos = findElem(list, 30);

    if (pos) {
        printf("找到元素30，位置为: %d\n", pos);
    } else {
        printf("没有找到元素30\n");
    }

    printf("\n");

    // 5. 删除元素
    printf("----- 测试 deleteElem -----\n");

    ElemType deleted;

    deleteElem(list, 3, &deleted);

    printf("删除第3个元素，删除的是: %d\n", deleted);

    printf("删除后顺序表:\n");
    listElem(list);

    printf("\n");

    // 6. 销毁
    printf("----- 测试 destroyList -----\n");

    destroyList(list);

    printf("顺序表销毁完成\n");

    printf("\n========== 测试结束 ==========\n");

    return 0;
}