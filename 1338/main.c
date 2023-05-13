#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char x[50];
    scanf("%s",x);
    a=strlen(x);
    for(b=a-1; b>=0; b--)
    {
        printf("%c",x[b]);
    }

}
