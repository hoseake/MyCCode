#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,x,j=0,k=0;
    float l=0;
    scanf("%d %d %d",&a,&b,&c);
    for(x=1;x<=a;x++)
    {
        j+=x;
    }
    for(x=1;x<=b;x++)
    {
        k+=x*x;
    }
    for(x=1;x<=c;x++)
    {
        l+=1.0/x;
    }
    printf("%.2f",j+k+l);
    return 0;
}
