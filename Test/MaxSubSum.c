static int
Max2(int x, int y) {
    return (x > y) ? x : y;
}

int
MaxSubSum(int A[], int N) {
    int max, dp;
    max = dp = A[0];

    for (int i = 1; i < N; i++) {
        dp = Max2(A[i], dp + A[i]);
        max = Max2(max, dp);
    }

    return max;
}