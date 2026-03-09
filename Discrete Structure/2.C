#include <stdio.h>

int floorValue(float num) {
    int intPart = (int)num;
    if (num >= 0 || num == (float)intPart)
        return intPart;
    else
        return intPart - 1;
}

int ceilingValue(float num) {
    int intPart = (int)num;
    if (num == (float)intPart)
        return intPart;
    else if (num > 0)
        return intPart + 1;
    else
        return intPart;
}

int main() {
    float num;
    printf("Enter a number: ");
    scanf("%f", &num);

    printf("Floor value: %d\n", floorValue(num));
    printf("Ceiling value: %d\n", ceilingValue(num));

    return 0;
}