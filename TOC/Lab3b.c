// c code for nfa to accept all the strings ending in 01
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int state[3] = {1, 0, 0};
    int newstate[3];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        newstate[0] = 0;
        newstate[1] = 0;
        newstate[2] = 0;

        /* From q0 */
        if (state[0] == 1)
        {
            if (str[i] == '0')
            {
                newstate[0] = 1;
                newstate[1] = 1;
            }
            else if (str[i] == '1')
            {
                newstate[0] = 1;
            }
        }

        /* From q1 */
        if (state[1] == 1)
        {
            if (str[i] == '1')
            {
                newstate[2] = 1;
            }
        }

        state[0] = newstate[0];
        state[1] = newstate[1];
        state[2] = newstate[2];
    }

    if (state[2] == 1)
        printf("String is ACCEPTED\n");
    else
        printf("String is NOT ACCEPTED\n");

    return 0;
}
