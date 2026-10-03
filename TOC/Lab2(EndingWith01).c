//dfa to accept all the strings ending in 01
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int state = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        if (state == 0)
        {
            if (str[i] == '0')
                state = 1;
            else
                state = 0;
        }

        else if (state == 1)
        {
            if (str[i] == '0')
                state = 1;
            else
                state = 2;
        }

        else if (state == 2)
        {
            if (str[i] == '0')
                state = 1;
            else
                state = 0;
        }
    }

    if (state == 2)
        printf("String is ACCEPTED\n");
    else
        printf("String is NOT ACCEPTED\n");

    return 0;
}
