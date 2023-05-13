#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,i,n;
    while(scanf("%d",&n)!=EOF)
    {
        int b=0;
        for(i=2; i<=n; i++)
        {
            int c=0;
            for(a=2; a<i; a++)
            {
                if(i%a==0)
                {
                    c=1;
                }
            }
            if(c==0)
            {
                b++;
            }
        }
        printf("%d\n",b);
    }
    return 0;
}
