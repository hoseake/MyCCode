#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(k=0;k<i*2+1;k++ )
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
