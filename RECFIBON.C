#include<stdio.h>
int rec(int);
void main()
{
int n;
printf("enter the number\n");
scanf("%d",&n);
printf("factorial of the number%d=%d",n,rec(n));
}
int rec(int x)
{
int f;
if(x==1)
return 1;
else
f=x*rec(x-1);
return f;
}
