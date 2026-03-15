//Prove that nPr=r!*nCr
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

    // Proving nPr = r! * nCr
    int nPr = permutation(n, r);
    int nCr = combination(n, r);
    int rFact = fact(r);
    
    if (nPr == rFact * nCr) {
        printf("Proved: P(%d, %d) = %d = %d! * C(%d, %d)\n", n, r, nPr, r, n, r);
    } else {
        printf("Not proved: P(%d, %d) != %d * C(%d, %d)\n", n, r, nPr, n, r);
    }
}
