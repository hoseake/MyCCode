#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i=0,j,b;
    char a[100];
    scanf("%s",a);
    for(j=0; a[j]!='\0'; j++)
    {
        if((a[j]>=65&&a[j]<=90)||(a[j]>=97&&a[j]<=122))
        {
            i++;
        }
    }
    printf("%d",i);
    return 0;
}
