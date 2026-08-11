#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Child process creation initiated.....\n\n\n");
    fork();
    fork();
    //fork();
    printf("Child process created .....\n\n\n");
    printf("Child process again created.....\n\n\n");
    return 0;
}