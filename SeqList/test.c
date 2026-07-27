#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SeqList;

// 初始化顺序表
SeqList *
initList(void) {
    SeqList *L = (SeqList *)malloc(sizeof(SeqList));

    if (L == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }

    L->data = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);

    if (L->data == NULL) {
        printf("内存分配失败\n");
        free(L);
        return NULL;
    }

    L->length = 0;

    return L;
}

// 添加元素
int
appendElem(SeqList *L, ElemType e) {
    if (L->length >= MAXSIZE) {
        printf("顺序表已满\n");
        return 0;
    }

    L->data[L->length] = e;
    L->length++;

    return 1;
}

// 输出顺序表
void
listElem(SeqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }

    printf("\n");
}

// 插入元素
int
insertElem(SeqList *L, int pos, ElemType e) {
    if (pos < 1 || pos > L->length + 1) {
        printf("插入位置错误\n");
        return 0;
    }

    for (int i = L->length - 1; i >= pos - 1; i--) {
        L->data[i + 1] = L->data[i];
    }

    L->data[pos - 1] = e;
    L->length++;

    return 1;
}

// 删除元素
int
deleteElem(SeqList *L, int pos, ElemType *e) {
    if (pos < 1 || pos > L->length) {
        printf("删除位置错误\n");
        return 0;
    }

    *e = L->data[pos - 1];

    for (int i = pos; i < L->length; i++) {
        L->data[i - 1] = L->data[i];
    }

    L->length--;

    return 1;
}

// 查找元素
int
findElem(SeqList *L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }

    return 0;
}

// 销毁顺序表
void
destroyList(SeqList *L) {
    if (L == NULL) {
        return;
    }

    free(L->data);
    free(L);
}

int
main(void) {
    printf("========== 顺序表测试开始 ==========\n\n");

    SeqList *list = initList();

    if (list == NULL) {
        return 0;
    }

    printf("初始化成功，当前长度: %d\n\n", list->length);

    printf("----- 测试 appendElem -----\n");

    appendElem(list, 10);
    appendElem(list, 20);
    appendElem(list, 30);
    appendElem(list, 40);

    listElem(list);

    printf("\n----- 测试 insertElem -----\n");

    insertElem(list, 2, 99);

    listElem(list);

    printf("\n----- 测试 findElem -----\n");

    int pos = findElem(list, 30);

    printf("30的位置: %d\n", pos);

    printf("\n----- 测试 deleteElem -----\n");

    ElemType deleted;

    deleteElem(list, 3, &deleted);

    printf("删除元素: %d\n", deleted);

    listElem(list);

    printf("\n----- 测试 destroyList -----\n");

    destroyList(list);

    printf("顺序表销毁完成\n");

    printf("\n========== 测试结束 ==========\n");

    return 0;
}