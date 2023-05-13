#include <stdio.h>
#include <stdlib.h>
int main()
{
   int a,b,c,d;
   float x1,x2;
   scanf("%d %d %d",&a,&b,&c);
      d=b*b-4*a*c;
      if(d>0)
      {
       x1=(-b+sqrt(d))/2*a;
       x2=(-b-sqrt(d))/2*a;
       printf("%f %f",x1,x2);
      }
      else if(d==0)
      {
          x1=(-b+sqrt(d))/2*a;
          printf("%f",x1);
      }
      else
      {
          printf("无解！");
      }
      return 0;/*已修改*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
int a,b;
char x;
while(scanf("%d%c%d",&a,&x,&b)!=EOF)
{
    switch(x)
{
    case'+' :
    printf("%d\n",a+b);
    break;
case'-' :
    printf("%d\n",a-b);
    break;
case'*' :
    printf("%d\n",a*b);
    break;
case'/' :
    printf("%d\n",a/b);
    break;
default:
    return 0;
}
}
}

