#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,a,b;
    scanf("%d\n",&x);
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d\n",a+b);
    }
    return 0;
}
