#include <stdio.h>

int main() {
    int n1, n2, i, j;
    printf("Enter number of elements in Set A: ");
    scanf("%d", &n1);
    int A[n1];
    printf("Enter elements of Set A:\n");
    for(i = 0; i < n1; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter number of elements in Set B: ");
    scanf("%d", &n2);
    int B[n2];
    printf("Enter elements of Set B:\n");
    for(i = 0; i < n2; i++) {
        scanf("%d", &B[i]);
    }

    printf("Cartesian Product A x B:\n{ ");
    for(i = 0; i < n1; i++) {
        for(j = 0; j < n2; j++) {
            printf("(%d,%d)", A[i], B[j]);
            if(i != n1-1 || j != n2-1)
                printf(", ");
        }
    }
    printf(" }\n");
    return 0;
}