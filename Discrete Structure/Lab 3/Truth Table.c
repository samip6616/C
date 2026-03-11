//WAP to implement conjunction, disjunction, implication, bi-conditional in truth table
#include <stdio.h>
void main() {
    int a, b;
    printf("Enter two integers(0 or 1): ");
    scanf("%d %d", &a, &b);
    printf("Conjunction (^): %d\n", a && b);
    printf("Disjunction (v): %d\n", a || b);
    printf("Implication (A -> B): %d\n", !a || b);
    printf("Bi-conditional (A <-> B): %d\n", (a && b) || (!a && !b));
    printf("\nTruth Table:\n");
    printf("p\t| q | p ^ q | p v q | p -> q | p <-> q |\n");
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
        printf("%d\t| %d |   %d   |   %d   |   %d    |   %d     |\n", i, j, i && j, i || j, !i || j, (i && j) || (!i && !j));
        }
    }
}
