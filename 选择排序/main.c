#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[100];
    int j,k,exchange;
    for(j=0;j<10;j++)
    {
        scanf("%d",&num[j]);
    }
    for(j=0; j<9; j++)
    {
        for(k=j+1;k<10;k++)
        {
            if(num[j]>num[k])
            {
                exchange=num[k];
                num[k]=num[j];
                num[j]=exchange;
            }
        }
    }
    for(j=0; j<10; j++)
    {
        printf("%d\n",num[j]);
    }
    return 0;
}
