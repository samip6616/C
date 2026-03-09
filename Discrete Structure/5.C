#include <stdio.h>

#define MAX 100

void inputSet(float set[], int *n, const char *name) {
    printf("Enter number of elements in %s: ", name);
    scanf("%d", n);
    printf("Enter membership values for %s (between 0 and 1):\n", name);
    for (int i = 0; i < *n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &set[i]);
        if (set[i] < 0 || set[i] > 1) {
            printf("Invalid membership value. Enter again: ");
            i--;
        }
    }
}

void printSet(float set[], int n, const char *name) {
    printf("%s = { ", name);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", set[i]);
    }
    printf("}\n");
}

void fuzzyUnion(float a[], float b[], float result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = (a[i] > b[i]) ? a[i] : b[i];
    }
}

void fuzzyIntersection(float a[], float b[], float result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = (a[i] < b[i]) ? a[i] : b[i];
    }
}

void fuzzyComplement(float a[], float result[], int n) {
    for (int i = 0; i < n; i++) {
        result[i] = 1 - a[i];
    }
}

int main() {
    float setA[MAX], setB[MAX], unionSet[MAX], intersectionSet[MAX], complementA[MAX];
    int n;

    inputSet(setA, &n, "Set A");
    inputSet(setB, &n, "Set B");

    fuzzyUnion(setA, setB, unionSet, n);
    fuzzyIntersection(setA, setB, intersectionSet, n);
    fuzzyComplement(setA, complementA, n);

    printSet(setA, n, "A");
    printSet(setB, n, "B");
    printSet(unionSet, n, "A U B");
    printSet(intersectionSet, n, "A ∩ B");
    printSet(complementA, n, "A'");

    return 0;
}