#include<stdio.h>
#include<conio.h>
void main()
{
int n,a;
int f=1;
clrscr();
printf("enter a number:\n");
scanf("%d",&n);
for(a=1;a<=n;a++)
{
f=f*a;
}
printf("factorial of the number%d=%d\n",n,f);
getch();
}