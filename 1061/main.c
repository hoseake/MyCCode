#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m=1;
    scanf("%d",&n);
    for(n; n>0; n--)
    {
        m=m*n;
    }
    printf("%d",m);
    return 0;
}
