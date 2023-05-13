#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c=0;
    scanf("%d",&a);
    if(a<=1)
    {
        c=1;
    }
    else
    {
    for(b=2;b<a;b++)
    {
        if(a%b==0)
        {
            c=1;
        }
    }
    }
    if(c==0)
        {
            printf("1");
        }
    else if(c==1)
        {
            printf("0");
        }
    return 0;
}

