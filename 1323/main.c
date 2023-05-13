#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,z,a;
    for(x=100;x<1000;x++)
    {
        y=x/100;
        z=x%10;
        a=x/10%10;
        if(x==y*y*y+z*z*z+a*a*a)
        {
            printf("%d\n",x);
        }
    }
    return 0;
}
