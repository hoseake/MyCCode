#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m,h=0.0;
    int n;
    scanf("%f %d",&m,&n);
    for(n;n>0;n--)
    {
        h=h+1.5*m;
        m=m/2.0;
    }
     h=h-m;
    printf("%.2f %.2f",m,h);
    return 0;
}
