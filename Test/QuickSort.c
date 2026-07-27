#include <stdio.h>

static void
Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* 三数取中法：取左、中、右三个元素的中位数作为枢纽元 */
static int
Median3(int A[], int left, int right) {
    int center = (left + right) / 2;

    if (A[left] > A[center])
        Swap(&A[left], &A[center]);
    if (A[left] > A[right])
        Swap(&A[left], &A[right]);
    if (A[center] > A[right])
        Swap(&A[center], &A[right]);

    /* 将枢纽元放到 right - 1 处 */
    Swap(&A[center], &A[right - 1]);
    return A[right - 1];
}

#define CUTOFF (3)

static void
InsertionSort(int A[], int N) {
    int i, j;
    int tmp;

    for (i = 1; i < N; i++) {
        tmp = A[i];
        for (j = i; j > 0 && A[j - 1] > tmp; j--)
            A[j] = A[j - 1];
        A[j] = tmp;
    }
}

static void
QSort(int A[], int left, int right) {
    int i, j;
    int pivot;

    if (left + CUTOFF <= right) {
        pivot = Median3(A, left, right);
        i = left;
        j = right - 1;

        for (;;) {
            while (A[++i] < pivot) {
            }
            while (A[--j] > pivot) {
            }
            if (i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }

        Swap(&A[i], &A[right - 1]); /* 将枢纽元放回正确位置 */
        QSort(A, left, i - 1);
        QSort(A, i + 1, right);
    } else {
        /* 对小数组使用插入排序 */
        InsertionSort(A + left, right - left + 1);
    }
}

void
QuickSort(int A[], int N) {
    QSort(A, 0, N - 1);
}

static void
PrintArray(int A[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    putchar('\n');
}

int
main(void) {
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int N = sizeof(A) / sizeof(A[0]);

    printf("排序前: ");
    PrintArray(A, N);

    QuickSort(A, N);

    printf("排序后: ");
    PrintArray(A, N);

    return 0;
}
