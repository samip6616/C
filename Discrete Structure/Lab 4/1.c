//Implement Recursive algorithm for finding fibonacci number series
#include <stdio.h>
int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Fibonacci series up to %d: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
}
