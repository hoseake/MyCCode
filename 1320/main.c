#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sn=0,a,b=0,n,x=0;
    scanf("%d",&a);
    for(n=0; n<5; n++)
    {
        b=b*10+a;
        sn+=b;
    }
    printf("%d",sn);

}
