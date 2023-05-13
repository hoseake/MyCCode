#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float i;
    scanf("%f",&i);
    for(a=1;a<=3;a++)
    {
        for(b=1;b<=a;b++)
        {
            printf("%6.2f ",i);
        }
        printf("\n");
    }
    return 0;
}
