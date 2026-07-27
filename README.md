# Data Structures and Algorithms in C

Practice implementations of classic data structures and algorithms in C.

## Project layout

- `SeqList/` — array-based sequential list implementation and demonstration.
- `Test/` — standalone algorithm exercises, including binary search, maximum-subarray algorithms, and quicksort.

## Build and run

### Sequential list demo

```sh
cd SeqList
cc -std=c11 -Wall -Wextra -Werror main.c SeqList.c -o /tmp/seqlist_demo
/tmp/seqlist_demo
```

### Quicksort demo

```sh
cc -std=c11 -Wall -Wextra -Werror Test/QuickSort.c -o /tmp/quicksort_demo
/tmp/quicksort_demo
```

## Notes

Build outputs and local editor settings are excluded through `.gitignore`.
