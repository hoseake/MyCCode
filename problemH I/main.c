#include <stdio.h>
#include <stdlib.h>
int main()
{
    int b,c;
    while(scanf("%d",&b)!=EOF)
    {
    int d=0;
    while(b--)
    {
       scanf("%d",&c);
       d=d+c;
    }
    printf("%d\n\n",d);
    }
    return 0;
}
