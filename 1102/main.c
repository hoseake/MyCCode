#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b=0;
    char e[1000];
    while(scanf("%d",&a)!=EOF)
    {
        for(b;;b++)
        {
            if(a<0)
            {
                a=abs(a);
                printf("-");
            }

            e[b]=a%2;
             a=a/2;
            printf("%s",e[b]);
        }
    }
    return 0;
}
