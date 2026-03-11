//Write a program to implement the tautology & contradiction with your own statement expression
#include <stdio.h>

void main() {
    int p, q;
    printf("Expression for Tautology: p v ~(p ^ q)\n");
    printf("Expression for Contradiction: ~(p v q) ^ q\n");
    printf("Truth Table for Tautology and Contradiction\n");
    printf("---------------------------------------------------------\n");
    printf(" p\t|\tq\t|   Tautology\t| Contradiction\t|\n");
    printf("---------------------------------------------------------\n");

    for (p = 0; p <= 1; p++) {
        for (q = 0; q <= 1; q++) {
            int tautology = p || !(p && q);         // Tautology: p || !(p && q)
            int contradiction = !(p || q) && q;     // Contradiction: !(p || q) && q
            printf(" %d\t|\t%d\t|\t%d\t|\t%d\t|\n", p, q, tautology, contradiction);
        }
    }
}
