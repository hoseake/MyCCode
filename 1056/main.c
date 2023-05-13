#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a=1.0,b=0;
    int c;
    for(c=2;c<=64;c++)
    {
        a=a*2;
        b=b+a;
    }
    printf("%.0lf",b);
    return 0;
}
