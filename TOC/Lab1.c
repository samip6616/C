//program to find the prefixes,suffixes and substring from the given string
#include <stdio.h>
#include <string.h>

// Function to print all prefixes of a string
void printPrefixes(char *str) {
    int len = strlen(str);
    printf("Prefixes:\n");
    for (int i = 1; i <= len; i++) {
        // Print the prefix of length i
        for (int j = 0; j < i; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

// Function to print all suffixes of a string
void printSuffixes(char *str) {
    int len = strlen(str);
    printf("\nSuffixes:\n");
    for (int i = 0; i < len; i++) {
        // Print the suffix starting from index i
        for (int j = i; j < len; j++) {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}

// Function to print all substrings of a string
void printSubstrings(char *str) {
    int len = strlen(str);
    printf("\nSubstrings:\n");
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            // Print the substring starting from i and ending at j-1
            for (int k = i; k < j; k++) {
                printf("%c", str[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Print prefixes, suffixes, and substrings
    printPrefixes(str);
    printSuffixes(str);
    printSubstrings(str);

    return 0;
}
