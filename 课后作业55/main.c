#include <stdio.h>
#include <stdlib.h>
int main()
{
   int a,b,c,d;
   float x1,x2;
   scanf("%d %d %d",&a,&b,&c);
      d=b*b-4*a*c;
       x1=(-b+sqrt(d))/2*a;
       x2=(-b-sqrt(d))/2*a;
       printf("%.2f %.2f",x1,x2);
}
