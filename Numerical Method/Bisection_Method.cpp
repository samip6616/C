//Bisection Method (Without Allowed Error Concept)
#include<stdio.h>
float findValueAt(float x)
{
    return x*x*x - 2*x -5;
}

float bisect(float x1, float x2)
{
    return (x1+x2)/2;
}

int main()
{
    int maxIteration, i=1;
    float x1,x2,x;
    printf("Enter Maximun no of Iterations\n");
    scanf("%d",&maxIteration);

    do
    {
        printf("Enter the value of x1 and x2(starting boundary)");
        scanf("%f%f",&x1,&x2);
        if(findValueAt(x1)*findValueAt(x2)>0)
        {
            printf("Roots are Invalid.\n");
            continue;
        }
        else
        {
            printf("Roots lies between %f nad %f\n",x1,x2);
            break;
        }
    } while (1);
    
    while (i<=maxIteration)
    {
        x = bisect(x1,x2);
        if(findValueAt(x)*findValueAt(x1)<0)
        x2=x;
        else if(findValueAt(x)*findValueAt(x2)<0)
        x1=x;
        printf("Iterations=%d Roots=%f\n",i,x);
        i++;
    }
    printf("Root=%f Total Iterations=%d",x,--i);
    return 0;
}