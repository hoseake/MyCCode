#include <stdio.h>
#include <stdlib.h>
//ɳ©
int main()
{
    int n,i,j,k,l,m,p,q,r,s,t,u,v,w,x,y,z,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(l=1;l<=n-1;l++)
    {
        for(m=1;m<=l;m++)
        {
            printf(" ");
        }
        for(p=1;p<=n-l;p++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(q=1;q<=n;q++)
    {
        for(r=1;r<=n-q;r++)
        {
            printf(" ");
        }
        for(s=1;s<=q;s++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(t=1;t<=n-1;t++)
    {
        for(u=1;u<=t;u++)
        {
            printf(" ");
        }
        for(v=1;v<=n-t;v++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(w=1;w<=n;w++)
    {
        for(x=1;x<=n-w;x++)
        {
            printf(" ");
        }
        for(y=1;y<=w;y++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(z=1;z<=n-1;z++)
    {
        for(a=1;a<=z;a++)
        {
            printf(" ");
        }
        for(b=1;b<=n-z;b++)
        {
            printf("*");
        }
        printf("\n");
    }
}
