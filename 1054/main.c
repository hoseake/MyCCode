#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j,k;
    for(j=0;j<200000;j++)
    {
        k=j*j;
        if(k%10==j||k%100==j||k%1000==j||k%10000==j)
        {
            printf("%d  ",j);
        }
    }
    return 0;
}

