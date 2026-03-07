#include<stdio.h>
#define F(x) (a[4]*x*x*x*x+a[3]*x*x*x+a[2]*x*x+a[1]*x+a[0])
float a[100],b[100];
int main()
{
    float x;
    int n;
    printf("Enter degree of polynomial\n");
    scanf("%d",&n);
    printf("Enter coefficients of dividend polynomial\n");
    for(int i=n;i>=0;i--)
    {
        scanf("%f",&a[i]);
    }
    printf("Enter value at which polynomial is to be evaluated\n");
    scanf("%f",&x);
    b[n]=a[n];
    while(n>0)
    {
        b[n-1]=a[n-1]+x*b[n];
        n--;
    }
    printf("Value of polynomial p(%.2f) is %.2f",x,b[0]);
}