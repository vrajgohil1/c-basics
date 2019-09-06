#include<stdio.h>
#include<math.h>
void main()
{
    int a,b,i=0,sum=0,c,d,n;
    printf("Enter any number\n");
    scanf("%d\n",&a);
    b=a;
    while(b>0)
    {
        b=b/10;
        i++;
    }
    c=a;
    while(a>0)
    {
        d=a%10;
        sum=sum+pow(d,i);
        a=a/10;
    }
    if(c==sum)
    {
        printf("It is an armstrong number");
    }
    else
    {
        printf("It is not an armstrong number");
    }
}