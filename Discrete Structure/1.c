#include <stdio.h>

int readSet(int set[]) {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    return n;
}

void printSet(int set[], int n) {
    int i;
    printf("{ ");
    for (i = 0; i < n; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

int isMember(int set[], int n, int elem) {
    int i;
    for (i = 0; i < n; i++) {
        if (set[i] == elem)
            return 1;
    }
    return 0;
}

int setUnion(int set1[], int n1, int set2[], int n2, int result[]) {
    int i, k = 0;
    for (i = 0; i < n1; i++)
        result[k++] = set1[i];
    for (i = 0; i < n2; i++) {
        if (!isMember(set1, n1, set2[i]))
            result[k++] = set2[i];
    }
    return k;
}

int setIntersection(int set1[], int n1, int set2[], int n2, int result[]) {
    int i, k = 0;
    for (i = 0; i < n1; i++) {
        if (isMember(set2, n2, set1[i]))
            result[k++] = set1[i];
    }
    return k;
}

int setDifference(int set1[], int n1, int set2[], int n2, int result[]) {
    int i, k = 0;
    for (i = 0; i < n1; i++) {
        if (!isMember(set2, n2, set1[i]))
            result[k++] = set1[i];
    }
    return k;
}

int main() {
    int set1[100], set2[100], result[100];
    int n1, n2, nResult, choice;

    printf("Enter Set 1:\n");
    n1 = readSet(set1);

    printf("Enter Set 2:\n");
    n2 = readSet(set2);

    printf("\nSet 1: ");
    printSet(set1, n1);
    printf("Set 2: ");
    printSet(set2, n2);

            nResult = setUnion(set1, n1, set2, n2, result);
            printf("Union: ");
            printSet(result, nResult);
            nResult = setIntersection(set1, n1, set2, n2, result);
            printf("Intersection: ");
            printSet(result, nResult);
            nResult = setDifference(set1, n1, set2, n2, result);
            printf("Difference (Set1 - Set2): ");
            printSet(result, nResult);
    return 0;
}