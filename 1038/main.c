#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,i;
    scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a>b)
        i=a,a=b,b=i;
        if(a>c)
            i=a,a=c,c=i;
        if(a>d)
            i=a,a=d,d=i;
    if(b>c)
        i=b,b=c,c=i;
        if(b>d)
            i=b,b=d,d=i;
    if(c>d)
        i=c,c=d,d=i;
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}
