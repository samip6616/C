#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index) {
    if (index == size) return -1; // Base case: target not found
    return (arr[index] == target) ? index : linearSearch(arr, size, target, index + 1); // Recursive call
}

int main() {
    int arr[50], size, target;

    printf("Enter the number of elements (max %d): ", 50);
    scanf("%d", &size);
    if (size < 1 || size > 50) {
        printf("Invalid size. Please enter a number between 1 and %d.\n", 50);
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target, 0);
    printf("Element %d %s at index %d.\n", target, (result != -1) ? "found" : "not found", result);
    
    return 0;
}
