//Program to check whether the given string is keyword or a valid identifier or an invalid identifier.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100

// Function to check if a string is a keyword
int isKeyword(char str[])
{
      const char *keywords[] ={"auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "inline", "int", "long", "register", "restrict", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while", NULL};
    for (int i = 0; keywords[i] != NULL; i++)
     {
        if (strcmp(str, keywords[i]) == 0)
            {
            return 1; // Keyword found
            }
    }
    return 0; // Not a keyword
}

// Function to validate a C identifier
int isValidIdentifier(char str[])
{
    int len = strlen(str);

    // Identifier must not be empty and cannot start with a digit
    if (len == 0 || isdigit(str[0]))
        {
        return 0;
        }

    // Identifier can only contain letters, digits, and underscores
    for (int i = 0; i < len; i++)
        {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
        }

    return 1;
}

int main() {
    char str[MAX_LENGTH];

    // Taking user input for identifier validation
    printf("Enter a string to check if it's a valid identifier or keyword: ");
    scanf("%s", str);

    // Check if the string is a keyword
    if (isKeyword(str))
        {
        printf("'%s' is a C keyword.\n", str);
        }
    // Check if the string is a valid identifier
    else if (isValidIdentifier(str))
    {
        printf("'%s' is a valid C identifier.\n", str);
    }
    else
        {
        printf("'%s' is not a valid C identifier or keyword.\n", str);
        }

    return 0;
}