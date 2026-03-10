//WAP in C to check whether a number is prime or not. optimal(add relatively prime or not)
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime numbers
    if (n <= 3) return 1; // 2 and 3 are prime numbers

    if (n % 2 == 0 || n % 3 == 0) return 0; // Exclude multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0; // Check divisibility
    }
    return 1; // If no factors found, it's prime
}

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // Return GCD
}

// Function to check if two numbers are relatively prime
int areRelativelyPrime(int a, int b) {
    return gcd(a, b) == 1; // They are relatively prime if GCD is 1
}

int main() {
    int number1, number2;

    // Input for prime checking
    printf("Enter a number to check if it is prime: ");
    scanf("%d", &number1);

    if (isPrime(number1)) {
        printf("%d is a prime number.\n", number1);
    } else {
        printf("%d is not a prime number.\n", number1);
    }

    // Input for relatively prime checking
    printf("Enter two numbers to check if they are relatively prime: ");
    scanf("%d %d", &number1, &number2);

    if (areRelativelyPrime(number1, number2)) {
        printf("%d and %d are relatively prime numbers.\n", number1, number2);
    } else {
        printf("%d and %d are not relatively prime numbers.\n", number1, number2);
    }

    return 0;
}
