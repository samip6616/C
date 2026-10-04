//PDA for the language given by L={0^n1^n:n>0}
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char stack[100];
    int top = -1;
    int i, length;
    int state = 0;

    printf("Enter the string: ");
    scanf("%s", input);

    length = strlen(input);

    for (i = 0; i < length; i++)
    {
        /* State 0: Reading 0s */
        if (state == 0)
        {
            if (input[i] == '0')
            {
                /* Push X into stack */
                top++;
                stack[top] = 'X';
            }
            else if (input[i] == '1')
            {
                /* At least one 0 must be present */
                if (top == -1)
                {
                    printf("Rejected\n");
                    return 0;
                }

                /* Change to state 1 */
                state = 1;

                /* Pop X */
                top--;
            }
            else
            {
                printf("Rejected\n");
                return 0;
            }
        }

        /* State 1: Reading 1s */
        else
        {
            if (input[i] == '1')
            {
                /* Stack must not be empty */
                if (top == -1)
                {
                    printf("Rejected\n");
                    return 0;
                }

                /* Pop X */
                top--;
            }
            else
            {
                /* 0 after 1 is not allowed */
                printf("Rejected\n");
                return 0;
            }
        }
    }

    /* Accept only if stack is empty and at least one 1 was read */
    if (top == -1 && state == 1)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }

    return 0;
}