#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,p,j;
    scanf("%d",&n);
    for(m=2; m<=n; m++)
    {
        j=0;
        for(p=1; p<m; p++)
        {
            if(m%p==0)
            {
                j=j+p;
            }
        }
        if(m==j)
        {
            printf("%d its factors are ",m);
            for(p=1; p<m; p++)
            {
                if(m%p==0)
                {
                    printf("%d ",p);
                }
            }
            printf("\n");
        }


    }
    return 0;
}
