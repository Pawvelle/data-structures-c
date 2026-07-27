#ifndef SEQLIST_H
#define SEQLIST_H

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SeqList;

// 初始化顺序表
SeqList *
initList(void);

// 添加元素
int
appendElem(SeqList *L, ElemType e);

// 输出顺序表
void
listElem(SeqList *L);

// 插入元素
int
insertElem(SeqList *L, int pos, ElemType e);

// 删除元素
int
deleteElem(SeqList *L, int pos, ElemType *e);

// 查找元素
int
findElem(SeqList *L, ElemType e);

// 销毁顺序表
void
destroyList(SeqList *L);

#endif