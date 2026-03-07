#include<stdio.h>
#include<math.h>
#define EPSILON 0.001

float f(float x)
{
    return x*x*x - x*x -1;
}

float findvalueAt(float x)
{
    return 1/sqrt(1+x);
}
float differentiate(float x)
{
    return -0.5 * pow(1 + x, -1.5);
}

int main()
{
    int maxIteration,i;
    float a,b,x,x0;
    printf("Enter Maximum no of Iterations\n");
    scanf("%d",&maxIteration);

    do
    {
        printf("Enter the value of a and b(starting bounary) ");
        scanf("%f%f",&a,&b);
        if(f(a)*f(b)>0)
        {
            printf("Bounary Values are Invalid\n");
            continue;
        }
        else
        {
            printf("Roots lies between %f and %f\n",a,b);
            break;
        }
    }while(1);

    x0= (a+b)/2;
    if(fabs(differentiate(x0))<1)
        printf("Function Form is Correct. Iteration Method can be applied.\n");
        else
        {
            printf("Function Form is Incorrect. Iteration Method CAN'T be applied.\n");
            return 0;
        }

    for(i=1;i<=maxIteration;i++)
    {
        x = findvalueAt(x0);

        if(fabs(x-x0)<EPSILON)
        {
            printf("Iterations=%d   Final Root=%f\n",i,x);
            return 0;
        }
        printf("Iterations=%d   Root=%f\n",i,x);
        x0=x;
        }
    printf("Root=%f Total Iterations=%d",x,--i);
    return 0;
}