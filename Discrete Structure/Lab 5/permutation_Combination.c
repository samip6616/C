//Implementation of permutation and combination in C
#include <stdio.h>
int fact(int n) { 
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}
int permutation(int n, int r) {
    return fact(n) / fact(n - r);
}

int combination(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

void main() {
    int n, r;
    printf("Enter values for n and r: ");
    scanf("%d %d", &n, &r);
    printf("Permutation P(%d, %d) = %d\n", n, r, permutation(n, r));
    printf("Combination C(%d, %d) = %d\n", n, r, combination(n, r));
}
