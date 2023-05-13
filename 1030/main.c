#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,h,j,k;
    for(a=1;a<1000;a++)
    {
        h=a/100;
        j=a/10%10;
        k=a%10;
        if(a==h*h*h+j*j*j+k*k*k)
        {
            printf("%d ",a);
        }
    }
    return 0;
}
