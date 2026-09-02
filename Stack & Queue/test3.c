#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Stack {
    ElemType data;
    struct Stack *next;
} Stack;

Stack *
initStack() {
    Stack *s = malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;

    return s;
}

int
isEmpty(Stack *s) {
    if (s->next == NULL) {
        printf("空的\n");
        return 1;
    }

    return 0;
}

int
push(Stack *s, ElemType e) {
    Stack *p = malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;

    return 1;
}

int
pop(Stack *s, ElemType *e) {
    if (s->next == NULL) {
        printf("空的\n");
        return 0;
    }

    Stack *p = s->next;
    *e = p->data;

    s->next = p->next;
    free(p);

    return 1;
}

int
getTop(Stack *s, ElemType *e) {
    if (s->next == NULL) {
        printf("空的\n");
        return 0;
    }

    *e = s->next->data;
    return 1;
}

int
main(void) {
    Stack *s = initStack();
    push(s, 10);
    push(s, 20);
    push(s, 30);
    ElemType e;
    pop(s, &e);
    printf("%d\n", e);
    getTop(s, &e);
    printf("%d\n", e);

    return 0;
}