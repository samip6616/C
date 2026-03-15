//Generate 5 random numbers with pseudo random number generation formula
//Suppose your own value of X0, a,c & m [Xi+1 = (a * Xi + c) mod m]
#include <stdio.h>

int main() {
    int X0, a, c, m;
    int Xi;

    printf("Enter values for X0, a, c, and m: ");
    scanf("%d %d %d %d", &X0, &a, &c, &m);
    // X0 =  Seed value
    // a = Multiplier
    // c =  Increment
    // m = Modulus

    Xi = X0;
    printf("Pseudo-random numbers:\n");
    for (int i = 0; i < 5; i++) {
        Xi = (a * Xi + c) % m;
        printf("X%d=%d\n", i + 1, Xi);
    }

}
