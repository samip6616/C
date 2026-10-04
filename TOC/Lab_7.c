//Program to implement Turing Machine for the language L={0^n1^n:n>0}
#include <stdio.h>
#include <string.h>

int main()
{
    char tape[100];
    int head = 0;
    int i;

    printf("Enter the string: ");
    scanf("%s", tape);

    int length = strlen(tape);

    while (1)
    {
        /* Move head to the left end */
        head = 0;

        /* Find an unmarked 0 */
        while (head < length && tape[head] != '0')
        {
            head++;
        }

        /* If no 0 is left, check whether all 1s are marked */
        if (head == length)
        {
            for (i = 0; i < length; i++)
            {
                if (tape[i] == '1')
                {
                    printf("Rejected\n");
                    return 0;
                }
            }

            printf("Accepted\n");
            return 0;
        }

        /* Mark 0 as X */
        tape[head] = 'X';

        /* Move right to find an unmarked 1 */
        head++;

        while (head < length && tape[head] != '1')
        {
            head++;
        }

        /* No matching 1 found */
        if (head == length)
        {
            printf("Rejected\n");
            return 0;
        }

        /* Mark 1 as Y */
        tape[head] = 'Y';
    }
}