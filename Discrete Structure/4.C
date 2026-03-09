#include <stdio.h>

int mod_add(int a, int b, int m) {
    return (a + b) % m;
}

int mod_sub(int a, int b, int m) {
    return ((a - b) % m + m) % m;
}

int mod_mul(int a, int b, int m) {
    return (a * b) % m;
}

int mod_pow(int base, int exp, int m) {
    int result = 1;
    base = base % m;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % m;
        exp = exp / 2;
        base = (base * base) % m;
    }
    return result;
}

int main() {
    int a, b, m;
    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);
    printf("Enter modulus (m): ");
    scanf("%d", &m);

    printf("Modular Addition: (%d + %d) mod %d = %d\n", a, b, m, mod_add(a, b, m));
    printf("Modular Subtraction: (%d - %d) mod %d = %d\n", a, b, m, mod_sub(a, b, m));
    printf("Modular Multiplication: (%d * %d) mod %d = %d\n", a, b, m, mod_mul(a, b, m));
    printf("Modular Exponentiation: (%d ^ %d) mod %d = %d\n", a, b, m, mod_pow(a, b, m));

    return 0;
}