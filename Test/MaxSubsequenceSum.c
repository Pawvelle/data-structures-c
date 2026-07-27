static int
Max3(int x, int y, int z) {
    int max = x;
    if (y > max)
        max = y;
    if (z > max)
        max = z;

    return max;
}

static int
MaxSubSum(int A[], int left, int right) {
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if (left == right)
        return (A[left] > 0) ? A[left] : 0;

    else {
        Center = (left + right) / 2;
        MaxLeftSum = MaxSubSum(A, left, Center);
        MaxRightSum = MaxSubSum(A, Center + 1, right);

        MaxLeftBorderSum = LeftBorderSum = 0;
        for (int i = Center; i >= left; i--) {
            LeftBorderSum += A[i];

            if (LeftBorderSum > MaxLeftBorderSum)
                MaxLeftBorderSum = LeftBorderSum;
        }

        MaxRightBorderSum = RightBorderSum = 0;
        for (int i = Center + 1; i <= right; i++) {
            RightBorderSum += A[i];

            if (RightBorderSum > MaxRightBorderSum)
                MaxRightBorderSum = RightBorderSum;
        }

        return Max3(MaxLeftSum, MaxRightSum,
                    MaxLeftBorderSum + MaxRightBorderSum);
    }
}

int
MaxSubsequenceSum(int A[], int N) {
    return MaxSubSum(A, 0, N - 1);
}