#include <stdio.h>
#include<string.h>
int main()
{
    int a,b;
    char x[255];
    scanf("%s",x);
    a=strlen(x);
    for(b=a-1; b>=0; b--)
    {
        printf("%c",x[b]);
    }
    return 0;
}
