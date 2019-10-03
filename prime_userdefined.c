 #include<stdio.h>
 int prime(int n);
 int main()
 {
     int n,p;
     printf("Enter any number");
     scanf("%d",&n);
     p=prime(n);
 }
 int prime(int n)
 {
     int i, sum=0;
     for(i=1;i<=n;i++)
     {
         if(n%i==0)
         {
             sum=sum+i;
         }
     }
     if(sum==n+1)
     {
         printf("Prime");
     }
     else
     {
         printf("Not Prime");
     }
 }
