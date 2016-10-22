#include "target.h"
#include "stdio.h"

inline int plus(int a, int b) {
    return a + b;
}

int test_call() {
    int c = plus(1, 2);
    printf("%d", c);
}


