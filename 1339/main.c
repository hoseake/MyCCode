#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    char b[100];
    scanf("%s\n%s",a,b);
    strcat(a,b);
    printf("%s",a);
    return 0;
}
