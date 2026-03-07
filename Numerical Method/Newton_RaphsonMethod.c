//C Program to Implement Newton Raphson Method
#include<stdio.h>
#include<math.h>
#define F(x) (a3*x*x*x+a2*x*x+a1*x+a0)
#define FD(x) (3*a3*x*x+2*a2*x+a1) //Derivative of F(x)
float a3,a2,a1,a0;
int main()
{
    float x0,x1,fx0,fdx0,E,Er;
    int i=0;
    printf("Enter coefficents a3,a2,a1 and a0\n");
    scanf("%f%f%f%f",&a3,&a2,&a1,&a0);
    printf("Enter initial guess and Error\n");
    scanf("%f%f",&x0,&E);
    while(1)
    {
        fx0=F(x0);
        fdx0=FD(x0);
        x1=x0-(fx0/fdx0); //Newton Raphson formula
        Er=fabs((x1-x0)/x1);
        if(Er<E)
        {
            printf("Root is %f",x1);
            break;
        }
        x0=x1;
        i++;
        if(i==50)
        break; //To avoid infinite loop in case of non-convergence
    }
    printf("\nNumber of iterations: %d",i);
}