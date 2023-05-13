#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,j,k,l;
    scanf("%d",&n);
    for(j=2;j<=n;j++)
    {
        l=0;
        for(k=2;k<j;k++)
        {
            if(j%k==0)
            l=1;
        }
        if(l==0)
            printf("%d\n",j);
    }
    return 0;
}
