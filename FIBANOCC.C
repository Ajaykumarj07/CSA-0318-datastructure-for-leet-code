#include<stdio.h>
#include<conio.h>
void main()
{
int n,i,f=0,s=1,ne;
clrscr();
printf("enter the number of series\n");
scanf("%d",&n);
printf("fibanocci series\n");
for(i=0;i<n;i++)
{
if(i<=1)
ne=i;
else
{
ne=f+s;
f=s;
s=ne;
}
printf("%d",ne);
}
getch();
}