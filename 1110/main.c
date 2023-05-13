#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int j,k,l=0,m;
    char x[225],y[225];
    scanf("%s",x);
    j=strlen(x);
    for(k=j-1;k>=0;k--)
    {
        m=l++;
        y[m]=x[k];
    }
    y[l]='\0';
    if(strcmp(x,y)==0)
    {
        printf("Y");
    }
    else
    {
        printf("N");
    }
    return 0;
}
