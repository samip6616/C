//WAP in C to find the gcd of any two numbers (Both euclidean & Extended Euclidean)
#include <stdio.h>

void euclideanAlgorithm(int a, int b) {
    printf("\nEuclidean Algorithm Steps:\n");
    printf(" a\t |  b\t |  q\t |  r\n");
    printf("---------------------------\n");

    while (b != 0) {
        int q = a / b; // Quotient
        int r = a % b; // Remainder

        // Print the current step of the Euclidean algorithm
        printf("%2d\t | %2d\t | %2d\t | %2d\n", a, b, q, r);

        // Update for next iteration
        a = b;
        b = r;
    }

    printf("GCD: %d\n", a);
}

void extendedEuclidean(int a, int b) {
    int r, q, s, t;
    int s1 = 0, s2 = 1, t1 = 1, t2 = 0;

    printf("\nExtended Euclidean Algorithm Steps:\n");
    printf(" q\t |  a\t |  b\t |  r\t |  s1\t |  s2\t |  t1\t |  t2\t\n");
    printf("-------------------------------------------------------------\n");

    while (b != 0) {
        q = a / b; // Quotient
        r = a % b; // Remainder

        // Update s and t
        s = s1 - q * s2;
        t = t1 - q * t2;

        // Print the current step of the Extended Euclidean algorithm
        printf("%2d\t | %2d\t | %2d\t | %2d\t | %3d\t | %3d\t | %3d\t | %3d\t\n",
               q, a, b, r, s1, s2, t1, t2);

        // Update for next iteration
        a = b;
        b = r;
        s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
    }

    // Final output
    printf("GCD: %d\n", a);
    printf("Coefficients: s = %d, t = %d\n", s1, t1);
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers to find GCD: ");
    scanf("%d %d", &num1, &num2);

    // Call the Euclidean algorithm
    euclideanAlgorithm(num1, num2);

    // Call the Extended Euclidean algorithm
    extendedEuclidean(num1, num2);

    return 0;
}
