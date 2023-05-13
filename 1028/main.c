#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,j,k,l;
    char n[1000];
    while(scanf("%s",&n)!=EOF)
    {
        t=0;
        j=strlen(n);
        for(k=0; k<j; k++)
        {
            t+=(n[k]-'0');
        }
        printf("%d\n",t);
    }

    return 0;
}
