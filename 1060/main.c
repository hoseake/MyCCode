#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    double t=0;
    for(n;n>=1;n--)
    {
        t+=1.0/n;
    }
    printf("%.6f",t);
    return 0;
}
