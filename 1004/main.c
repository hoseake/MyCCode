#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,n,s=0,b=0;
    scanf("%d %d",&a,&n);
    for(n;n>=1;n--)
    {
        b=b*10+a;
        s=s+b;
    }
   printf("%d",s);
}
