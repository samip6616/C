#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int n;
void *computeSum(void *arg)
{
    long *sum = malloc(sizeof(long));
    *sum = 0;
    for (int i = 1; i <= n; i++)
    {
        *sum += i;
    }
    return sum;
}
int main()
{
    pthread_t tid;
    long *result;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    if (pthread_create(&tid, NULL, computeSum, NULL) != 0)
    {
        printf("Thread creation failed\n");
        return 1;
    }
    pthread_join(tid, (void **)&result);
    printf("Sum from 1 to %d = %ld\n", n, *result);
    free(result);
    return 0;
}