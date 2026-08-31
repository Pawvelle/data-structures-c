#include <stdio.h>

int
isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void
printPrime(int num) {
    for (int i = 2; i < num + 1; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }

    printf("\n");
}

int
main(void) {
    printPrime(100);

    return 0;
}
