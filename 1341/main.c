#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y,a,b,c,d;
    scanf("%d",&y);
    a=y/1000;
    b=y/100%10;
    c=y/10%10;
    d=y%10;
    printf("%d %d %d %d",a,b,c,d);

}
