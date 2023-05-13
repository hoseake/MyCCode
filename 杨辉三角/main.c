#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
    int a[50][20],i,j,k;
    for(i=0; i<N; i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2; i<N; i++)
    {
        for(j=1; j<i; j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    for(i=0; i<N; i++)
    {
       for(k=1; k<N-i; k++)
       {
           printf("  ");
        }
        for(j=0; j<=i; j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    }
    return 0;
}
