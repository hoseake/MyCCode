#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,x;
    scanf("%d %d",&a,&b);
    int c=0;
    for(x=a;x<=b;x++)
    {
        if(x%3==1&&x%5==3)
        {
          c=c+x;
        }
    }
printf("%d",c);
    return 0;
}
