#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int a,b,c,d;
    long long int e=0;
    scanf("%d",&a);
    if(a>=1&&a<=13)
    {
   for(int i=1;i<=a;i++)
    {
        d=1;
        b=1;
        c=a;
        for(int j=1;j<=i;j++)
        {
            b=b*c;
            c--;
         }
333666666666666666666666666666666666666666         for(int k=1;k<=i;k++)

   {
       b=b/k;
   }
   b=b*pow(4,i);
       e=e+b;
    }
    printf("%lld",e+1);
    }
    return 0;

}
